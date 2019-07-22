int led1 = 12;
int led2 = 11;
int push1 = 3;
int push2 = 2;

int state1 = false;
int state2 = false;

long elapsed = 0;
bool polling = false;
bool displaying = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(push1, INPUT);
  pinMode(push2, INPUT);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  if (polling) {
    if (millis() - elapsed > 100) {
      polling = false;
      displaying = true;
    } else
      evalPush();
  } else if (displaying) {
      if (state1)
        digitalWrite(led1, HIGH);
      if (state2)
        digitalWrite(led2, HIGH);
      delay(500);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      delay(50);
      state1 = false;
      state2 = false;
      displaying = false;
  } else {
    if (evalPush()) {
      elapsed = millis();
      polling = true;
    } else
      delay(10);
  }
}

boolean evalPush() {
  if (digitalRead(push1) == HIGH)
    state1 = true;
  if (digitalRead(push2) == HIGH)
    state2 = true;
  return state1 or state2;
}

