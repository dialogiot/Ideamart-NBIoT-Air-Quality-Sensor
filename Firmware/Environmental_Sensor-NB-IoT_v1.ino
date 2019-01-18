#define TINY_GSM_MODEM_SIM808
#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

#include <Wire.h>
#include "MutichannelGasSensor.h"
#include <BME280.h>
#include <Adafruit_NeoPixel.h>  
#include "MICS-VZ-89TE.h"

//ideaBoard pin configuration
#define ideaBoard_PWRKEY 13
#define ideaBoard_RX      8
#define ideaBoard_TX      7
#define ideaBoard_RST    11

#define PIN              A2      // LED on analog pin 2
#define NUMLEDS           1      // Use total of 1 LED

MICS_VZ_89TE mics;
BME280 bme;
Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

SoftwareSerial SerialAT(7,8); // RX, TX

TinyGsm modem(SerialAT);
TinyGsmClient client(modem);
PubSubClient mqtt(client);

unsigned long pr = 0;        // will store last time published
const long interval = 50000;           // interval at which to publish data (milliseconds)
#define gps 2   // 0 - disable, 1- send periodically, 2 - send only at powerup/reset

//Dialog IoT params
#define ID "env123"
#define PUB_TOPIC "ideamart/environmentalsensor/v3/common"


void setup() {
  pinMode(ideaBoard_RST, OUTPUT);
  digitalWrite(ideaBoard_RST, LOW);

  pinMode(ideaBoard_PWRKEY, OUTPUT);
  //digitalWrite(ideaBoard_PWRKEY, LOW);
  //delay(200);

  digitalWrite(ideaBoard_PWRKEY, HIGH);
  //delay(180);
  //digitalWrite(ideaBoard_PWRKEY, LOW);
    
  Serial.begin(115200);
  bme.begin();
  mics.begin();
  gas.begin(0x04);//the default I2C address of the slave is 0x04
  gas.powerOn();
  
  SerialAT.begin(4800);
  leds.begin();  
  leds.setPixelColor(0, leds.Color(50, 0, 0));
  leds.show();                      
  delay(500);

  Serial.print(F("Network  : "));
  if (!modem.waitForNetwork()) {
    Serial.println(F(" fail"));
    while (true);
  }
  Serial.println(F(" OK"));
  Serial.print(F("GPRS     : "));
  if (!modem.gprsConnect("dialogbb", "", "")) {
    Serial.println(F(" fail"));
    while (true);
    rgb(3,1,0,0);

  }
  Serial.println(F(" OK"));
  // MQTT Broker setup
  mqtt.setServer("mqtt.iot.ideamart.io", 1883);
  if(gps == 2){
  mCon();
  gpsPush();}
//
//  Serial.println(modem.getSimCCID());
//    Serial.println(modem.getIMEI());
//      Serial.println(modem.getOperator());
//        Serial.println(modem.localIP());
}

void loop() {

    unsigned long cr = millis();

  if (cr - pr >= interval) {
    pr = cr;

  if (mCon()) {    
    DataPush();
    if(gps == 1){
      gpsPush();
    }
    rgb(3,5,1,0);
    rgb(3,5,1,0);
  }
 mqtt.disconnect();
  } 
  rgb(5,0,1,0);
}


boolean mCon() {
  Serial.print(F("MQTT     : "));
  randomSeed(analogRead(5)); //analog pin 5 used to generate random number
  
  if (!mqtt.connect("ENV-3210","ideamart-environmentalsensor-v3_1777","1544415787_1777")) {
    Serial.println(F(" fail"));
    return false;
  }
  Serial.println(F(" OK"));
  return mqtt.connected();
}

void rgb(int wait,int r, int g, int b){
  for(int i=0; i<255; i++) {            // Loop through next color change
    leds.setPixelColor(0, leds.Color(r*i, g*i, b*i)); 
    leds.show(); 
    delay(wait); 
  }
  for(int i=255; i>=0; i--) {            // Count up color units from 0 to 255
    leds.setPixelColor(0, leds.Color(r*i, g*i, b*i));  // Color mix for LED
    leds.show();                        // Set the LED
    delay(wait);                        // Delay for visual effect
  }
  
}

