package lk.dialog.iot.das.operation.process.plugin.ideamart.envsensor.v1;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.google.gson.Gson;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import jdk.nashorn.internal.parser.JSONParser;
import lk.dialog.iot.das.exception.PluginServiceException;
import lk.dialog.iot.das.operation.dto.EventDto;
import lk.dialog.iot.das.operation.dto.EventParametersDto;
import lk.dialog.iot.das.operation.process.plugin.PluginService;
import lk.dialog.iot.das.util.Constants;
import lk.dialog.iot.das.util.EnumTypes;
import lk.dialog.iot.das.util.JsonConverter;
import lk.dialog.iot.das.util.PluginSequence;
import net.minidev.json.JSONObject;
import ro.fortsoft.pf4j.Extension;
import ro.fortsoft.pf4j.Plugin;
import ro.fortsoft.pf4j.PluginWrapper;

import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import com.opencsv.CSVReader;

import java.io.FileReader;
import java.io.IOException;


import static lk.dialog.iot.das.util.Constants.ACTION_PARAMETERS_KEY;

public class IdeamartEnvsensorV1Plugin extends Plugin {
    public IdeamartEnvsensorV1Plugin(PluginWrapper wrapper) {
        super(wrapper);
    }

    @Extension
    public static class envsensor_v1 implements PluginService {
        @Override
        public String toString() {
            return "envsensor_v1";
        }

