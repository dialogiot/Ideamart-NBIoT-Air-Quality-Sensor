
void DataPush(){ 
  
  mics.readSensor();  
  float t= bme.readTemp();
  float p= bme.readPressure();
  float a= bme.readAltitude();
  float h= bme.readHumidity();
  float nh3   =gas.measure_NH3();   
  float h2    =gas.measure_H2(); 
  float c2h5oh=gas.measure_C2H5OH(); 
  float co2   =mics.getCO2();
  float co    =gas.measure_CO(); 
  float no2   =gas.measure_NO2(); 
  float c3h8  =gas.measure_C3H8(); 
  float c4h10 =gas.measure_C4H10();
  float ch4   =gas.measure_CH4(); 
  int sig     =modem.getSignalQuality();
  int bat     =modem.getBattPercent();
  float voc   =mics.getVOC();
  
  String csv = "data,"+ String(ID)+"," + String(t)+","+String(p)+","+String(a)+","+String(h)+","+String(nh3)+","+String(co)+","+String(no2)+","+String(c3h8)+","+String(c4h10)+","+String(ch4)+","+String(h2)+","+String(c2h5oh)+","+String(co2)+","+String(voc)+","+String(sig)+","+String(bat);

  //String csv1 = "{\"eventName\":\"data1\",\"status\":\"none\",\"t\":"+String(t)+",\"p\":"+String(p)+",\"a\":"+String(a)+",\"h\":"+String(h)+",\"nh\":"+String(nh3)+",\"h2\":"+String(h2)+",\"c2\":"+String(c2h5oh)+",\"co2\":"+String(co2)+",\"mac\":\""+ID+"\"}";
  mqtt.publish(PUB_TOPIC,csv.c_str());
  Serial.println(csv);
}


void gpsPush(){
  float lat,lon;
  if(modem.enableGPS()){
  Serial.print("Locating");

  int count = 0;
  while(!modem.getGPS(&lat,&lon)){
    count++;
     Serial.print(F("."));
     if(count == 300){  // retry attempts for gps
      Serial.println(F("GPS failed..Check antenna"));  // if gps error,check gps antenna 
      break;
     }
  }
  if(count < 300){
      Serial.println();
      Serial.print(F("GPS Location: "));
      Serial.println(String(lat)+","+String(lon));

      mqtt.publish(PUB_TOPIC,("gps," + String(ID) + "," + modem.getGPSraw()).c_str());
  }
      modem.disableGPS();
  }
  else(F("GPS failed.."));
}

void other(){
  
}


