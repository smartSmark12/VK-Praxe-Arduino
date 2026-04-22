int led1 = 7;

int inp1 = 4;

int dumbDelay = 100; //ms

unsigned long timeSinceButtonDown;
unsigned long timeHeldFor;
int currentPresses = 0;
int targetPresses = 5;
int triggerTimeout = 1000;//ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
}

void loop() {
  if (handleClickExtended(inp1)) {
    currentPresses++;
  }

  if (currentPresses >= targetPresses) {
    ledOn(led1);
  }
}

bool handleClickExtended(int buttonID) {
  if (digitalRead(buttonID) == LOW) {
    timeSinceButtonDown = millis();
    delay(dumbDelay);
    while (digitalRead(buttonID) == LOW);
    timeHeldFor = millis();
    delay(dumbDelay);
    if (timeHeldFor - timeSinceButtonDown >= triggerTimeout) {
      return true;
    }
  }
  return false;
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}