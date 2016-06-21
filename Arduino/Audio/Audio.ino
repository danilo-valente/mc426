
int pwmPin = 3; // output pin supporting PWM
int val2 = 0; // variable to store the read value
int flag = 0;
int freq = 4;

void setup() {
  pinMode(pwmPin, OUTPUT); // sets the pin as output
  TCCR3B = (TCCR3B & 0b11111000) | freq;
  
  Serial.begin(9600);
}

void loop() {
  
    if (val2 == 510) {
      flag = 1;
    }

    if (val2 == 0 ) {
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

