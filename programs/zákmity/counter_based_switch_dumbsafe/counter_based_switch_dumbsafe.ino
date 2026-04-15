int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int presses1 = 0;
int presses2 = 0;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (handleClick(inp1)) presses1++;
  if (handleClick(inp2)) presses2++;

  handleLeds();
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

void handleLeds() {
  if (presses1 > presses2) {
    ledOff(led2);
    ledOn(led1);
  } else if (presses1 < presses2) {
    ledOff(led1);
    ledOn(led2);
  } else {
    ledOff(led1);
    ledOff(led2);
  }
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}