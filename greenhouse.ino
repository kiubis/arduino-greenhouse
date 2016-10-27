#include <LiquidCrystal.h> 
#include <Keypad.h>

LiquidCrystal lcd(53,52,51,50,49,48);

const byte rows = 4; //four rows
const byte cols = 3; //three columns
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[rows] = {22,24,26,28}; //connect to the row pinouts of the keypad
byte colPins[cols] = {23,25,27,29}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("Hello world!");

}

void loop() {
  // put your main code here, to run repeatedly:
  

}
