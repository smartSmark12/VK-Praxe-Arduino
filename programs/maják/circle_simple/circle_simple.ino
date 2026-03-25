int lightsAmount = 10;
int timeout = 250;

int lights[] = {
  4, 5, 6, 7, 8, 9, 10, 11, 12, 13
};

int currentIndex = 0;

void setup() {
  for (int light = 0; light < lightsAmount; light++) {
    pinMode(light, OUTPUT);
  }
}

void loop() {
  digitalWrite(lights[currentIndex], HIGH);
  delay(timeout);
  digitalWrite(lights[currentIndex], LOW);

  currentIndex++;

  if (currentIndex > lightsAmount - 1) {
    currentIndex = 0;
  }
}
