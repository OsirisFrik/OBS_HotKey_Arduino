// OBS HotKeys arduino keyboard v1.4
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

int state = 0;
int onAir = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchA, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(switchA);
  buttonA = digitalRead(3);
  buttonB = digitalRead(4);
  buttonC = digitalRead(5);

  if (buttonC == 0){
    //Keyboard.press(0x80);
    Keyboard.press(0x80);
    Keyboard.press(0x81);
    Keyboard.press('t');
    delay(100);
    Keyboard.releaseAll();
    if (onAir == 1){
      onAir = 0;
    } else {
      onAir = 1;
    }
  }
  
  if (state == 0){
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
    if (buttonA == 0){ 
      Keyboard.press(0x80);     
      Keyboard.press(0x81);
      Keyboard.press('m'); // "M"
      delay(100); // Delay 100 ms
      Keyboard.releaseAll(); // unpress all keys
    } else if (buttonB ==0) {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('b'); // Num 1
      delay(100); // Delay 100 ms
      Keyboard.releaseAll(); // unpress all keys
    }
    delay(100);
  } else {
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
    if (buttonA == 0){ 
      Keyboard.press(0x80);
      Keyboard.press(0x81);     
      Keyboard.press('1'); // Num 1
      delay(100); // Delay 100 ms
      Keyboard.releaseAll(); // unpress all keys
    } else if (buttonB == 0) {
      Keyboard.press(0x80);
      Keyboard.press(0x81);
      Keyboard.press('2'); // Num 2
      delay(50); // Delay 100 ms
      Keyboard.releaseAll(); // unpress all keys
    }
    delay(100);
  }

  if (onAir != 0){
    digitalWrite(ledRed, LOW);
    delay(100);
  } else {
    digitalWrite(ledRed, HIGH);
  }
}
