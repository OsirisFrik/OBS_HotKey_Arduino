// OBS HotKeys arduino keyboard v1.5.2
// Made by OsirisFrik
// Twitter & Twitch OsirisFrik
// Git https://github.com/OsirisFrik/OBS_HotKey_Arduino

#include <Keyboard.h>

const int switchA = 2;
int buttonA = 0;
int buttonB = 0;
int buttonC = 0;

const int ledYellow = 12;
const int ledGreen = 11;
const int ledRed = 10;
const int ledBlue = 9;

int state = 0;
bool onAir = false;
bool mode = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchA, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(switchA);
  buttonA = digitalRead(3);
  buttonB = digitalRead(4);
  buttonC = digitalRead(5);

  if (buttonA == 0){    
    digitalWrite(ledBlue, HIGH);    
    Keyboard.press(0x80);
    Keyboard.press(0x81);
    Keyboard.press('t');
    if (onAir == true){
      onAir = false;      
      digitalWrite(ledRed, LOW);
      delay(500);
    } else {
      onAir = true;      
      digitalWrite(ledRed, HIGH);
      delay(500);
    }    
    Keyboard.release(0x80);
    Keyboard.release(0x81);
    Keyboard.release('t');
    digitalWrite(ledBlue, LOW);
  }

  if (state == 0) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    delayMicroseconds(50);
    mode = true;
  } else {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    delay(100);
    mode = false;
  }

  if (buttonB == 0){
    digitalWrite(ledBlue, HIGH);
    if (mode == false){
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('1');
      delay(200);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('1');
    } else {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('m');
      delay(200);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('m');
    }
    digitalWrite(ledBlue, LOW);
  } else if (buttonC == 0){
    digitalWrite(ledBlue, HIGH);
    if (mode == false){
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('2');
      delay(200);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('2');
    } else {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('b');
      delay(200);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('b');
    }
    digitalWrite(ledBlue, LOW);
  }
}
