int led_pins[7]={2,12,4,5,6,7,8};

int valor_caras[7][7]={ {0,0,0,0,0,0,1},
                  {0,0,0,0,0,1,1},
                  {0,0,0,0,1,1,1},
                  {0,0,0,1,1,1,1},
                  {0,0,1,1,1,1,1},
                  {0,1,1,1,1,1,1},
                  {0,0,0,0,0,0,0} };
                  
int boton=9;
int todo_apagado=6;

void setup(){
  for(int i=0;i<7;i++){
    pinMode(led_pins[i],OUTPUT);
    digitalWrite(led_pins[i],LOW);
  }
  randomSeed(analogRead(0)); //evita repetir mismas secuencias
}

void loop(){
  if(digitalRead(boton)){
    lanzarDado();
  }
  delay(100);
}
void lanzarDado(){
  int res;
  int girando_dado=random(20,30);
  for(int i=0;i<girando_dado;i++){
    res=random(0,6);
    mostrar(res);
    delay(70+i*19);
  }
  for(int j=0;j<3;j++){
    mostrar(todo_apagado);
    delay(500);
    mostrar(res);
    delay(500);
  }
}
void mostrar(int resultado){
  for(int i=0;i<7;i++){
    digitalWrite(led_pins[i],valor_caras[resultado][i]);
  }
}
