/*
arduino constantly listens to some parameters
the program sends:
^HPeriod:2000,LPeriod:6000$
arduino interprets:
HPeriod=2000
LPeriod=6000
leed turns on by 2000 msecs
led turns off by 6000 msecs
*/

int led = 13;

int HPeriod = 1000;
int LPeriod = 1000;

void setup() {
  Serial.begin(9600);
  digitalWrite(led, LOW);
  Serial.flush();
}

void loop() {
  if (Serial.available()) {
    String params = Serial.readString();
    int ini = params.indexOf('^');
    int fin = params.indexOf('$', ini+1);
    
    if (ini > -1 and fin > -1) {
      parseParams(params, ini, fin);
      performActions();
    }
  }
}

void performActions() {
  digitalWrite(led, HIGH);
  delay(HPeriod);
  digitalWrite(led, LOW);
  delay(LPeriod);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
}

void parseParams(String params, int ini, int fin) {
  int separaL = ini;
  int separaR = params.indexOf(',', ini+1);
  
  while (true) {
    if (separaR == -1 or separaR > fin) {
      separaR = fin;
    }
    
    String pair = params.substring(separaL+1, separaR);
    setParam(pair);
    
    if (separaR == fin) {
      break;
    }
    
    separaL = separaR;
    separaR = params.indexOf(',', separaR+1);
  }
}

void setParam(String pair) {
  int separa = pair.indexOf(':');
  String key = pair.substring(0, separa);
  String value = pair.substring(separa+1);
  
  if (key == "HPeriod") {
    HPeriod = value.toInt();
  } else
  if (key == "LPeriod") {
    LPeriod = value.toInt();
  }
}

/*
for testing from python:

>>> from serial import Serial
>>> ser = Serial('/dev/ttyACM0')
>>> ser.write(b'^HPeriod:2000,LPeriod:6000$')
*/
