#include "Audio"

int flamePin = 39;
int flame = HIGH;

void setup() {
  pinMode(flamePin,INPUT);
  Serial.begin(9600);
}

void loop() {
  flame = digitalRead(flamePin);
  
  if(flame == LOW){
    Serial.println("Fogo!");
    audio.setup();
    audio.loop();
  }else{
    audio.desativar();
  }
}
