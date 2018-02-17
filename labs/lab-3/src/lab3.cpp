#include <Arduino.h>

int LED_PIN = 6;
int pot = A5;

void setup(){
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

}

void loop(){


  int val = analogRead(pot);
  Serial.print("Pot value: ");
  Serial.println(val);
  analogWrite(LED_PIN, val/4);
}
