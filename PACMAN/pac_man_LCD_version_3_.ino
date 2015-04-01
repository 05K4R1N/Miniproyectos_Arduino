#include <LiquidCrystal.h>

#define LED_INTERNO_LCD 7

int   y_comida=0;
int   b=1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte pacman1[8]={B00000,
                B01110,
                B10110,
                B11100,
                B11000,
                B01110,
                B01110,
                B00000};
byte pacman2[8]={B00000,
                B01110,
                B11111,
                B10111,
                B11111,
                B11111,
                B01110,
                B00000};
byte comida[8]={B00000,
                B00000,
                B00100,
                B01110,
                B11111,
                B01110,
                B00100,
                B00000};

void setup(){
  lcd.createChar(1,pacman1);
  lcd.createChar(2,pacman2);
  lcd.createChar(3,comida);
  lcd.begin(16,4);
  pinMode(LED_INTERNO_LCD,OUTPUT);
  digitalWrite(LED_INTERNO_LCD,HIGH);
  Serial.begin(9600);
}
void loop(){
  prepararCampo();
  while(b==1){
    recorrer_pacman();
    b=0;
  }
  lcd.setCursor(0,2);
  lcd.print("SIMULACION");
  lcd.setCursor(0,3);
  lcd.print("TERMINADA");
}
void recorrer_pacman(){
  int pos_x=0;
  int pos_y=0;
  while(pos_x>=0 || pos_x<=16){
    lcd.setCursor(pos_x,pos_y);
    pacman_animado(pos_x);
    lcd.setCursor(pos_x,pos_y);
    delay(250);
    lcd.print(" ");
    pos_x++;
    if(pos_x==16){
      pos_x=0;
      pos_y++;
    }
    if(pos_y==4){
      pos_x=17;
      break;
    }
  }
}
void pacman_animado(int x){
  if(x%2==0){
    lcd.write(1);
  }else{
    lcd.write(2);
  }
}
void prepararCampo(){
  for(;y_comida<4;y_comida++){
    for(int x_comida=0;x_comida<16;x_comida++){
      lcd.setCursor(x_comida,y_comida);
      lcd.write(3);
      delay(25);
    }
  }
}
  
