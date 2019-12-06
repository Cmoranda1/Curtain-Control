#define rf 7
int state = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rf, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(rf) == true){
    delay(500);
    state += 1;
    Serial.print("State is \n");
    Serial.println(state);
  }
}
