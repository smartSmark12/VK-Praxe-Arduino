int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int per = 700; //ms
int halfper = per / 2;

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // initial blink
  while (digitalRead(inp2) == HIGH);
  for (int i = 0; i < 3; i++) {
    blink(led2, halfper);
  }
}

void loop() {
  if (digitalRead(inp1) == LOW) {
    digitalWrite(led1, HIGH);
  }
  if (digitalRead(inp2) == LOW) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}

void blink(int pinID, int delayTime) {
  digitalWrite(pinID, HIGH);
  delay(delayTime);
  digitalWrite(pinID, LOW);
  delay(delayTime);
}