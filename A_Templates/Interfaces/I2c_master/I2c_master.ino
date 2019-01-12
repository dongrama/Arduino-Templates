

#include <Wire.h>
#define LED 17

void setup() {
  Wire.begin();
  pinMode(LED,OUTPUT);
  Serial.begin(115200);
  Serial.println("I2C Master ready!");
}

void loop() {
  delay(50);
  Serial.println("Write data");
  digitalWrite(LED,1);
//  Wire.beginTransmission(8);
//  Wire.write(0);
//  Wire.endTransmission();
  digitalWrite(LED,0);
  Serial.println("Receive data");
  Wire.requestFrom(8,1,true);
  String response = "";
  while (Wire.available()) {
    
      digitalWrite(LED,1);
      char b = Wire.read();
      response = b;
  }
  
  digitalWrite(LED,0);
  Serial.println(response);
}
