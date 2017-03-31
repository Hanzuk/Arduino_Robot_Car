//Motor derecho
int H_IN1 = 6; 
int H_IN2 = 5; 
//int H_ENABLE_A = 7; //Para el motor derecho

//Motor izquierdo
int H_IN3 = 4; 
int H_IN4 = 3; 
//int H_ENABLE_B = 2; //Para el motor izquierdo

void setup() {
  pinMode(H_IN1, OUTPUT);
  pinMode(H_IN2, OUTPUT);
  pinMode(H_IN3, OUTPUT);
  pinMode(H_IN4, OUTPUT);
  //pinMode(H_ENABLE_A, OUTPUT);
  //pinMode(H_ENABLE_B, OUTPUT);
}

void loop() {
  //digitalWrite(H_ENABLE_A, HIGH);
  //digitalWrite(H_ENABLE_B, HIGH);
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
