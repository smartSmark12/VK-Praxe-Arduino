int led1 = 7;

int inp1 = 4;

int dumbDelay = 100; //ms

unsigned long timeSinceButtonDown;
unsigned long timeButtonHeldFor;

int targetTriggerTime = 3000;//ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (handleClickExtended(inp1)) {
    if (timeButtonHeldFor >= targetTriggerTime) {
      ledOn(led1);
    } else {
      ledOff(led1);
    }
  }
}

bool handleClickExtended(int buttonID) {
  if (digitalRead(buttonID) == LOW) {
    timeSinceButtonDown = millis();
    delay(dumbDelay);
    while (digitalRead(buttonID) == LOW);
    timeButtonHeldFor = millis() - timeSinceButtonDown;
    delay(dumbDelay);
    return true;
  }
  return false;
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}