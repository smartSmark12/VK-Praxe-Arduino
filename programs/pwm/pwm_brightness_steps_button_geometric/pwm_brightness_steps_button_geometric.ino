int led1 = 6;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

unsigned long lastPress[6];  // dumb, but works
bool lastStatus[6];
bool buttonStatus[6];

int minBrightness = 0;
int maxBrightness = 255;
int brightnessStepMult = 2;

int brightness = 1;

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
  if (asyncButtonPress(inp1)) brightnessUp();
  if (asyncButtonPress(inp2)) brightnessDown();

  setBrightness(led1, brightness);
}

void brightnessUp() {
  if (brightness == 0) {
    brightness = 1;
  } else if (brightness <= 128) {
    brightness *= brightnessStepMult;
  }
}

void brightnessDown() {
  if (brightness == 1) {
    brightness = 0;
  } else if (brightness > 0) {
    brightness /= brightnessStepMult;
  }
}

int clamp(int num, int min, int max) {
  if (num > max) {
    return max;
  } else if (num < min) {
    return min;
  } else {
    return num;
  }
}

void setBrightness(int ledID, float brightness) {

  analogWrite(ledID, clamp(brightness, minBrightness, maxBrightness));
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