#include <Servo.h>

#define TRIG 8
#define ECHO 12
#define SERVO 2

Servo servo;


void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(SERVO,OUTPUT);
  servo.attach(2);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  int distance = (pulseIn(ECHO,HIGH) * 340) / 2 / 10000;
  if(distance <= 30) {
    Serial.print(distance);
    Serial.println(" cm");
    servo.write(120);
  }
  else {
    servo.write(0);
    Serial.println("above");
  }
}
