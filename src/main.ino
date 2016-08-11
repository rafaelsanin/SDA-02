#include <mcp4141.h>

MCP4141 digital_pot = MCP4141(10);

void setup(){
  Serial.begin(115200);
}

void loop(){
  for(int i=0;i<130;i+=10){
    digital_pot.set(i);
    Serial.println(digital_pot.getPosition());
    delay(1000);
  }
}
