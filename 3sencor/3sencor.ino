#include <SoftwareSerial.h>

SoftwareSerial BT(3,4);


#define DIS 30

#define IN1 13
#define IN2 12
#define ENA 11
#define IN3 8
#define IN4 7
#define ENB 6

#define TRIGF A4
#define ECHOF A5

#define TRIGR A0
#define ECHOR A1

#define TRIGL A2
#define ECHOL A3

// 부저
#define SOUND 5

// 멜로디
#define c4 3822 // 261.63Hz 도
#define d4 3405 // 293.67Hz 레
#define e4 3034 // 329.63Hz 미
#define f4 2863 // 349.23Hz 파
#define g4 2551 // 392.11Hz 솔
#define g4s 2408 // 415.30Hz 솔#
#define a4 2273 // 440.11Hz 라
#define b4 2025 // 493.88Hz 시
#define c5 1910 // 523.25Hz 도
#define d5 1703 // 587.33Hz 레
#define d5s 1607 // 584.37Hz 레#
#define e5 1517 // 659.26Hz 미
#define f5 1432 // 698.46Hz 파
#define g5 1276 // 783.99Hz 솔
#define a5 1136 // 880.11Hz 라
#define b5 1012 // 987.77Hz 시

long distanceF;
long distanceR;
long distanceL;

// 후진할 때 부저 멜로디
int song[] = { e5, d5s, e5, d5s, e5, b4, d5, c5, a4, c4, e4, a4, b4, e4, g4s, b4, c5, e4, e5, d5s, e5,
d5s, e5, b4, d5, c5, a4, c4, e4, a4, b4, e4, c5, b4, a4 };

unsigned long mil = 0;
int song_pivot=0;

char mode;

void setup() {
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(ENB, OUTPUT);
  
pinMode(TRIGF,OUTPUT);
pinMode(ECHOF, INPUT);

pinMode(TRIGR, OUTPUT);
pinMode(ECHOR, INPUT);

pinMode(TRIGL, OUTPUT);
pinMode(ECHOL, INPUT);

pinMode(SOUND, OUTPUT);

Serial.begin(9600);
BT.begin(9600);
}

void loop() {
char c;

  if(BT.available()>0) {
    c = BT.read();
    if(c == 'F') { mode = 'f';}
    else if(c == 'B') { mode = 'b';}
    else if(c == 'L') { mode = 'l';}
    else if(c == 'R') { mode = 'r';}
    else if(c == 'V') { mode = 'v';}
    else if(c == 'A') { mode = 'a';}
    else if(c == 'S') { mode = 's';}
  }
    if(mode == 'f') Front();
    if(mode == 'b') Back();
    if(mode == 'l') Left();
    if(mode == 'r') Right();
    if(mode == 'a') Auto();
    if(mode == 's') Stop();
    if(mode == 'v') {
      for(int i = 0; i <= 34; i++) {
      sing(song[song_pivot++]);
     if(song_pivot == 35)  song_pivot = 0;
      mil = millis();
    }
    }
  /* if(c == 'F') {
    Front();
   }
   else if(c == 'B') {
    Back();
   }
   else if(c == 'L') {
   Left();
   }
   else if(c == 'R') {
    Right();
   }
   else if(c == 'V') {
    for(int i = 0; i <= 34; i++) {
      sing(song[song_pivot++]);
     if(song_pivot == 35)  song_pivot = 0;
      mil = millis();
    }
   } else if(c == 'A') {
    
   }
   
   else {
    Stop();
   }*/
  
}


void Auto() { // 자율주행모드
   if(FrontSensor() <= 18 && RightSensor() <= 18 && LeftSensor() <= 18) {
       Right(); // 만약 양측면, 전방 초음파 센서 18cm 앞에 장애물이 있다면 우회전하기
      }
    else if(FrontSensor() > 18 && RightSensor() <= 18 && LeftSensor() > 18) {
        Left();
      }
    else if(FrontSensor() <= 18 && RightSensor() > 18 && LeftSensor() > 18) {
      Right();
    }
    else if(FrontSensor() > 18 && RightSensor() > 18 && LeftSensor() <= 18) {
      Right();
    }
    else if(FrontSensor() <= 18 && RightSensor() <= 18 && LeftSensor() > 18) {
     Left(); 
    }
    else if(FrontSensor() <= 18 && RightSensor() > 18 && LeftSensor() <= 18) {
      Right();
    }
    else {
      Front();
    }

}

long RightSensor() { // 오른쪽 초음파 센서
   digitalWrite(TRIGR, HIGH);  // 초음파 발사
    delayMicroseconds(5);
    digitalWrite(TRIGR, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIGR, HIGH);
    distanceR = pulseIn(ECHOR, HIGH);
    return (distanceR/58); // 장애물과의 거리 계산 후 리턴
}

long FrontSensor() { // 전방 초음파 센서
   digitalWrite(TRIGF, HIGH); // 초음파 발사
    delayMicroseconds(5);
    digitalWrite(TRIGF, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIGF, HIGH);
    distanceF = pulseIn(ECHOF, HIGH);
    return (distanceF/58);  // 장애물과의 거리 계산 후 리턴
}

long LeftSensor() { // 왼쪽 초음파 센서
   digitalWrite(TRIGL, HIGH);  // 초음파 발사
    delayMicroseconds(5);
    digitalWrite(TRIGL, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIGL, HIGH);
    distanceL = pulseIn(ECHOL, HIGH);
    return (distanceL/58);  // 장애물과의 거리 계산 후 리턴
}

void sing(int eum) {
  long lele = 125000;
  for(long i=0; i< lele ; i+= eum) {
    digitalWrite(SOUND, HIGH);
    delayMicroseconds(eum/2);
    digitalWrite(SOUND, LOW);
    delayMicroseconds(eum/2);
  }
}

void Front() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB,255);
}

void Back() {
    /*digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA,255);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB,255);*/

    digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,255);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB,255);

  delay(925);
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB,0);
}

void Left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA,255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB,255);
}

void Right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,255);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB,255);
}
