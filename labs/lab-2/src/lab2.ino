#include <Arduino.h>

int RED_LED = 4;
int GREEN_LED = 6;
int BUTTON = 2;
int bState = 0;

void setup(){
  pinMode(BUTTON, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600);

  // set initial LED state
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
}

void loop(){

  bState = digitalRead(BUTTON);

  if(bState == HIGH && digitalRead(RED_LED) == HIGH){
    digitalWrite(RED_LED,LOW);
    digitalWrite(GREEN_LED,HIGH);
  } else if(bState == HIGH && digitalRead(GREEN_LED) == HIGH){
    digitalWrite(RED_LED,HIGH);
    digitalWrite(GREEN_LED,LOW);
  }
}
