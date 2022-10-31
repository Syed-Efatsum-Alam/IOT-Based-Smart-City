#include <Servo.h>
int const trigPin = 10;
int const echoPin = 11;
int const buzzPin = 12;
int const trigPin1 = 3;
int const echoPin1 = 4;
int const servoPin = 7;
int const ldr = 13;
Servo Servo1;
void setup()
{
  Servo1.attach(servoPin);
  //Servo1.write(180);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(ldr, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  float sensorValue = analogRead(A1);
  delay(200);
  // Reads the analog input ranging from 0 to 1023
  Serial.print("LDR value: ");
  Serial.print(sensorValue);
  Serial.print("  \n");
  if (sensorValue < 120)
  {
    digitalWrite(ldr, HIGH);
  }
  else {
    digitalWrite(ldr, LOW);
  }




  Servo1.write(47);
  int duration, distance, duration1, distance1;

  digitalWrite(trigPin1, HIGH);
  delay(1);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration / 2) / 29.1;


  if (distance1 < 4) {
    if (distance > 2) {
      Servo1.write(75);
      digitalWrite(buzzPin, HIGH);
      delay(10000);
    }
    else {
      digitalWrite(buzzPin, LOW);
    }
  }




  Serial.print("Object distance: ");
  Serial.print(distance1);
  Serial.print(" cm.");
  Serial.print("   ");
  Serial.print("Trash distance: ");
  Serial.print(distance);
  Serial.println(" cm.");

}













//#include <Servo.h>
//int const trigPin = 10;
//int const echoPin = 11;
//
//int const trigPin1 = 3;
//int const echoPin1 = 4;
//int servoPin = 7;
//Servo Servo1;
//void setup()
//{
//  Servo1.attach(servoPin);
//  //Servo1.write(180);
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
//  pinMode(trigPin1, OUTPUT);
//  pinMode(echoPin1, INPUT);
//  //pinMode(buzzPin, OUTPUT);
//  Serial.begin(9600);
//}
//void loop()
//{
//  Servo1.write(47);
//  int duration, distance, duration1, distance1;
//
//  digitalWrite(trigPin1, HIGH);
//  delay(1);
//  digitalWrite(trigPin1, LOW);
//  duration1 = pulseIn(echoPin1, HIGH);
//  distance1 = (duration1 / 2) / 29.1;
//
//  digitalWrite(trigPin, HIGH);
//  delay(1);
//  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH);
//  // Distance is half the duration devided by 29.1 (from datasheet)
//  distance = (duration / 2) / 29.1;
//
//
//  if (distance1 < 4) {
//    if (distance > 2) {
//      Servo1.write(75);
//      delay(10000);
//    }
//  }
//  Serial.print("S: ");
//  Serial.print(distance);
//  Serial.println(" cm.");
//  Serial.print("   ");
//  Serial.print(distance1);
//  Serial.println(" cm.");
//
//}
