int ani1 = A1;

int led1 = 6;//pwm

int inp1 = 4;

int maxVolt = 5;//v
int knownRes = 2000;//ohm

float triggerLightLevel = 1000;//ohm
float maxLightLevel = 2500;

int readData;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(inp1, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  readData = analogRead(ani1);

  int brightness = map(clamp(getRes(readData), triggerLightLevel, maxLightLevel), triggerLightLevel, maxLightLevel, 0, 255);

  analogWrite(led1, brightness);
  
}

float getRes(int analogData) {
  float source = maxVolt;
  float measured = analogData / 1023. * maxVolt;
  float known = source - measured;

  return measured / known * knownRes;
}

float clamp(float val, float min, float max) {
  if (val < min) return min;
  else if (val > max) return max;
  else return val;
}






