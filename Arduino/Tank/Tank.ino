
int inputPin = 41;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
  
void setup() {
  pinMode(inputPin, INPUT);     // declare sensor as input 
  Serial.begin(9600);
}
 
void loop(){
 
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Full");
      audio.setup();
      audio.loop();
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      audio.desativar();
      // we have just turned of
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
