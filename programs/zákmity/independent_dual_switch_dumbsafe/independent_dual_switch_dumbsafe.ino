int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

bool state1 = false;
bool state2 = false;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (handleClick(inp1)) state1 = !state1;
  if (handleClick(inp2)) state2 = !state2;

  handleLed(led1, state1);
  handleLed(led2, state2);
}

bool handleClick(int buttonID) {
  if (digitalRead(buttonID) == LOW) {
    delay(dumbDelay);
    while (digitalRead(buttonID) == LOW);
    delay(dumbDelay);
    return true;
  }
  return false;
}

void handleLed(int ledID, bool state) {
  if (state) {
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