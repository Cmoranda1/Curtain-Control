#define prox 9
#define prox2 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(prox, INPUT);
  pinMode(prox2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(prox) == true){
    Serial.println("Curtain Closed\n");
  }

  if(digitalRead(prox2) == true){
    Serial.println("Curtain Open\n");
  }

}
