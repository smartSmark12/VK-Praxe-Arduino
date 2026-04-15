int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int counter = 0;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  while (counter < 5) {
    while (digitalRead(inp1) == HIGH);
    delay(dumbDelay);
    while (digitalRead(inp1) == LOW);
    counter += 1;
    delay(dumbDelay);
  }

  counter = 0;
  ledOn(led1);

  while (counter < 3) {
    while (digitalRead(inp1) == HIGH);
    delay(dumbDelay);
    while (digitalRead(inp1) == LOW);
    counter += 1;
    delay(dumbDelay);
  }

  counter = 0;
  ledOff(led1);
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}