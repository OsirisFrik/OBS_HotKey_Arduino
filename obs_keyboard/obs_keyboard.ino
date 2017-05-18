// OBS HotKeys arduino keyboard
// Made by OsirisFrik
// Twitter & Twitch OsirisFrik
// Git https://github.com/OsirisFrik/OBS_HotKey_Arduino

#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Keyboard.begin();
  if (digitalRead (3) == 0){
    Keyboard.press(0x80); // Left Ctrl
    Keyboard.press('1'); // Num 1
    delay(100); // Delay 100 ms
    Keyboard.releaseAll(); // unpress all keys
  }
  else if (digitalRead (4) == 0){
    Keyboard.press(0x80); // Left Ctrl
    Keyboard.press('2'); // Num 1
    delay(100); // Delay 100 ms
    Keyboard.releaseAll(); // unpress all keys
  }
}
