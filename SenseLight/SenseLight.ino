int sensorPin = 7;
int lightValue = 0;

int lightLevel = HIGH;
int lowTresh = 3;
int highTresh = 4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(sensorPin);
  Serial.println(lightValue);
}

boolean darkened() {
  if (lightLevel == HIGH and lightValue < lowTresh) {
    lightLevel = LOW;
    return true;
  }
  
  return false;
}

boolean lightened() {
  if (lightLevel == LOW and lightValue > highTresh) {
    lightLevel = HIGH;
    return true;
  }
  
  return false;
}

/* TODO make the system respont to light level */
