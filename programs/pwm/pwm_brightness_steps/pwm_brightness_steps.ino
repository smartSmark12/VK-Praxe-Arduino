int led1 = 6;
int led2 = 9;

unsigned long phaseStart;
int phaseTimeout = 1000* 1;//ms

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  phaseLoop(0);
  phaseLoop(20);
  phaseLoop(40);
  phaseLoop(70);
  phaseLoop(100);
}

void phaseLoop(float brightnessPercent) { // blocking
  phaseStart = millis();

  int brightness = 255 * (brightnessPercent / 100);

  analogWrite(led2, brightness);

  while(millis() - phaseStart < phaseTimeout);
}