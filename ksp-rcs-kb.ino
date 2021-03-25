#include "Adafruit_Keypad.h"
#include <Keyboard.h>

const byte ROWS = 3; // rows
const byte COLS = 3; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'j','i','l'},
  {'n','k','h'},
  {'x','r','x'}
};
byte rowPins[ROWS] = {6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  customKeypad.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    
    if(e.bit.EVENT == KEY_JUST_PRESSED) Keyboard.press((char)e.bit.KEY);
    else if(e.bit.EVENT == KEY_JUST_RELEASED) Keyboard.release((char)e.bit.KEY);
  }

  delay(10);
}
