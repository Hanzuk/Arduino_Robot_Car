/*
--Variables para el motor--
  >> H_IN1 y H_IN2 para el motor derecho
  >> H_IN3 y H_IN4 para el motor izquierdo
*/
int h_IN1 = 10; 
int h_IN2 = 6;
int h_IN3 = 5; 
int h_IN4 = 3;

/*--Variables para el sensor--*/
long distancia, tiempo;
int diodo = 13;
int trigger = 8;
int echo = 9;

/*Variable para el Bluetooth*/
char estado = 'S';

void setup(){
  Serial.begin(9600);
  pinMode(h_IN1, OUTPUT);
  pinMode(h_IN2, OUTPUT);
  pinMode(h_IN3, OUTPUT);
  pinMode(h_IN4, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(diodo, OUTPUT);
}

void loop(){
  bluetooth();
  //adelante();
  //automatico();
}

void adelante(){ 
  digitalWrite(h_IN1, LOW);
  digitalWrite(h_IN2, HIGH);
  digitalWrite(h_IN3, HIGH);
  digitalWrite(h_IN4, LOW);
}
  
void atras(){
  digitalWrite(h_IN1, HIGH);
  digitalWrite(h_IN2, LOW);
  digitalWrite(h_IN3, LOW);
  digitalWrite(h_IN4, HIGH);
} 
    
void girarIzquierda(){
  digitalWrite(h_IN1, LOW);
  digitalWrite(h_IN2, HIGH);
  digitalWrite(h_IN3, LOW);
  digitalWrite(h_IN4, LOW);
}

void girarDerecha(){
  digitalWrite(h_IN1, LOW);
  digitalWrite(h_IN2, LOW);
  digitalWrite(h_IN3, HIGH);
  digitalWrite(h_IN4, LOW);
}

void parar(){
  digitalWrite(h_IN1, LOW);
  digitalWrite(h_IN2, LOW);
  digitalWrite(h_IN3, LOW);
  digitalWrite(h_IN4, LOW);
}

void automatico(){
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);

  tiempo = pulseIn(9, HIGH);
  distancia = (tiempo/2)/29; //Formula para la distancia en centimetros

  if(distancia <= 30){
    parar();
    delay(1000);
    girarDerecha();
    delay(1296);
    /*if(distancia <= 30){
      girarIzquierda();
      delay(1000);
      if(distancia <= 30){
        girarIzquierda();
        delay(800);
        adelante();
      }else{
        adelante();
      }
    }else{
      adelante();
    }*/
  }else{
    adelante();
  }

  delay(180);
}

void bluetooth(){
  if(Serial.available() > 0){
    estado = Serial.read();
  }

  if(estado == 'A'){
    adelante();
  }

  if(estado == 'R'){
    atras();
  }

  if(estado == 'I'){
    girarIzquierda();
  }

  if(estado == 'D'){
    girarDerecha();
  }

  if(estado == 'S'){
    parar();
  }

  if(estado == '1'){
    parar();
    delay(1000);
    automatico();
  }
}
