
float sensorValue;
int x=0;
float output;
int sp=A3;
int ledPin=9; 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(sp,INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
 

while(Serial.available()==0)
{}
 x=Serial.parseFloat();
 analogWrite(ledPin,x);
 
}
