int targetPin1 = 7;
int targetPin2 = 9;

int T1 = 250; //ms
int T2 = 400;

int repeat1 = 3;
int repeat2 = 2;

void setup() {
  pinMode(targetPin1, OUTPUT);
  pinMode(targetPin2, OUTPUT);
}

void loop() {
  // první svítí, druhá bliká
  ledOn(targetPin1);
  blinkRepeatedly(targetPin2, repeat1, T1);
  ledOff(targetPin1);

  // druhá svítí, první bliká
  ledOn(targetPin2);
  blinkRepeatedly(targetPin1, repeat2, T2);
  ledOff(targetPin2);
}

void ledOn(int pinID) {
  digitalWrite(pinID, HIGH);
}

void ledOff(int pinID) {
  digitalWrite(pinID, LOW);
}

void blinkRepeatedly(int pinID, int repeatTimes, int repeatPeriod) {
  for (int i = 0; i < repeatTimes; i++) {
    blink(pinID, repeatPeriod / 2);
    delay(repeatPeriod / 2);
  }
}

void blink(int pinID, int delayTime) {
  ledOn(pinID);
  delay(delayTime);
  ledOff(pinID);
}