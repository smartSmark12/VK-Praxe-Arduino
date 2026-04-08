int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int freq = 4; //Hz
int per = 1000 / freq; //ms
int halfper = per / 2;

bool blinking = false;

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (digitalRead(inp1) == LOW) {
    blinking = true;
  } else if (digitalRead(inp2) == LOW) {
    blinking = false;
  }

  if (blinking) blink(led1, halfper);
}

void blink(int pinID, int delayTime) {
  digitalWrite(pinID, HIGH);
  delay(delayTime);
  digitalWrite(pinID, LOW);
  delay(delayTime);
}