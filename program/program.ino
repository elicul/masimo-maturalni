const int btn1 = 13;   
const int btn2 = 12;   
const int btn3 = 11;   
const int btn4 = 10;
const int interruptBtn = 2;
unsigned long interrupt_time = 0;
unsigned long last_interrupt_time = millis();

const int led1 = 7;   
const int led2 = 6;   
const int led3 = 5;   
const int led4 = 4;

const int pump = 3;
// Program Modes: 1 - manual, 2 - automatic
int mode = 1;

void setup() {
  Serial.begin(9600);
  
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

  digitalWrite(btn1, HIGH);
  digitalWrite(btn2, HIGH);
  digitalWrite(btn3, HIGH);
  digitalWrite(btn4, HIGH);
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
  interrupt_time = millis();
  // If interrupts come faster than 500ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 500) {
    if(mode == 1) {
      digitalWrite(btn1, LOW); 
      digitalWrite(btn2, LOW); 
      digitalWrite(btn3, LOW); 
      digitalWrite(btn4, LOW);
      mode = 2;
      Serial.println("Changing to automatic mode!");
    } else {
      digitalWrite(btn1, HIGH);
      digitalWrite(btn2, HIGH);
      digitalWrite(btn3, HIGH);
      digitalWrite(btn4, HIGH);
      digitalWrite(led1, LOW); 
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW); 
      digitalWrite(led4, LOW);
      mode = 1;
      Serial.println("Changing to manual mode!");
    } 
  }
  last_interrupt_time = interrupt_time;
}
