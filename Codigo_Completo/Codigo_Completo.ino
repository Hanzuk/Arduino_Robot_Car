/*
--Variables para el motor--
  >> H_IN1 y H_IN2 para el motor derecho
  >> H_IN3 y H_IN4 para el motor izquierdo
*/
int H_IN1 = 6; 
int H_IN2 = 5;
int H_IN3 = 4; 
int H_IN4 = 3;

/*--Variables para el sensor--*/
long distancia, tiempo;
int diodo = 13;

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
  adelante();
  sensor();
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

void sensor(){
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
    delay(1000);
    if(distancia <= 30){
      girarIzquierda();
      delay(2000);
      if(distancia <= 30){
        girarIzquierda();
        delay(1000);
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

  delay(200);
}