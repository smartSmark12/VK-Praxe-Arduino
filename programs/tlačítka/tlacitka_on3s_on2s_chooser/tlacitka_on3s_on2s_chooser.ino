int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int timeOn1 = 3000;//ms
int timeOn2 = 2000;//ms

void setup() {
  pinMode(inp1, INPUT);
  pinMode(inp2, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (digitalRead(inp1) == LOW) {
    lightUpFor(led1, timeOn1);
  }

  if (digitalRead(inp2) == LOW) {
    lightUpFor(led2, timeOn2);
  }
}

void lightUpFor(int pinID, int timeOn) {
  digitalWrite(pinID, HIGH);
  delay(timeOn);
  digitalWrite(pinID, LOW);
}