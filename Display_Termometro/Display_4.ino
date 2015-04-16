//Author: Gamboa Acho Oscar Rolando
#define lm35 A0

float temperatura=0;
float aux=0;
int unidad,decena;

int pin_segmentos[]={3,4,5,6,7,8,9};   //pins de acuerdo al orden del led display a,b,c,d,e,f,g

int display_Pins[]={11,12};     //unidad decena respectivamente

byte digitos[10][7]={         // digitos del 0 al 9
  {1,1,1,1,1,1,0},//0
  {0,1,1,0,0,0,0},//1
  {1,1,0,1,1,0,1},//2
  {1,1,1,1,0,0,1},//3
  {0,1,1,0,0,1,1},//4
  {1,0,1,1,0,1,1},//5
  {1,0,1,1,1,1,1},//6
  {1,1,1,0,0,0,0},//7
  {1,1,1,1,1,1,1},//8
  {1,1,1,1,0,1,1} //9
};

void setup(){
  pinMode(lm35,INPUT);
  for(int i=0;i<7;i++){
    pinMode(pin_segmentos[i],OUTPUT);
  }
  pinMode(display_Pins[0],OUTPUT);//unidades
  pinMode(display_Pins[1],OUTPUT);//decenas
  Serial.begin(9600);
}
void loop(){
  
  temperatura=analogRead(lm35);
  aux=((temperatura*5*100)/1024)-30;
  unidad=((int)aux%10);
  decena=((int)aux/10);
  Serial.println(aux);
  Serial.print(decena);
  Serial.print(" ");
  Serial.println(unidad);
  valor(unidad,decena);
  //delay(1000);
}
void valor(int num1,int num2){    
  digitalWrite(display_Pins[0],HIGH);
  digitalWrite(display_Pins[1],LOW);
  encender_segmento(num1);
  delay(10);
  
  digitalWrite(display_Pins[0],LOW);
  digitalWrite(display_Pins[1],HIGH);
  encender_segmento(num2);
  delay(10);
  
}
void encender_segmento(int x){ // metodo en el cual en el display se mostrara el numero que se le pase == x
  for(int t=0;t<7;t++){
    digitalWrite(pin_segmentos[t],digitos[x][t]);
  }
  //delay(100);
}
