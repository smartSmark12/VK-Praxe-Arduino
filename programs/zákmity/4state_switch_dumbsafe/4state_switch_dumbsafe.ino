aint led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int state = 0;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  while (digitalRead(inp1) == HIGH);
  delay(dumbDelay);
  while (digitalRead(inp1) == LOW);
  ledOff(led1);
  ledOff(led2);
  state += 1;
  if (state > 3) {
    state = 0;
  }

  switch (state) {
    case 0:
      break;
      
    case 1:
      ledOn(led1);
      break;

    case 2:
      ledOn(led2);
      break;

    case 3:
      ledOn(led1);
      ledOn(led2);
  }

  delay(dumbDelay);
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}