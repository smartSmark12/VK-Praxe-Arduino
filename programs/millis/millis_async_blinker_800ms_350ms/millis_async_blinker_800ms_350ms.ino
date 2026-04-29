int led1 = 7;
int led2 = 9;

int inp1 = 4;

int period1 = 800;  //ms
int period2 = 350;

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  asyncBlinkLed(led1, period1);
  asyncBlinkLed(led2, period2);
}

void asyncBlinkLed(int ledID, int period) {
  if (millis() % period < period / 2) {
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