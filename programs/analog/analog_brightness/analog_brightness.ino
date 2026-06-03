int ani1 = A1; // dont need to set pinMode

int led1 = 6;

int brightness;
int minBrightness = 0;
int maxBrightness = 100;

int per;

void setup() {
  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  brightness = maxBrightness * (analogRead(ani1) / 1024.); // using 1024. to force float division
  brightness = clamp(brightness, minBrightness, maxBrightness);

  analogWrite(led1, brightness);
}

int clamp(int val, int min, int max) {
  if (val < min) return min;
  else if (val > max) return max;
  else return val;
}