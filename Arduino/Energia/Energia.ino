#include "EmonLib.h"             // Include Emon Library
EnergyMonitor emon1;             // Create an instance

double potTotal = 0;

void setup()
{  
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  emon1.current(A1, 93);       // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  double volt = analogRead(A2);
  double pot = 0;
  double consumo = 0;
  
  Irms = Irms/5; // fio passa 5 vezes no sensor, aumenta a precisão! (quanto mais vezes, melhor)
  
  Serial.print(Irms);// Apparent power
  Serial.print("\t");

  volt = volt - 90; // pela montagem ta pegando duas fases, entao aqui desconto uma fase
  
  Serial.print(volt);// Voltagem
  Serial.print("\t");

  pot = Irms*(volt);

  potTotal = pot + potTotal; // calculo da curva de energia de consumo em Joules/segundo ou Watts

  consumo = potTotal/3600000; // transforma em kWh
  
  Serial.print(pot);// É o consumo em tempo real
  Serial.print("\t");
  Serial.print(consumo);// em kWh
  Serial.print("\n");
  
}
