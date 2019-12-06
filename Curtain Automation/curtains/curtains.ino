//states
#define closed 0
#define opening 1
#define part_opened 2
#define closing 3
#define part_closed 4
#define opened 5
//sensors

//receiver for clicker
#define rf 8

//inputs for prox switches
#define prox1 9
#define prox2 7

//output to motor/h-bridge
//#define enA 11
//#define in1 5
//#define in2 6
#define enA A0
#define in1 A1
#define in2 A2
int rotDirection = 0;
int pressed = false;
char c;
int A = 0;
int one = LOW;
int two = LOW;
int state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rf, INPUT);
  pinMode(prox1, INPUT);
  pinMode(prox2, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  analogWrite(enA, A);
  digitalWrite(in1, one);
  digitalWrite(in2, two);
  if(digitalRead(prox1) == true){
    state = closed;
    //analogWrite(enA, 0);
    //digitalWrite(in1, LOW);
    //digitalWrite(in2, LOW);
    A = 0;
    one = LOW;
    two = LOW;
    Serial.println("Curtains Closed\n");
  }
  if(digitalRead(prox2) == true){
    state = opened;
//    analogWrite(enA, 0);
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, LOW);
    A = 0;
    one = LOW;
    two = LOW;
    Serial.println("Curtains Open\n");
  }
  if(digitalRead(rf) == true){
    delay(250);
    if(state == closed){
      state = opening;
//      analogWrite(enA, 255);
//      digitalWrite(in1, LOW);
//      digitalWrite(in2, HIGH);
      A = 255;
      one = LOW;
      two = HIGH;
      Serial.println("Opening");
    }
    else if(state == opening){
      state = part_opened;
//      analogWrite(enA, 0);
//      digitalWrite(in1, LOW);
//      digitalWrite(in2, LOW);
      A = 0;
      one = LOW;
      two = LOW;
      Serial.println("Partly Opened, pausing");
    }
    else if(state == part_opened){
      state = closing;
//      analogWrite(enA, 255);
//      digitalWrite(in1, HIGH);
//      digitalWrite(in2, LOW);
      A = 255;
      one = HIGH;
      two = LOW;
      Serial.println("Closing");
    }
    else if(state == closing){
      state = part_closed;
//      analogWrite(enA, 0);
//      digitalWrite(in1, LOW);
//      digitalWrite(in2, LOW);
      A = 0;
      one = LOW;
      two = LOW;
      Serial.println("Partly Closed, pausing");
    }
    else if(state == part_closed){
      state = opening;
//      analogWrite(enA, 255);
//      digitalWrite(in1, LOW);
//      digitalWrite(in2, HIGH);
      A = 255;
      one = LOW;
      two = HIGH;
      Serial.println("Opening");
    }
    else if(state == opened){
      state = closing;
//      analogWrite(enA, 255);
//      digitalWrite(in1, HIGH);
//      digitalWrite(in2, LOW);
      A = 255;
      one = HIGH;
      two = LOW;
      Serial.println("Closing");
    }
  }
  // put your main code here, to run repeatedly:

}
