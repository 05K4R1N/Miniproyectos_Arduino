
#include <LiquidCrystal.h>

#define sensor_temperatura A0
#define LED_INTERNO 7

#define ROJO 8
#define AMARILLO 9
#define VERDE 10
//                rs  e  d4  d5 d6 d7 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float temperatura=0;
float aux=0;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,4);
  pinMode(sensor_temperatura,INPUT);
  pinMode(LED_INTERNO,OUTPUT);
  pinMode(ROJO,OUTPUT);
  pinMode(AMARILLO,OUTPUT);
  pinMode(VERDE,OUTPUT);
}

void loop()
{
  digitalWrite(LED_INTERNO,HIGH);
  lcd.print("05K4R1N");
  //lcd.setCursor(0,1);
  temperatura=analogRead(sensor_temperatura);
  aux=(temperatura*5*100)/1024;
  lcd.setCursor(0,1);
  lcd.print("TEMP: ");
  lcd.print(aux);
  lcd.print(" C");
  lcd.setCursor(0,2);

  bandera_leds(aux);
  delay(500);
  lcd.clear(); 
}

void bandera_leds(float auxiliar){
  if(auxiliar<=25){
    digitalWrite(VERDE,HIGH);
    digitalWrite(AMARILLO,LOW);
    digitalWrite(ROJO,LOW);
    lcd.print("BAJO");
  }
  if(auxiliar>25 && auxiliar<=40){
    digitalWrite(AMARILLO,HIGH);
    digitalWrite(ROJO,LOW);
    digitalWrite(VERDE,LOW);
    lcd.print("MEDIO");
  }
  if(auxiliar>40){
    digitalWrite(ROJO,HIGH);
    digitalWrite(VERDE,LOW);
    digitalWrite(AMARILLO,LOW);
    lcd.print("ALTO");
  }
}



