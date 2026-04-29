int inp1 = 4;

unsigned long timeOfLastButtonDown = 0;
bool lastButtonStatus = false;
bool buttonStatus = false;
int pressTimeout = 100;  //ms

unsigned long timeOfLastPrint = 0;
int printTimeout = 1000;
int presses = 0;

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  if (asyncButtonPressLimited()) presses++;

  if (millis() - timeOfLastPrint >= printTimeout) {
    timeOfLastPrint = millis();
    Serial.println("pps: " + String(presses));
    presses = 0;
  }
}

bool asyncButtonPressLimited() {
  if (millis() - timeOfLastButtonDown >= pressTimeout) {
    buttonStatus = digitalRead(inp1) == LOW;
    bool buttonChanged = buttonStatus != lastButtonStatus;
    lastButtonStatus = buttonStatus;

    if (buttonChanged) {
      timeOfLastButtonDown = millis();

      if (buttonStatus) {
        return true;
      }
    }
  }

  return false;
}