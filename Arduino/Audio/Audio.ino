/*
   PIR sensor tester
*/
//int rele = 46;
int pwmPin = 3; // output pin supporting PWM
//int pwmPin2 = 7; // output pin supporting PWM
//int inPin = 3; // voltage connected to analog pin 3, e.g. a potentiometer
int val2 = 0; // variable to store the read value
int flag = 0;
int freq = 4;
int ledPin = 28;                // choose the pin for the LED
int inputPin = 52;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status



void setup() {
  pinMode(pwmPin, OUTPUT); // sets the pin as output
  TCCR3B = (TCCR3B & 0b11111000) | freq;

  //pinMode(rele, OUTPUT);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  //TCCR4B = (TCCR4B & 0b11111000) | 0x01;
  Serial.begin(9600);
}

void loop() {

  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {// check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    float sen = 0;
  
    if (val2 == 510) {
      flag = 1;
    }

    if (val2 == 0 ) {
      flag = 0;
    }

    analogWrite(pwmPin, (val2));
    //analogWrite(pwmPin2, (100));

    if (flag == 1) {
      val2++;
    } else {
      val2--;
    }

    delay(7);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
      //digitalWrite(rele, LOW);
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    analogWrite(pwmPin, 0);
    if (pirState == HIGH) {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
      //digitalWrite(rele, HIGH);
    }
  }
}

