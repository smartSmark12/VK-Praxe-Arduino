int led1 = 7;
int led2 = 9;

int inp1 = 4;

int freq = 2;//Hz
int period = 1000 / freq;//ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (millis() % period < period / 2) {
    ledOn(led1);
  } else {
    ledOff(led1);
  }
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}