int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int dumbDelay = 100; //ms

bool pressed = false;
bool lastPressed = false;
bool changed = false;
bool state = false;

int presses = 0;

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  lastPressed = pressed;

  if (digitalRead(inp1) == LOW) {
    pressed = true;
    delay(dumbDelay);
  } else {
    pressed = false;
  }

  if (lastPressed != pressed) {
    changed = true;
  } else {
    changed = false;
  }

  if (pressed && changed) {
    presses += 1;
    Serial.println("presses: " + String(presses));
  }
}