int led1 = 7;

int inp1 = 4;

int dumbDelay = 100; //ms

int requiredPresses = 10;
int currentPresses = 0;

unsigned long timeSinceStart;
unsigned long timeLastPress;

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  while (currentPresses < requiredPresses) {
    if (digitalRead(inp1) == LOW) {

      if (currentPresses == 0) {
        timeSinceStart = millis();
      }

      delay(dumbDelay);
      while (digitalRead(inp1) == LOW);

      if (currentPresses > requiredPresses - 2) {
        timeLastPress = millis();
      }

      delay(dumbDelay);

      currentPresses++;
    }
  }

  Serial.println("čas od prvního stisku: " + String(timeLastPress - timeSinceStart));
  currentPresses = 0;
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