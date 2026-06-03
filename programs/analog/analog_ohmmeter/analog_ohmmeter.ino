int ani1 = A1;

int maxVolt = 5;
int knownRes = 270;//ohm

int readData;

void setup() {
  Serial.begin(9600);
}

void loop() {
  readData = analogRead(ani1);
  Serial.println(String(getRes(readData)) + " Ω");
}

float getRes(int analogData) {
  float source = maxVolt;
  float measured = analogData / 1023. * maxVolt;
  float known = source - measured;

  return measured / known * knownRes;
}