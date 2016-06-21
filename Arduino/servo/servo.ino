#include <Servo.h> 

Servo myservo;

int val;

void setup() 
{ 
  // Pino de dados do servo conectado ao pino 9 do Arduino
  myservo.attach(22);   
} 

void loop() 
{ 
       myservo.write(180);  //Move o servo para o angulo de 60 graus
       delay(3000);          //Delay para o servo atingir a posiçao
 
       myservo.write(-180);  //Move o servo para o angulo de 90 graus
       delay(3000);
 
}
