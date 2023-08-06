#include <RCSwitch.h>

#define joyX A0
#define joyY A1

RCSwitch mySwitch = RCSwitch();

int button=2;
void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  mySwitch.enableTransmit(2);
}
 
void loop() {
 int xValue = analogRead(joyX);
 int yValue = analogRead(joyY);
 
  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
  mySwitch.send("", 4);

  delay(50);
}