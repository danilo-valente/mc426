#include <DHT.h>

#define DHTPIN 52 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

int rele = 46;
int ledPin = 28;                // choose the pin for the LED
int inputPin = 52;               // choose the input pin (for PIR sensor)
float temp = 0.0;
float hum = 0.0;
void setup(){

  pinMode(rele, OUTPUT);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  dht.begin();
  Serial.begin(9600);
  
}

void loop()
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();
   if (isnan(temp) || isnan(hum)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    Serial.print("Umidade: ");
    Serial.print(hum);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" *C");
    delay(1000);
    if(temp <= 25.0){
        digitalWrite(rele, LOW);
       digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(rele, HIGH);
      digitalWrite(ledPin, LOW);
    }
  }
}

