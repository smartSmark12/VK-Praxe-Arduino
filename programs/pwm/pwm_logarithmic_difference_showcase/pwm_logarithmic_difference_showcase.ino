int led1 = 6;
int led2 = 9;

int brightness1_1 = 10;
int brightness1_2 = 20;

int brightness2_1 = 240;
int brightness2_2 = 250;

unsigned long phaseStart;
int phaseTimeout = 1000* 1;//ms

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  setBrightness(led1, brightness1_1);
  setBrightness(led2, brightness2_1);

  phaseStart = millis();
  while(millis() - phaseStart < phaseTimeout);

  setBrightness(led1, brightness1_2);
  setBrightness(led2, brightness2_2);

  phaseStart = millis();
  while(millis() - phaseStart < phaseTimeout);
}

void setBrightness(int ledID, int brightness) {
  analogWrite(ledID, brightness);
}