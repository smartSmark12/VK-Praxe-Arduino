int led1 = 6;
int led2 = 9;

int freq2 = 100;//Hz
int period2 = 1000 / freq2;//ms
int lightupTime2 = period2 / 2;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  ledOn(led1);
  asyncBlinkLedExtended(led2, period2, lightupTime2);
}

void asyncBlinkLedExtended(int ledID, int period, int lightupTime) {
  if (millis() % period < lightupTime) {
    ledOn(ledID);
  } else {
    ledOff(ledID);
  }
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}