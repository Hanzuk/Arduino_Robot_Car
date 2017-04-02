/*
--Variables para el motor--
  >> H_IN1 y H_IN2 para el motor derecho
  >> H_IN3 y H_IN4 para el motor izquierdo
*/
int H_IN1 = 10; 
int H_IN2 = 6;
int H_IN3 = 5; 
int H_IN4 = 3;

/*--Variables para el sensor--*/
long distancia, tiempo;
int diodo = 13;

//Variable para el Bluetooth
int estado = 'S';

void setup() {
  Serial.begin(9600);
  pinMode(H_IN1, OUTPUT);
  pinMode(H_IN2, OUTPUT);
  pinMode(H_IN3, OUTPUT);
  pinMode(H_IN4, OUTPUT);
  pinMode(8, OUTPUT); //Trigger
  pinMode(9, INPUT); //Echo
  pinMode(diodo, OUTPUT);
}

void loop() {
  bluetooth();
  //adelante();
  //automatico();
}

void adelante(){ 
  digitalWrite(H_IN1, LOW);
  digitalWrite(H_IN2, HIGH);
  digitalWrite(H_IN3, HIGH);
  digitalWrite(H_IN4, LOW);
}
  
void atras(){
  digitalWrite(H_IN1, HIGH);
  digitalWrite(H_IN2, LOW);
  digitalWrite(H_IN3, LOW);
  digitalWrite(H_IN4, HIGH);
} 
    
void girarIzquierda(){
  digitalWrite(H_IN1, LOW);
  digitalWrite(H_IN2, HIGH);
  digitalWrite(H_IN3, HIGH);
  digitalWrite(H_IN4, LOW);
}

void girarDerecha(){
  digitalWrite(H_IN1, HIGH);
  digitalWrite(H_IN2, LOW);
  digitalWrite(H_IN3, LOW);
  digitalWrite(H_IN4, HIGH);
}

void parar(){
  digitalWrite(H_IN1, LOW);
  digitalWrite(H_IN2, LOW);
  digitalWrite(H_IN3, LOW);
  digitalWrite(H_IN4, LOW);
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
    delay(800);
    if(distancia <= 30){
      girarIzquierda();
      delay(1200);
      if(distancia <= 30){
        girarIzquierda();
        delay(800);
        adelante();
      }else{
        adelante();
      }
    }else{
      adelante();
    }
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
}