/*
  When trigger button is pressed, a sound is randomly selected from
  the sound bank and is played and the tail light LEDs flash
*/

#include <SPI.h> //SPI Lib
#include <SdFat.h> //SDFat lib
#include <SFEMP3Shield.h> // MP3 Shield lib

// initiating variables
SdFat sd;
SFEMP3Shield player;

const uint8_t vol = 0;
const uint16_t mono = 1;

int triggerBtn = 5;
int LEDpin = 10;
int rando;

// sounds preloaded onto SD card
char* fileNames[7] = {"track001.mp3", "track002.mp3", "track003.mp3", "track004.mp3", "track005.mp3", "track006.mp3", "track007.mp3"};

void setup() {
  pinMode(triggerBtn, INPUT_PULLUP);
  pinMode(LEDpin, OUTPUT);
  initSD();
  initMP3();
  Serial.begin(115200);
}

void loop() {

  rando = random(0,8);

  if(digitalRead(triggerBtn) == 1){
    if(player.isPlaying()){
      player.stopTrack();
    } else {
      player.playMP3(fileNames[rando]);
//      player.playMP3("track001-amp.mp3");
    }

    blink(LEDpin, 200, 10);
  }

}


void blink(int LEDpin, int len, int num){
  for(int i = 0; i < num; i++){
    if(i % 2 == 0){
      digitalWrite(LEDpin, HIGH);
//        Serial.println("HIGH");
    } else {
      digitalWrite(LEDpin, LOW);
//        Serial.println("LOW");
    }
    delay(len);
  }
}

// Following functions are from the MP3 Shield hookup guide found on the Sparkfun product page
// https://learn.sparkfun.com/tutorials/mp3-player-shield-hookup-guide-v15

void initSD() {
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)){
    sd.initErrorHalt();
  }
  if(!sd.chdir("/")){
    sd.errorHalt("sd.chdir");
  }
}

void initMP3() {
  uint8_t result = player.begin();

  player.setVolume(vol, vol);
  player.setMonoMode(mono);
}
