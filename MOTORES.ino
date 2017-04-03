//Motor derecho
int h_IN1 = 6; 
int h_IN2 = 5; 

//Motor izquierdo
int h_IN3 = 4; 
int h_IN4 = 3; 

void setup() {
  pinMode(h_IN1, OUTPUT);
  pinMode(h_IN2, OUTPUT);
  pinMode(h_IN3, OUTPUT);
  pinMode(h_IN4, OUTPUT);
}

void loop() {
  adelante();
  delay(800);
  atras();
  delay(800);
  //girarIzquierda();
  //delay(3000);
  //girarDerecha();
  //delay(3000);
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
