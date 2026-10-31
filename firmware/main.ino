#include "BluetoothSerial.h"
#include <Arduino.h>

BluetoothSerial serialBT;
char BT;
int Speed = 100;

#define AIN1 19
#define AIN2 21
#define PWMA 18

#define BIN1 23
#define BIN2 22
#define PWMB 5

#define STBY 4

#define pwmRight 0
#define pwmLeft  1

void setup() {
  Serial.begin(115200);
  serialBT.begin("My Soccer Bot YT");

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);

  ledcSetup(pwmRight, 5000, 8);
  ledcAttachPin(PWMA, pwmRight);

  ledcSetup(pwmLeft, 5000, 8);
  ledcAttachPin(PWMB, pwmLeft);
}

void loop() {
  while (serialBT.available()) {
    BT = serialBT.read();

    if (BT == '0') Speed = 100;
    if (BT == '1') Speed = 110;
    if (BT == '2') Speed = 120;
    if (BT == '3') Speed = 130;
    if (BT == '4') Speed = 140;
    if (BT == '5') Speed = 150;
    if (BT == '6') Speed = 180;
    if (BT == '7') Speed = 200;
    if (BT == '8') Speed = 220;
    if (BT == '9') Speed = 240;
    if (BT == 'q') Speed = 255;

    if (BT == 'F') go_forward();
    else if (BT == 'B') go_backward();
    else if (BT == 'L') go_left();
    else if (BT == 'R') go_right();
    else if (BT == 'S') stopMotors();
    else if (BT == 'I') forward_right();
    else if (BT == 'J') backward_right();
    else if (BT == 'G') forward_left();
    else if (BT == 'H') backward_left();
  }
}

void go_forward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  ledcWrite(pwmRight, Speed);
  ledcWrite(pwmLeft, Speed);
}

void go_backward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  ledcWrite(pwmRight, Speed);
  ledcWrite(pwmLeft, Speed);
}

void go_left() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  ledcWrite(pwmRight, Speed);
  ledcWrite(pwmLeft, Speed);
}

void go_right() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  ledcWrite(pwmRight, Speed);
  ledcWrite(pwmLeft, Speed);
}

void stopMotors() {
  ledcWrite(pwmRight, 0);
  ledcWrite(pwmLeft, 0);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void forward_right() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  ledcWrite(pwmRight, Speed);
  ledcWrite(pwmLeft, 0);
}

void backward_right() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  ledcWrite(pwmRight, Speed);
  ledcWrite(pwmLeft, 0);
}

void forward_left() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  ledcWrite(pwmRight, 0);
  ledcWrite(pwmLeft, Speed);
}

void backward_left() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  ledcWrite(pwmRight, 0);
  ledcWrite(pwmLeft, Speed);
}