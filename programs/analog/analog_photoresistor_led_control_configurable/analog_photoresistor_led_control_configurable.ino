int ani1 = A1;

int led1 = 7;

int inp1 = 4;

int maxVolt = 5;//v
int knownRes = 2000;//ohm

float triggerLightLevel = 1000;//ohm

int readData;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(inp1, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  readData = analogRead(ani1);

  if (getPressed(inp1)) {
    triggerLightLevel = getRes(readData);
  }

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

bool getPressed(int inpID) {
  return digitalRead(inpID) == LOW;
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}






