int led1 = 6;
int led2 = 9;

unsigned long phaseStart;
int phaseTimeout = 1000* 1;//ms
bool phaseSwitch = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  if (millis() - phaseStart > phaseTimeout) {
    phaseStart = millis();
    phaseSwitch = !phaseSwitch;
  }

  if (phaseSwitch) {
    phaseDown();
  } else {
    phaseUp();
  }
}

void phaseUp() {
  setBrightnessPercent(led1, (millis() - phaseStart) / 10);
  setBrightnessPercent(led2, (phaseTimeout - (millis() - phaseStart)) / 10);
}

void phaseDown() {
  setBrightnessPercent(led2, (millis() - phaseStart) / 10);
  setBrightnessPercent(led1, (phaseTimeout - (millis() - phaseStart)) / 10);
}

void setBrightnessPercent(int ledID, float brightnessPercent) {
  int brightness = 255 * (brightnessPercent / 100);

  analogWrite(ledID, brightness);
}