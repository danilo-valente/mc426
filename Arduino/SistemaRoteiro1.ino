
int releLuz1 = 30;
int releLuz2 = 32;
int releLuz3 = 34;
int releLuz4 = 36;
int inputPin = 52;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int pinCaixa = 46;

int pirState = LOW;             // we start, assuming no motion detected

int caixa = 0;
int pwmPin = 3;
int flag = 0;
int val2 = 0;

//-------------------- Sensor de Temp/hum ----------------------------
/*
  #define DHTPIN 52 // pino do sensor de humidade
  #define DHTTYPE DHT11 // DHT 11

  DHT dht(DHTPIN, DHTTYPE);

  float temperatura = 0.0;
  float humidade = 0.0;

  //-------------------- Fim Sensor de temp/hum ------------------------*/

//-------------------- Sensor de fumaca ------------------------------

const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin
int leitorFumaca;

//------------------- Fim sensor de fumaca ---------------------------


void setup() {
  pinMode(releLuz1, OUTPUT);
  pinMode(releLuz2, OUTPUT);
  pinMode(releLuz3, OUTPUT);
  pinMode(releLuz4, OUTPUT);
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(pinCaixa, INPUT);

  pinMode(pwmPin, OUTPUT); // sets the pin as output

  TCCR3B = (TCCR3B & 0b11111000) | 0x04;

  //inicializacao temp/hum

  //dht.begin();

  //fim inicializacao temp/hum

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH

    if (pirState == LOW) {
      // we have just turned on
      digitalWrite(releLuz1, LOW);
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {

    if (pirState == HIGH) {
      // we have just turned of
      digitalWrite(releLuz1, HIGH);
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  /*
    //parte da temperatura
    temperatura = dht.readTemperature();
    humidade = dht.readHumidity();

    if(isnan(temperatura) || isnan(humidade)){
    Serial.println("Falha ao ler temperatura/humidade");
    }
    else{
    //insira o que fazer com temperatura aqui
    //se a temperatura ultrapassar 30 graus celsius
    if(temperatura > 30){
      //acende o rele
       digitalWrite(releLuz2, LOW);
    }
    else{
      //se nao, apaga o rele
      digitalWrite(releLuz2, HIGH);
    }
    }
    //fim temperatura
  */
  //inicio fumaca

  leitorFumaca = analogRead(gasPin);
  if (leitorFumaca > 250) {
    digitalWrite(releLuz2, LOW);
    if (val2 == 0) {
      flag = 1;
    } else if (val2 == 510 ) {
      flag = 0;
    }

    analogWrite(pwmPin, (val2));

    if (flag == 1) {
      val2++;
    } else {
      val2--;
    }
    delay(7);
  }
  else {
    digitalWrite(releLuz2, HIGH);
    digitalWrite(pwmPin, LOW);
  }


  //fim fumaca

  caixa = digitalRead(pinCaixa);  // read input value
  if (caixa == HIGH) {
    // check if the input is HIGH
    digitalWrite(releLuz3, LOW);
    digitalWrite(releLuz4, LOW);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Full");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH) {
      digitalWrite(releLuz3, LOW);
      digitalWrite(releLuz4, LOW);
      caixa = LOW;
      digitalWrite(pwmPin, LOW);
      // we have just turned of
      // We only want to print on the output change, not state
      pirState = LOW;
    }

    //delay(5000);
    //digitalWrite(releLuz1, HIGH); // HIGH desliga o rele!
    // a leitura vai ser por segundo.
    // delay(1000);
    digitalWrite(releLuz1, LOW); // LOW LIGA o rele!!
    digitalWrite(releLuz2, HIGH);
    //delay(5000);
    digitalWrite(releLuz3, HIGH);
    //delay(5000);
    digitalWrite(releLuz4, HIGH);
    //delay(5000);
    //digitalWrite(releLuz2, LOW);
    //digitalWrite(releLuz3, LOW);
    //digitalWrite(releLuz4, LOW);

    // put your main code here, to run repeatedly:

  }

