#include <LiquidCrystal.h> 
#include <Keypad.h>

LiquidCrystal lcd(53,52,51,50,49,48);

const byte rows = 4; //four rows
const byte cols = 4; //four columns
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
byte rowPins[rows] = {22,24,26,28}; //connect to the row pinouts of the keypad
byte colPins[cols] = {23,25,27,29}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

int cykl=1;

void setup() {
lcd.begin(16,2);
lcd.clear();
Serial.begin(9600);
Welcome();
Menu1();
MenuLogin();
}

void loop() {
lcd.setCursor(12,0);
lcd.print(analogRead(A0)*0.0049);
delay(100);
lcd.setCursor(12,1);
lcd.print(analogRead(A1)*0.0049);
delay(100);
cykl++;
if(cykl==25){
  cykl=1;
  MenuLogin();
  }
}

void Welcome(){
lcd.clear();
lcd.setCursor(5,0);
lcd.print("Welcome");
lcd.setCursor(1,1);
lcd.print("please wait...");
delay(1500);
lcd.clear();
}

void Menu1(){
lcd.clear();
lcd.print("LightVol: ");
lcd.setCursor(0,1);
lcd.print("ContrastVol: ");
 }

void MenuLogin(){
lcd.clear();
lcd.print("Press D for menu");
lcd.setCursor(5,1);
lcd.print("access");
delay(2000);
Menu1();
loop();
}

