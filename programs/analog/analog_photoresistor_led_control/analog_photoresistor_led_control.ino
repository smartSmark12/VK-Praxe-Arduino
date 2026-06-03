int ani1 = A1;

int led1 = 7;

int maxVolt = 5;//v
int knownRes = 2000;//ohm

float triggerLightLevel = 1000;//ohm

int readData;

void setup() {
  Serial.begin(9600);
}

void loop() {
  readData = analogRead(ani1);
  if (getRes(readData) > triggerLightLevel) {
    ledOn(led1);
  } else {
    ledOff(led1);
  }
}

float getRes(int analogData) {
  float source = maxVolt;
  float measured = analogData / 1023. * maxVolt;
  float known = source - measured;

  return measured / known * knownRes;
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}