        public Map<String, ?> pluginOperation(Map<String, Object> receivedMap) throws PluginServiceException {

            Map<String, Object> responseMap = null;

            String operation = (String) receivedMap.get(Constants.OPERATION_KEY);
            if (operation.equals(EnumTypes.OperationTypes.EVENT_OPERATION.getName())) {


                String message = (String) receivedMap.get("messageBody");
                String[] line = message.split(",");

                   List<EventDto> eventDtoList = new ArrayList<EventDto>();
                   EventDto eventDto = new EventDto();

                if(line[0].equals("data")) {

                    eventDto.setEventName(line[0]);
                    eventDto.setStateName("none");

                    EventParametersDto eventParametersDto0 = new EventParametersDto();
                    eventParametersDto0.setName("Temperature(Celsius)");
                    eventParametersDto0.setType("Double");
                    eventParametersDto0.setValue(line[2]);
                    eventDto.getEventParameters().add(eventParametersDto0);

                    EventParametersDto eventParametersDto1 = new EventParametersDto();
                    eventParametersDto1.setName("Pressure(Pa)");
                    eventParametersDto1.setType("Double");
                    eventParametersDto1.setValue(line[3]);
                    eventDto.getEventParameters().add(eventParametersDto1);

                    EventParametersDto eventParametersDto2 = new EventParametersDto();
                    eventParametersDto2.setName("Altitude(m)");
                    eventParametersDto2.setType("Double");
                    eventParametersDto2.setValue(line[4]);
                    eventDto.getEventParameters().add(eventParametersDto2);

                    EventParametersDto eventParametersDto3 = new EventParametersDto();
                    eventParametersDto3.setName("Humidity(%)");
                    eventParametersDto3.setType("Double");
                    eventParametersDto3.setValue(line[5]);
                    eventDto.getEventParameters().add(eventParametersDto3);


                    EventParametersDto eventParametersDto4 = new EventParametersDto();
                    eventParametersDto4.setName("Ammonia(ppm)");
                    eventParametersDto4.setType("Double");
                    eventParametersDto4.setValue(line[6]);
                    eventDto.getEventParameters().add(eventParametersDto4);

                    EventParametersDto eventParametersDto5 = new EventParametersDto();
                    eventParametersDto5.setName("Carbon Monoxide(ppm)");
                    eventParametersDto5.setType("Double");
                    eventParametersDto5.setValue(line[7]);
                    eventDto.getEventParameters().add(eventParametersDto5);

                    EventParametersDto eventParametersDto6 = new EventParametersDto();
                    eventParametersDto6.setName("Nitrogen Dioxide(ppm)");
                    eventParametersDto6.setType("Double");
                    eventParametersDto6.setValue(line[8]);
                    eventDto.getEventParameters().add(eventParametersDto6);

                    EventParametersDto eventParametersDto7 = new EventParametersDto();
                    eventParametersDto7.setName("Propane(ppm)");
                    eventParametersDto7.setType("Double");
                    eventParametersDto7.setValue(line[9]);
                    eventDto.getEventParameters().add(eventParametersDto7);


                    EventParametersDto eventParametersDto8 = new EventParametersDto();
                    eventParametersDto8.setName("Butane(ppm)");
                    eventParametersDto8.setType("Double");
                    eventParametersDto8.setValue(line[10]);
                    eventDto.getEventParameters().add(eventParametersDto8);

                    EventParametersDto eventParametersDto9 = new EventParametersDto();
                    eventParametersDto9.setName("Methane(ppm)");
                    eventParametersDto9.setType("Double");
                    eventParametersDto9.setValue(line[11]);
                    eventDto.getEventParameters().add(eventParametersDto9);

                    EventParametersDto eventParametersDto10 = new EventParametersDto();
                    eventParametersDto10.setName("Hydrogen(ppm)");
                    eventParametersDto10.setType("Double");
                    eventParametersDto10.setValue(line[12]);
                    eventDto.getEventParameters().add(eventParametersDto10);

                    EventParametersDto eventParametersDto11 = new EventParametersDto();
                    eventParametersDto11.setName("Ethanol(ppm)");
                    eventParametersDto11.setType("Double");
                    eventParametersDto11.setValue(line[13]);
                    eventDto.getEventParameters().add(eventParametersDto11);

                    EventParametersDto eventParametersDto12 = new EventParametersDto();
                    eventParametersDto12.setName("Carbon Dioxide(ppm)");
                    eventParametersDto12.setType("Double");
                    eventParametersDto12.setValue(line[14]);
                    eventDto.getEventParameters().add(eventParametersDto12);

                    EventParametersDto eventParametersDto13 = new EventParametersDto();
                    eventParametersDto13.setName("Volatile Organic Compound(ppb)");
                    eventParametersDto13.setType("Double");
                    eventParametersDto13.setValue(line[15]);
                    eventDto.getEventParameters().add(eventParametersDto13);

                    EventParametersDto eventParametersDto14 = new EventParametersDto();
                    eventParametersDto14.setName("RSSI");
                    eventParametersDto14.setType("Double");
                    eventParametersDto14.setValue(line[16]);
                    eventDto.getEventParameters().add(eventParametersDto14);

                    EventParametersDto eventParametersDto15 = new EventParametersDto();
                    eventParametersDto15.setName("Battery Level(%)");
                    eventParametersDto15.setType("Double");
                    eventParametersDto15.setValue(line[17]);
                    eventDto.getEventParameters().add(eventParametersDto15);
                }

                else if(line[0].equals("gps")) {

                    eventDto.setEventName(line[0]);
                    eventDto.setStateName("none");

                    EventParametersDto eventParametersDto0 = new EventParametersDto();
                    eventParametersDto0.setName("UTC date & Time");
                    eventParametersDto0.setType("Double");
                    eventParametersDto0.setValue(line[4]);
                    eventDto.getEventParameters().add(eventParametersDto0);

                    EventParametersDto eventParametersDto1 = new EventParametersDto();
                    eventParametersDto1.setName("Latitude");
                    eventParametersDto1.setType("Double");
                    eventParametersDto1.setValue(line[5]);
                    eventDto.getEventParameters().add(eventParametersDto1);

                    EventParametersDto eventParametersDto2 = new EventParametersDto();
                    eventParametersDto2.setName("Longitude");
                    eventParametersDto2.setType("Double");
                    eventParametersDto2.setValue(line[6]);
                    eventDto.getEventParameters().add(eventParametersDto2);

                    EventParametersDto eventParametersDto3 = new EventParametersDto();
                    eventParametersDto3.setName("MSL Altitude(m)");
                    eventParametersDto3.setType("Double");
                    eventParametersDto3.setValue(line[7]);
                    eventDto.getEventParameters().add(eventParametersDto3);

                    EventParametersDto eventParametersDto4 = new EventParametersDto();
                    eventParametersDto4.setName("Speed Over Ground(km/h)");
                    eventParametersDto4.setType("Double");
                    eventParametersDto4.setValue(line[8]);
                    eventDto.getEventParameters().add(eventParametersDto4);

                    EventParametersDto eventParametersDto5 = new EventParametersDto();
                    eventParametersDto5.setName("Course Over Ground(degrees)");
                    eventParametersDto5.setType("Double");
                    eventParametersDto5.setValue(line[9]);
                    eventDto.getEventParameters().add(eventParametersDto5);

                    EventParametersDto eventParametersDto6 = new EventParametersDto();
                    eventParametersDto6.setName("GNSS Satellites in View");
                    eventParametersDto6.setType("Double");
                    eventParametersDto6.setValue(line[16]);
                    eventDto.getEventParameters().add(eventParametersDto6);

                    EventParametersDto eventParametersDto7 = new EventParametersDto();
                    eventParametersDto7.setName("GNSS Satellites Used");
                    eventParametersDto7.setType("Double");
                    eventParametersDto7.setValue(line[17]);
                    eventDto.getEventParameters().add(eventParametersDto7);

                }

                eventDtoList.add(eventDto);
                responseMap = new HashMap<String, Object>();
                responseMap.put(Constants.MAC_KEY, line[1]);
                responseMap.put(Constants.EVENT_RESPONSE, eventDtoList);


            } else {
                throw new PluginServiceException("Unkonwn operation as : " + operation);

            }
        return responseMap;}

    }
}