int led1 = 6;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int brightnessSets[] = { 10, 30, 50, 80 };
int brightnessIndex = 0;

unsigned long lastPress[6];  // dumb, but works
bool lastStatus[6];
bool buttonStatus[6];

int pressTimeout = 100;  //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  lastPress[inp1] = 0;
  lastPress[inp2] = 0;

  lastStatus[inp1] = false;
  lastStatus[inp2] = false;

  buttonStatus[inp1] = false;
  buttonStatus[inp1] = false;

  Serial.begin(9600);
}

void loop() {
  if (asyncButtonPress(inp1)) {
    brightnessIndex++;
    if (brightnessIndex > (sizeof(brightnessSets) / sizeof(brightnessSets[0])) - 1) {
      brightnessIndex = 0;
    }
  }

  setBrightnessPercent(led1, brightnessSets[brightnessIndex]);
}

void setBrightnessPercent(int ledID, float brightnessPercent) {
  int brightness = 255 * (brightnessPercent / 100);

  analogWrite(ledID, brightness);
}

bool asyncButtonPress(int pinID) {
  if (millis() - lastPress[pinID] >= pressTimeout) {
    buttonStatus[pinID] = digitalRead(pinID) == LOW;
    bool buttonChanged = buttonStatus[pinID] != lastStatus[pinID];
    lastStatus[pinID] = buttonStatus[pinID];

    if (buttonChanged) {
      lastPress[pinID] = millis();

      if (buttonStatus[pinID]) {
        return true;
      }
    }
  }

  return false;
}