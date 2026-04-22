int led1 = 7;

int inp1 = 4;

int dumbDelay = 100; //ms

unsigned long timeSinceButtonDown;
int heldTimeout = 3000;//ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
}

void loop() {
  if (digitalRead(inp1) == LOW) {
    timeSinceButtonDown = millis();
    delay(dumbDelay);
    while (digitalRead(inp1) == LOW) {
      if (millis() - timeSinceButtonDown >= heldTimeout) {
        ledOn(led1);
      } else {
        ledOff(led1);
      }
    }
    delay(dumbDelay);
    return true;
  }
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}