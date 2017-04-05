int h_IN1 = 10; 
int h_IN2 = 6;
int h_IN3 = 5; 
int h_IN4 = 3;

int diodo = 13;
int trigger = 8;
int echo = 9;
long distancia, tiempo;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT); //Trigger
  pinMode(echo, INPUT); //Echo
  pinMode(diodo, OUTPUT);
}

void loop() {
  //digitalWrite(diodo, HIGH); //Diodo
  automatico();
}

void automatico(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);

  tiempo = pulseIn(echo, HIGH);
  distancia = (tiempo/2)/29; //Formula para la distancia en centimetros
  delay(10);

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
  delay(180);
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
