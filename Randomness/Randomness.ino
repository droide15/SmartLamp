void setup() {
  Serial.begin(9600);
  
  int seed = analogRead(A0);
  randomSeed(seed);
  
  Serial.println("-------");
  Serial.print("seed: ");
  Serial.println(seed);
  Serial.println("-------");
}

void loop() {
  int highSpan = random(23, 37);
  if (random(1, 10) > 3) {
    highSpan += 10;
  }
  int lowSpan = random(3, 17);
  if (random(1, 10) > 3) {
    lowSpan += 10;
  }
  
  Serial.print("turns HIGH for ");
  Serial.print(highSpan);
  Serial.println(" minutes");
  Serial.print("turns LOW for ");
  Serial.print(lowSpan);
  Serial.println(" minutes");
  delay(5000);
  Serial.println("-------");
}
