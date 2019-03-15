// Pin initialization
const int interruptBtn = 2;
const int increaseTimeBtn = 3;
const int dencreaseTimeBtn = 4;
const int injectorPowerBtn = 5;

const int led = 13;   

unsigned long interruptTime = 0;
unsigned long lastInterruptTime = millis();

// Program Modes: 1 - manual, 2 - automatic
int programMode = 1;

void setup() {
  Serial.begin(9600);
  
  pinMode(injectorPowerBtn, INPUT);
  pinMode(increaseTimeBtn, INPUT);
  pinMode(dencreaseTimeBtn, INPUT);
  pinMode(interruptBtn, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptBtn), interruptMethod, CHANGE);
  
  pinMode(led, OUTPUT);

  digitalWrite(injectorPowerBtn, HIGH);
  digitalWrite(increaseTimeBtn, HIGH);
  digitalWrite(dencreaseTimeBtn, HIGH);
}

void loop() {
  
  if(programMode == 1) {
    if(digitalRead(injectorPowerBtn) == LOW)
      digitalWrite(led, HIGH);
    else
      digitalWrite(led, LOW);
  } else {
    digitalWrite(led, LOW); 
    delay(1000); 
    digitalWrite(led, HIGH); 
    delay(100); 
    digitalWrite(led, LOW); 
  }
}

void interruptMethod() {
  interruptTime = millis();
  // If interrupts come faster than 500ms, assume it's a bounce and ignore
  if (interruptTime - lastInterruptTime > 500) {
    if(programMode == 1) {
      digitalWrite(injectorPowerBtn, LOW); 
      digitalWrite(increaseTimeBtn, LOW); 
      digitalWrite(dencreaseTimeBtn, LOW); 
      programMode = 2;
      Serial.println("Changing to automatic mode!");
    } else {
      digitalWrite(injectorPowerBtn, HIGH);
      digitalWrite(increaseTimeBtn, LOW); 
      digitalWrite(dencreaseTimeBtn, LOW);
      digitalWrite(led, LOW); 
      programMode = 1;
      Serial.println("Changing to manual mode!");
    } 
  }
  lastInterruptTime = interruptTime;
}
