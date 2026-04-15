int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int counter1 = 0;
int counter2 = 0;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (handleClick(inp1)) counter1++;
  if (handleClick(inp2)) counter2++;

  if (counter1 > 5-1 || counter2 > 8-1) {
    ledOn(led1);
  }
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

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}