int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int per1 = 300; //ms
int halfper1 = per1 / 2; //ms

int per2 = 120; //ms
int halfper2 = per2 / 2; //ms

int halfperFinal = halfper1;

void setup() {
  pinMode(inp1, INPUT);
  pinMode(inp2, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (digitalRead(inp1) == LOW) {
    halfperFinal = halfper1;
  }

  if (digitalRead(inp2) == LOW) {
    halfperFinal = halfper2;
  }

  blink(led1, halfperFinal);
}

void blink(int pinID, int halfdelay) {
  digitalWrite(pinID, HIGH);
  delay(halfdelay);
  digitalWrite(pinID, LOW);
  delay(halfdelay);
}