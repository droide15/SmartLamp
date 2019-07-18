int led1 = 12;
int led2 = 11;
int push1 = 3;
int push2 = 2;

int state1 = 0;
int state2 = 0;

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
    if (millis() - elapsed > 250) {
      polling = false;
      displaying = true;
    } else {
      if (digitalRead(push1) == HIGH)
        state1 = 1;
      if (digitalRead(push2) == HIGH)
        state2 = 1;
    }
  } else if (displaying) {
      if (state1 == 1)
        digitalWrite(led1, HIGH);
      if (state2 == 1)
        digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      delay(1000);
      state1 = 0;
      state2 = 0;
      displaying = false;
  } else {
    if (digitalRead(push1) == HIGH)
      state1 = 1;
    if (digitalRead(push2) == HIGH)
      state2 = 1;
    if (state1 == 1 or state2 == 1) {
      elapsed = millis();
      polling = true;
    } else
      delay(50);
  }
}
