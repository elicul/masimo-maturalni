const int btn1 = 13;   
const int btn2 = 12;   
const int btn3 = 11;   
const int btn4 = 10;
const int interruptBtn = 2;

const int led1 = 7;   
const int led2 = 6;   
const int led3 = 5;   
const int led4 = 4;

const int pump = 3;
// Program Modes: 1 - automatic, 2 - manual
int mode = 1;

void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(interruptBtn, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptBtn), interruptMethod, CHANGE);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(pump, OUTPUT);
}

void loop() {

  if(mode == 1) {
    if(digitalRead(btn1) == LOW)
      digitalWrite(led1, HIGH);
    else
      digitalWrite(led1, LOW);
    
    if(digitalRead(btn2) == LOW)
      digitalWrite(led2, HIGH);
    else
      digitalWrite(led2, LOW);

    if(digitalRead(btn3) == LOW)
      digitalWrite(led3, HIGH);
    else
      digitalWrite(led3, LOW);

    if(digitalRead(btn4) == LOW)
      digitalWrite(led4, HIGH);
    else
      digitalWrite(led4, LOW);
  } else {
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
    digitalWrite(led4, LOW); 
    delay(1000); 
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH); 
    digitalWrite(led3, HIGH); 
    digitalWrite(led4, HIGH); 
    delay(100); 
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
    digitalWrite(led4, LOW);
  }
}

void interruptMethod() {
  if(mode == 1)
    mode = 2;
  else 
    mode = 1;
}
