#define MenuAccessKey '#'         //key used to access configuration menu

#include <LiquidCrystal.h>        //linking lcd library
#include <Keypad.h>               //linking keypad library

LiquidCrystal lcd(53,52,51,50,49,48); //declaration of pin layout for lcd ( LiquidCrystal lcd(rs, enable, d4, d5, d6, d7) ) 

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
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols ); //defining custom keypad

void setup() {
lcd.begin(16,2);    //preparation of lcd screen
lcd.clear();        //preparation of lcd screen
Serial.begin(9600); //temporary for tests/debugging 
Welcome();          //completelly useless piece of code, but it looks more professional :D
MenuInfo();         //informing user which key should they press to access caonfiguration menu
Menu1();            //main layout of values menu
}

void loop() {
//almost all from loop(); will be moved to another function... i think
//i need to test communication between functions
for(int c=0; c<=200; c++){
char key=keypad.getKey();
if(c%8==0){
lcd.setCursor(12,0);
lcd.print(analogRead(A0)*0.0049);
Serial.print("Contrast Voltage: ");     //temporary for tests/debugging 
Serial.println(analogRead(A0)*0.0049);  //temporary for tests/debugging 
lcd.setCursor(12,1);
lcd.print(analogRead(A1)*0.0049);   
Serial.print("Light Voltage: ");        //temporary for tests/debugging 
Serial.println(analogRead(A1)*0.0049);  //temporary for tests/debugging 
}
delay(50);
// if correct key is pressed, program moves to login menu
if (key==MenuAccessKey)
MenuLogin();
}
MenuInfo();
}

//useless little welcoming-thing; it makes this shitty code look like a pro software :D
void Welcome(){
lcd.clear();
lcd.setCursor(5,0);
lcd.print("Welcome");
lcd.setCursor(1,1);
lcd.print("please wait...");
delay(1500);
lcd.clear();
}

// function for main menu, so it's only rendered once per x seconds (not so often like values)
void Menu1(){
lcd.clear();
lcd.print("LightVol: ");
lcd.setCursor(0,1);
lcd.print("ContrastVol: ");
 }

// function, which pops up to inform the user which key should they press to access menu
void MenuInfo(){
lcd.clear();
lcd.print("Press ");
lcd.print(MenuAccessKey);
lcd.print(" for menu");
lcd.setCursor(5,1);
lcd.print("access");

// loop to get menu-key press and to delay going to next function
for (int i=0;i<=25;i++){
char key=keypad.getKey();
delay(50);

// if correct key is pressed, program moves to login menu
if (key==MenuAccessKey)MenuLogin();
}
Menu1();
}

// function used to login into control panel
//to do
//control panel menu
//change a litte bit wrong-pin menu
//maybe move pin declaration to top
void MenuLogin(){
 lcd.clear();
 lcd.print("Time left: ");
 lcd.setCursor(0,1);
 lcd.print("PIN: ");
 int numbers=0;                 //how many numbers program already has from user
 int Tburned=0;                 //burned time(used for countdown)
 char keycl[4];                 //declaration fo saving clicked keys
 char pin[4]={'5','1','3','9'}; //declared PIN
 
for(int t=0; t<=150; t++){
  char key=keypad.getKey();
  // Printing and saving in memory keys we get
     if (key){                      // 
       lcd.setCursor(5+numbers,1);  // moving cursor to next number
       lcd.print(key);              // printing pressed key on lcd
       keycl[numbers]=key;          // declaring pressed keys in memory
       numbers++;                   // incrementation of #nr key pressed
       }                            //
 delay(100);                        // 100ms delay for easier math(could be every number, but you also need to change another numbers in loop to save real time pass)

 //checking if clicked keys==declared pin
 if(numbers==4){
  delay(400);                       //little delay for better immersion (menu doesn't change immediately when 4th key is pressed)
  
  int PosT=0;                      
  for (int k=0; k<4; k++){
   if(keycl[k]==pin[k])PosT++;
  }
   if (PosT==4){
    lcd.clear();
    lcd.print("asdasd");
    delay(1000);
    setup();
    break;
    }
    else{
      lcd.clear();
      lcd.print("Wrong PIN!");
      delay(2000);
      Menu1();
      break;
      }
  }
  
   if(t%10==0){
   int TLeft=15-Tburned;
   lcd.setCursor(11,0);
   lcd.print("    ");
   lcd.setCursor(11,0);
   lcd.print(TLeft); 
   lcd.print("s");
   Tburned++;
   }
 }
}


