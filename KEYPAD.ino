#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); //LCD 16x02, địa chỉ I2C là 0X27

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
char SP1[2]={'0','1'};
char SP2[2]={'0','2'};
char SP3[2]={'0','3'};
char SP4[2]={'0','4'};
char SP5[2]={'0','5'};
char SP6[2]={'0','6'};
char SP7[2]={'0','7'};
char SP8[2]={'0','8'};
char SP9[2]={'0','9'};
char SP10[2]={'1','0'};
int i;
char key=00;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  lcd.init(); //Khởi động LCD
  lcd.backlight(); //Bật đèn nền
  lcd.clear();

  lcd.setCursor(0,0); //Cột 0, hàng 0
  lcd.print("TSP:"); 
}
  
void loop(){
  char key = keypad.getKey();// Read the key

  // Nhập số sản phẩm
  for(i=0;i<2;i++){
    Serial.print("SSP: ");
    if(i==0){
      SP1[0] = key;
      lcd.setCursor(5,1);
      lcd.print(SP1[0]);
      Serial.println(SP1[0]);
    }
    if(i==1){
      SP1[1] = key;
      lcd.setCursor(6,1);
      lcd.print(SP1[1]);
      Serial.println(SP1[1]);
    }
}
}
//  if (key){
//    Serial.print("Key Pressed : ");
//    Serial.println(key);
