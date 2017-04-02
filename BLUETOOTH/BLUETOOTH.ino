int H_IN1 = 10; 
int H_IN2 = 6;
int H_IN3 = 5; 
int H_IN4 = 3;
int estado = 'S';

void setup() {
  Serial.begin(9600);
  pinMode(H_IN1, OUTPUT);
  pinMode(H_IN2, OUTPUT);
  pinMode(H_IN3, OUTPUT);
  pinMode(H_IN4, OUTPUT);
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