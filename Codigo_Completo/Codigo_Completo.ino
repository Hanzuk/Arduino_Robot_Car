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
int trigger = 8;
int echo = 9;

/*Variable para el Bluetooth*/
char estado = 'S';

/*Variables para los leds*/
int diodoWhite = 12;
//int diodoRed = ?;

void setup(){
  Serial.begin(9600);
  pinMode(h_IN1, OUTPUT);
  pinMode(h_IN2, OUTPUT);
  pinMode(h_IN3, OUTPUT);
  pinMode(h_IN4, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  //pinMode(diodoRed, OUTPUT);
  pinMode(diodoWhite, OUTPUT);
}

void loop(){
  bluetooth();
}

void adelante(){ 
  digitalWrite(h_IN1, LOW);
  digitalWrite(h_IN2, HIGH);
  digitalWrite(h_IN3, HIGH);
  digitalWrite(h_IN4, LOW);
  //digitalWrite(diodoRed, LOW);
}
  
void atras(){
  digitalWrite(h_IN1, HIGH);
  digitalWrite(h_IN2, LOW);
  digitalWrite(h_IN3, LOW);
  digitalWrite(h_IN4, HIGH);
  //digitalWrite(diodoRed, LOW);
} 
    
void girarIzquierda(){
  digitalWrite(h_IN1, LOW);
  digitalWrite(h_IN2, HIGH);
  digitalWrite(h_IN3, LOW);
  digitalWrite(h_IN4, LOW);
  //digitalWrite(diodoRed, LOW);
}

void girarDerecha(){
  digitalWrite(h_IN1, LOW);
  digitalWrite(h_IN2, LOW);
  digitalWrite(h_IN3, HIGH);
  digitalWrite(h_IN4, LOW);
  //digitalWrite(diodoRed, LOW);
}

void parar(){
  digitalWrite(h_IN1, LOW);
  digitalWrite(h_IN2, LOW);
  digitalWrite(h_IN3, LOW);
  digitalWrite(h_IN4, LOW);
  //digitalWrite(diodoRed, HIGH);
}

void automatico(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(6);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  tiempo = pulseIn(echo, HIGH);
  distancia = (tiempo/2)/29; //Formula para la distancia en centimetros

  if(distancia <= 50 && distancia >= 2){
    parar();
    delay(1000);
    atras();
    delay(700);
    girarDerecha();
    delay(780);
    parar();
    delay(1000);
  }else{
    adelante();
  }
  delay(300);
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
    automatico();
  }
  if(estado == '2'){
    digitalWrite(diodoWhite, HIGH);
  }
  if(estado == '3'){
    digitalWrite(diodoWhite, LOW);
  }
}
