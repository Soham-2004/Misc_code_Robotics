#include<Wire.h>
#include <VirtualWire.h>

struct package
{
  float code;
  float number;
  float number2;
};

typedef struct package Package;
Package data;

const int transmit_pin = 12;
const int led_pin = 13;


const int MPU = 0x68;
float pitch;
float pitch1;
float roll1;
float roll;
int16_t acX, acY, acZ;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
vw_set_tx_pin(transmit_pin);
  vw_setup(500);
pinMode(led_pin, OUTPUT);
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}


void loop() {
   // put your main code here, to run repeatedly:
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);
    acX=Wire.read()<<8|Wire.read();
    acY=Wire.read()<<8|Wire.read();
    acZ=Wire.read()<<8|Wire.read();
    pitch=atan2(acY,acZ);
    
    Serial.println(pitch);
   
    roll=atan2(acX,acZ);
  
    
    digitalWrite(led_pin, HIGH); // Flash a light to show transmitting


  data.code = 900.0;//password
  data.number = pitch;
  data.number2=roll;//


vw_send((uint8_t *)&data, sizeof(data));
 vw_wait_tx(); // Wait until the whole message is gone

Serial.print("PITCH =   ");
Serial.println(data.number);

Serial.print("ROLL =   ");
Serial.println(data.number2);
digitalWrite(led_pin, LOW);
  delay(10);
  
 
    
} 
