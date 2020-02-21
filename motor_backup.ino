#include<VirtualWire.h>
struct package
{
  float code;
  float number;
  float number2;
  };
  
int trig = 12;
const int ena=3;
const int enb=5;
const int in1=7;
const int in2=8;
const int in3=4;
float x,y;

const int in4=2;

int eco = 6;
int led = 13;
float pitch1,roll1;
long duration;
long distance;
typedef struct package Package;
  Package data;
const int receive_pin = 11;
void setup() {

  Serial.begin(9600);
  Serial.println("START"); 
  pinMode(trig,OUTPUT);
  pinMode(eco,INPUT);
  pinMode(led,OUTPUT);
    pinMode(ena,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
    pinMode(enb,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  

  
  
  

  vw_set_rx_pin(receive_pin);
  vw_setup(500);
  vw_rx_start();
}

void loop() {

  
    uint8_t buf[sizeof(data)];
    
    uint8_t buflen = sizeof(data);
                             
    if (vw_have_message()==true)  // Is there a packet for us? 
    {
    
         vw_get_message(buf, &buflen);
             memcpy(&data,&buf,buflen);
         Serial.println("R");    
    
    if (data.code == 900.0)
    {
        
        //Serial.println("Package =");
        //Serial.println(2);
       Serial.println(data.number);
           Serial.println(data.number2);
           pitch1=data.number;
           roll1=data.number2;
//         digitalWrite(trig,LOW);
//         delayMicroseconds(2);
//        digitalWrite(trig,HIGH);
//        delayMicroseconds(10);
//        digitalWrite(trig,LOW);
//       duration = pulseIn(eco,HIGH);  
//          distance = duration*0.034/2;
         x=fabs(pitch1);
         y=fabs(roll1);
     
//     if(distance>=15)
//   {
      if(x>y)
      {
   
          if(pitch1>0 )      
    {
      Serial.print("moving forward");
      analogWrite(ena,100);
        analogWrite(enb,100);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
     
    }
    else if(pitch1<0 )
    {
      Serial.print("moving backwards");
      analogWrite(ena,100);
        analogWrite(enb,100);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      
    }
      }
   else if(y>x )
    {
      if(roll1>0 )
    {
       Serial.print("turning right"); 
       analogWrite(ena,100);
       analogWrite(enb,0);            
       digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
     
      
    }
      
   
    
      
      else if(roll1<0)
       
    {
       Serial.print("turning left");
      analogWrite(ena,0);
        analogWrite(enb,100);
       digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
       
      
    }
  }
     
  
  
    
    
    else 
    {
      analogWrite(ena,0);
            analogWrite(enb,0);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      }
//    Serial.print("STOP");
    }
    

    }
    
//     else 
//     {
//
//      Serial.println(data.code);
//    }
    }
       
