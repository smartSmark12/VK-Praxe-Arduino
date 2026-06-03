int ani1 = A1;

int maxVolt = 5;
int readData;

void setup() {
  Serial.begin(9600);
}

void loop() {
  readData = analogRead(ani1);
  Serial.println(String(getVolt(readData)) + " V");
}

float getVolt(int analogData) {
  return analogData / 1023. * maxVolt;
}