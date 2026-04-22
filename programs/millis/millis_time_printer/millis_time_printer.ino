int led1 = 7;

int inp1 = 4;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (handleClick(inp1)) {
    Serial.println("čas: " + String(millis()));
  }
}

bool handleClick(int buttonID) {
  if (digitalRead(buttonID) == LOW) {
    delay(dumbDelay);
    while (digitalRead(buttonID) == LOW);
    delay(dumbDelay);
    return true;
  }
  return false;
}