#include <Arduino.h>
int l1=8;  //LED 1
int echol1=2; //Echo Pin 1st ultrasonic sensor
int trigl1=3; //Trigger Pin 1st ultrasonic sensor
int long duration1,cm1; //Variable for holding distance
void setup() {
  Serial.begin(9600);
  pinMode(l1,OUTPUT);
  pinMode(trigl1,OUTPUT);
  pinMode(echol1,INPUT); 
}

void loop() {
  //first ultrasonic sensor
  digitalWrite(trigl1,0);
  delayMicroseconds(5);
  digitalWrite(trigl1,1);
  delayMicroseconds(10);
  digitalWrite(trigl1,0);
  duration1=pulseIn(echol1,1);
  cm1=(duration1/2)/29.1;
 //print distances
  Serial.println("Distance of 1st LED in cm (cm1) : "+(String)cm1+"");
   //logic for turning ON LEDs
  if(cm1<10)
  { digitalWrite(l1,1);
    delay(2000); }
  else {
    digitalWrite(l1,0); }
}
