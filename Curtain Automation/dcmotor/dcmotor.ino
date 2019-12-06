#define enA A0
#define in1 A1
#define in2 A2

int rotDirection = 0;
int pressed = false;

char c;
int A = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(enA, A);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  c = Serial.read();
  if(c == 's'){
    A = 0;  
  }
}
