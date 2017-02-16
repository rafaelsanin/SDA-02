#include <mcp4141.h>
#include <amodulator.h>
#include <ArduinoJson.h>

MCP4141 digital_pot = MCP4141(10);
String command;
float parameter;

// AMODULATOR am = AMODULATOR(3,10);
// uint8_t signal[100] = {102,88,21,94,88,15,106,7,112,53,78,83,69,51,
//                   4,107,1,21,44,30,121,65,94,75,56,87,50,95,9,
//                   101,56,106,114,17,69,17,27,46,32,96,40,15,17,
//                   57,86,47,84,37,117,42,24,114,69,76,81,9,28,86,
//                   21,20,55,115,4,71,17,35,6,107,81,2,3,25,112,10,
//                   56,41,20,74,46,1,71,10,65,1,73,29,108,20,59,2,
//                   67,80,25,122,8,47,77,104,108,3};

void setup(){
  Serial.begin(115200);
  // am.init();
}


// void loop(){
//   for(int i=0;i<100;i++){
//     am.modulate(signal[i]);
//     delay(20);
//   }
// }

void loop(){
  if(new_command()){
    if(command == "set"){
      digital_pot.set(parameter);
    }
    else if(command == "setPercent"){
      digital_pot.setPercent(parameter);
    }
    else if(command == "read"){
      Serial.print("VOUT: ");Serial.println(analogRead(A0)*(5.0/1023));
    }
  }
}

bool new_command(){
  if(Serial.available() > 0){
    StaticJsonBuffer<200> jsonBuffer;
    String inp = Serial.readStringUntil('\n');
    JsonObject& root = jsonBuffer.parseObject(inp);
    if(root.success()){
      command = root["command"].asString();
      parameter = root["parameter"];
      return true;
    }
  }
  return false;
}
