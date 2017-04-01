long distancia, tiempo;
int diodo = 13;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT); //Trigger
  pinMode(9, INPUT); //Echo
  pinMode(diodo, OUTPUT);
}

void loop() {
  //digitalWrite(diodo, HIGH); //Diodo
  sensor();
}

void sensor(){
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);

  tiempo = pulseIn(9, HIGH);
  distancia = (tiempo/2)/29;

  if(distancia >= 500 || distancia <= 0){
    Serial.println("Error");
  }else{
    Serial.println(distancia);
    Serial.println("cm");
  }

  if(distancia >= 20){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }

  delay(200);
}

