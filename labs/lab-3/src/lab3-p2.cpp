#include <Arduino.h>

int LED1 = 6;
int LED2 = 5;
int force = A0;
int photo = A1;


void setup(){
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop(){

  int forceVal = analogRead(force);
  int photoVal = analogRead(photo);

  int pV = map(photoVal, 300, 900, 0, 255);
//  Serial.print("force value: ");
//  Serial.println(forceVal);
  Serial.print("Photo value: ");
  Serial.println(photoVal);
  analogWrite(LED1, forceVal/4);
  analogWrite(LED2, pV);



}
