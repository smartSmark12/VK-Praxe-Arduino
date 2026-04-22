int led1 = 7;

int inp1 = 4;

unsigned long timeSinceButtonDown;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  handleClickExtended(inp1);
}

bool handleClickExtended(int buttonID) {
  if (digitalRead(buttonID) == LOW) {
    timeSinceButtonDown = millis();
    while (digitalRead(buttonID) == LOW);
    Serial.println("drženo po: " + String(millis() - timeSinceButtonDown));
    return true;
  }
  return false;
}