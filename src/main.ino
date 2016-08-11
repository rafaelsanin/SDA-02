#include <mcp4141.h>
#include <ArduinoJson.h>

MCP4141 digital_pot = MCP4141(10);
String command;
float parameter;

void setup(){
  Serial.begin(115200);
}

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
