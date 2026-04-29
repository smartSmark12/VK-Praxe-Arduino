int led1 = 7;
int led2 = 9;

int inp1 = 4;

int period1 = 650;//ms

int freq2 = 12;//Hz
int period2 = 1000 / freq2;

unsigned long timeout1 = 1000* 15;
unsigned long timeout2 = 1000* 25; 

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (millis() < timeout1) asyncBlinkLed(led1, period1); else ledOff(led1);
  if (millis() < timeout2) asyncBlinkLed(led2, period2); else ledOff(led2);
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