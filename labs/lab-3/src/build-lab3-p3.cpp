#include <Arduino.h>

int flexes = A0;
int spkrOut = 8;

void setup(){

  Serial.begin(9600);
  pinMode(spkrOut, OUTPUT);

}

void loop(){

  String sOne = "Flex value: ";
  int fVal = analogRead(spkrOut); // reads analog input
  // String sTwo = sOne + fVal;
  Serial.println(fVal);





}
