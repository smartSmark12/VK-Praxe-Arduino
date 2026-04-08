int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int freq1 = 2; //Hz
int per1 = 1000 / freq1; //ms
int halfper1 = per1 / 2;

int freq2 = 4; //Hz
int per2 = 1000 / freq2; //ms
int halfper2 = per2 / 2;

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (digitalRead(inp1) == LOW && digitalRead(inp2) == LOW) {
    digitalWrite(led2, LOW);
    blink(led1, halfper2);
  } else if (digitalRead(inp1) == LOW || digitalRead(inp2) == LOW) {
    digitalWrite(led2, LOW);
    blink(led1, halfper1);
  } else {
    digitalWrite(led2, HIGH);
  }
}

void blink(int pinID, int delayTime) {
  digitalWrite(pinID, HIGH);
  delay(delayTime);
  digitalWrite(pinID, LOW);
  delay(delayTime);
}