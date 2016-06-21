#include <DHT.h>

#define DHTPIN 52 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

int releAque = 38;
int releVent = 40;
int inputPin = 52;               // choose the input pin (for PIR sensor)
float temp = 0.0;
float hum = 0.0;
void setup(){

  pinMode(releAque, OUTPUT);
  pinMode(releVent, OUTPUT);
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
        digitalWrite(releAque, LOW);
    }else{
      digitalWrite(releAque, HIGH);
    }
    if(temp <= 30.0){
       digitalWrite(releVent, LOW);
    }else{
      digitalWrite(releVent, HIGH);
    }
  }
}

