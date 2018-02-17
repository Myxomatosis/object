#include <Arduino.h>

int flexes = A0;
int spkrOut = 8;
int key;
float freq;

void setup(){

  Serial.begin(9600);
  pinMode(spkrOut, OUTPUT);

}

void loop(){

  int fVal = analogRead(spkrOut); // reads analog input
  Serial.println(fVal);


  key = map(fVal, 0, 1023, 100, 2000);
  // float a = pow(2, 1/key);
  // float b = pow(a, key-49);
  // float freq = pow(a, b) * 440;
  // Serial.print("Freq: ");
  // Serial.println(freq);

  tone(spkrOut, key, 10);





}
