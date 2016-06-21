/* Testing MQ-2 GAS sensor with serial monitor
   Suitable for detecting of LPG, i-butane, propane, methane ,alcohol, Hydrogen or smoke
   More info: http://www.ardumotive.com/how-to-use-mq2-gas-sensor-en.html
   Dev: Michalis Vasilakis // Date: 11/6/2015 // www.ardumotive.com                     */

const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin
int val2 = 0;
int leitorFumaca = 0;
int pwmPin = 3;

void setup()
{
  pinMode(pwmPin, OUTPUT); // sets the pin as output
  TCCR3B = (TCCR3B & 0b11111000) | 0x04;

  Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop()
{
  Serial.println(analogRead(gasPin));
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
    digitalWrite(pwmPin, LOW);
  }
}
