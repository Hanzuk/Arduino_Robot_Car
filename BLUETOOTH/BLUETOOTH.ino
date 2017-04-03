//Motor derecho
int h_IN1 = 10; 
int h_IN2 = 6;
//Motor izquierdo
int h_IN3 = 5; 
int h_IN4 = 3;
char estado = 'S';

void setup() {
  Serial.begin(9600);
  pinMode(h_IN1, OUTPUT);
  pinMode(h_IN2, OUTPUT);
  pinMode(h_IN3, OUTPUT);
  pinMode(h_IN4, OUTPUT);
}

void loop() {
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
