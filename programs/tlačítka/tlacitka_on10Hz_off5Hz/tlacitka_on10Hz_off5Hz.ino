int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int freq1 = 10; //Hz
int halfper1 = (1000 / freq1) / 2; //ms

int freq2 = 5; //Hz
int halfper2 = (1000 / freq2) / 2; //ms

void setup() {
  pinMode(inp1, INPUT);
  pinMode(inp2, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (digitalRead(inp1) == LOW) {
    blink(led1, halfper1);
  } else {
    blink(led1, halfper2);
  }
}

void blink(int pinID, int halfdelay) {
  digitalWrite(pinID, HIGH);
  delay(halfdelay);
  digitalWrite(pinID, LOW);
  delay(halfdelay);
}