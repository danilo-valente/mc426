#include <Ultrasonic.h>
#define PINO_TRG  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define PINO_ECHO     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

//NewPing sonar(PINO_TRG, PINO_ECHO, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Ultrasonic ultrasonic(PINO_TRG, PINO_ECHO);

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  //Variaveis para guardar os valores em 
  //cm (cmSec) e polegadas (inMsec)
  float cmMsec, inMsec;
  
  //Le os valores do sensor ultrasonico
  long microsec = ultrasonic.timing();
  //Atribui os valores em cm ou polegadas as variaveis
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  
  //Mostra os valores na serial
  Serial.print("Centimetros: ");
  Serial.print(cmMsec);
  Serial.print(" - Polegadas: ");
  Serial.println(inMsec);
  
  //Aguarda 1 segundo e reinicia o processo
  delay(1000);
}
