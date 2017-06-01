// OBS HotKeys arduino keyboard v1.5.2
// Made by OsirisFrik
// Twitter & Twitch OsirisFrik
// Git https://github.com/OsirisFrik/OBS_HotKey_Arduino

#include <Keyboard.h>

const int key1 = 4;
const int led1 = 3;
const int key2 = 2;
const int led2 = 5;
const int key3 = 6;
const int led3 = 7;
const int key4 = 8;
const int led4 = 11;
const int key5 = 10;
const int led5 = 9;

const int led = 12;

int air = false;
int mode = false;

int press1 = 0;
int press2 = 0;
int press3 = 0;
int press4 = 0;
int press5 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);
  pinMode(key4, INPUT_PULLUP);
  pinMode(key5, INPUT_PULLUP);

  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  press1 = digitalRead(key1);
  press2 = digitalRead(key2);
  press3 = digitalRead(key3);
  press4 = digitalRead(key4);
  press5 = digitalRead(key5);
  
  if(press1 == 0){
    if(air == false) {
      air = true;
      digitalWrite(led1, HIGH);
    } else {
      air = false;
      digitalWrite(led1, LOW);
    }
    Keyboard.press(0x80);
    Keyboard.press(0x81);
    Keyboard.press('t');    
    delay(120);
    Keyboard.release(0x80);
    Keyboard.release(0x81);
    Keyboard.release('t');
  }

  if(press2 == 0) {
    if(mode == false) {
      mode = true;
      digitalWrite(led2, HIGH);
    } else {
      mode = false;
      digitalWrite(led2, LOW);
    }
    delay(120);
  }

  if(press3 == 0) {
    digitalWrite(led3, HIGH);
    if(mode == false) {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('1');
      delay(120);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('1');
    } else {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('m');
      delay(120);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('m');
    }
    digitalWrite(led3, LOW);
  }

  if(press4 == 0) {
    digitalWrite(led4, HIGH);
    if(mode == false) {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('2');
      delay(120);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('2');
    } else {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('g');
      delay(120);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('g');
    }
    digitalWrite(led4, LOW);
  }
  
  if(press5 == 0) {
    digitalWrite(led5, HIGH);
    if(mode == false) {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('3');
      delay(120);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('3');
    } else {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('u');
      delay(120);
      Keyboard.release(0x80);
      Keyboard.release(0x81);
      Keyboard.release('u');
    }
    digitalWrite(led5, LOW);
  }
}
