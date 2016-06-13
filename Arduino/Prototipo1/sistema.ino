/*Prototipacao sistema 1
 *Feito:
 **Monitoramento : Acende um led caso registre movimento
 *A fazer:
 **Portas e luzes (para entregavel 1)
 * 
 * //////////////////////////////////////////////////
 * ////////Explicacao sensor de movimento PIR////////
 * //////////////////////////////////////////////////
 *
 * Switches a LED according to the state of the sensors output pin.
 * Determines the beginning and end of continuous motion sequences.
 *
 * @author: Kristian Gohlke / krigoo (_) gmail (_) com / http://krx.at
 * @date:   3. September 2006 
 *
 * kr1 (cleft) 2006 
 * released under a creative commons "Attribution-NonCommercial-ShareAlike 2.0" license
 * http://creativecommons.org/licenses/by-nc-sa/2.0/de/
 *
 *
 * The Parallax PIR Sensor is an easy to use digital infrared motion sensor module. 
 * (http://www.parallax.com/detail.asp?product_id=555-28027)
 *
 * The sensor's output pin goes to HIGH if motion is present.
 * However, even if motion is present it goes to LOW from time to time, 
 * which might give the impression no motion is present. 
 * This program deals with this issue by ignoring LOW-phases shorter than a given time, 
 * assuming continuous motion is present during these phases.
 *  
 */
 
 /*
  * Modificado para o sistema, comentários adaptados onde necessário
  */
 

//INCLUDES

#include <DHT.h>
#include <Ultrasonic.h>
 
///////////////////////
//-------------------- Declaracao de variaveis ---------------------

//---------------------Variaveis de sistema ------------------------
//variavel que controla o monitoramento
boolean monitoramento = false;
//---------------------Fim variaveis de sistema --------------------

//-------------------- Sensor Movimento ----------------------------
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;        

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;

int inputSensorMovPin = 3;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;			  //pin de saida para um led
//------------------- Fim Sensor Movimento ---------------------------

//------------------- Reles ------------------------------------------

int pinRele = 46;

//------------------- Fim de Reles -----------------------------------

//-------------------- Sensor de Temp/hum ----------------------------

#define DHTPIN 52 // pino do sensor de humidade
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

float temperatura = 0.0;
float humidade = 0.0;

//-------------------- Fim Sensor de temp/hum ------------------------

//-------------------- Sensor de gas ---------------------------------

int pinGas = A0;

//-------------------- Fim sensor de gas -----------------------------

//-------------------- Sensor de luz ---------------------------------

int pinSensorLuz = 52;
int valorSensorLuz;

//-------------------- Fim sensor de luz -----------------------------

//-------------------- Sensor sonar ----------------------------------

#define pin_TRG 12 //pino trigger sonar
#define pin_Echo 11 //pino echo
#define MAX_DISTANCE 200 //distancia maxima a ser medida

//inicializa ultrasom
Ultrasonic ultrasonic(pin_TRG, pin_Echo, MAX_DISTANCE);
// centimetros e polegadas
float cmMsec, inMsec;
long microSec;

//-------------------- Fim sensor sonar ------------------------------




/////////////////////////////
//Setup do arduino
void setup(){
	//inicializacao dos sensores
	Serial.begin(9600);

	//inicializacao LED
	
	pinMode(ledPin, OUTPUT);
	
	//fim de inicializacao de led
	
	//inicializacao rele
	
	pinMode(pinRele, OUTPUT);
	
	//fim inicializacao rele
	
	//inicializacao PIR

	//sensor de movimento pir como entrada
	pinMode(inputSensorMovPin, INPUT);
	//inicializa movimento em low
	digitalWrite(inputSensorMovPin, LOW);

	//calibragem do sensor de movimento
	Serial.print("calibrating sensor ");
	for(int i = 0; i < calibrationTime; i++){
		Serial.print(".");
		delay(1000);
    }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
	
	//fim inicializacao PIR
	
	//inicializacao temp/hum
	
	dht.begin();
	
	//fim inicializacao temp/hum
	
	
}

////////////////////////////
//
//Loop principal do sistema
void loop(){
	//-------------------- Codigo do Monitoramento ---------------------
	//se o monitoramento estiver ligado, verifica o estado do sensor de movimento.
	if(monitoramento == true){
		//se a leitura do sensor de movimento for HIGH
		if(digitalRead(inputSensorMovPin) == HIGH){
			//deixa o estado do led em HIGH
			digitalWrite(ledPin, HIGH);   //the led visualizes the sensors output pin state
			if(lockLow){  
				//makes sure we wait for a transition to LOW before any further output is made:
				lockLow = false;            
				Serial.println("---");
				Serial.print("motion detected at ");
				Serial.print(millis()/1000);
				Serial.println(" sec"); 
				delay(50);
			}         
			takeLowTime = true;
		}
		//se o estado do sensor de movimento for LOW
		if(digitalRead(pirPin) == LOW){       
			digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state
			if(takeLowTime){
				lowIn = millis();          //save the time of the transition from high to LOW
				takeLowTime = false;       //make sure this is only done at the start of a LOW phase
			}
			//if the sensor is low for more than the given pause, 
			//we assume that no more motion is going to happen
			if(!lockLow && millis() - lowIn > pause){  
				//makes sure this block of code is only executed again after 
				//a new motion sequence has been detected
				lockLow = true;                        
				Serial.print("motion ended at ");      //output
				Serial.print((millis() - pause)/1000);
				Serial.println(" sec");
				delay(50);
			}
		}
	}
	//--------------------- Fim Codigo Monitoramento ----------------------
	
	//--------------------- Codigo temperatura/humidade -------------------
	
	temperatura = dht.readTemperature();
	humidade = dht.readHumidity();
	
	if(isnan(temperatura) || isnan(humidade)){
		Serial.println("Falha ao ler temperatura/humidade");
	}
	
	else{
		//insira o que fazer com temperatura aqui
	}
	
	//--------------------- Fim temperatura/humidade ----------------------
	
	//--------------------- Codigo Sensor de gas --------------------------
	
	//insira o que fazer com gas aqui
	Serial.println(analogRead(pinGas));
	
	//--------------------- Fim sensor de gas -----------------------------
	
	//--------------------- Sesor de luz ----------------------------------
	
	photocellReading = analogRead(photocellPin);  
 
	Serial.print("Analog reading = ");
	Serial.print(photocellReading);     // the raw analog reading
 
	// Imprime baseado no nivel da leitura
	if (photocellReading < 10) {
		Serial.println(" - Dark");
	} else if (photocellReading < 200) {
		Serial.println(" - Dim");
	} else if (photocellReading < 500) {
		Serial.println(" - Light");
	} else if (photocellReading < 800) {
		Serial.println(" - Bright");
	} else {
		Serial.println(" - Very bright");
	}
	
	//--------------------- Fim sensor de luz -----------------------------
	
	//--------------------- Sensor Distancia ------------------------------
	
	//le os valores do sensor
	microSec = ultrasonic.timing;
	cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
	inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
	
	//Mostra os valores na serial
	Serial.print("Centimetros: ");
	Serial.print(cmMsec);
	Serial.print(" - Polegadas: ");
	Serial.println(inMsec);
	
	//--------------------- Fim sensor distancia --------------------------
	
	
	
	delay(1000);
}

//funcoes uteis
