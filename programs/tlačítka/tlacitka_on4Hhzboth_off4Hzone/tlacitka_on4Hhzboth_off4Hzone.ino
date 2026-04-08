int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int freq = 4; //Hz
int per = 1000 / freq; //ms
int halfper = per / 2;

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (digitalRead(inp1) != LOW) {
    blinkBoth();
  } else {
    blinkOne();
  }
}

void blinkOne() {
  digitalWrite(led1, HIGH);
  delay(halfper);
  digitalWrite(led1, LOW);
  delay(halfper);
}

void blinkBoth() {
  digitalWrite(led2, HIGH);
  digitalWrite(led1, HIGH);
  delay(halfper);
  digitalWrite(led2, LOW);
  digitalWrite(led1, LOW);
  delay(halfper);
}