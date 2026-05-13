int ani1 = A1;

int led1 = 6;

int freq;
int minFreq = 1;
int maxFreq = 30;

int per;

void setup() {
  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  freq = maxFreq * (analogRead(ani1) / 1024.);
  freq = clamp(freq, minFreq, maxFreq);
  per = 1000 / freq;

  //Serial.println(freq);
  
  asyncBlinkLed(led1, per);
}

void asyncBlinkLed(int ledID, int period) {
  if (millis() % period < period / 2) {
    ledOn(ledID);
  } else {
    ledOff(ledID);
  }
}

int clamp(int val, int min, int max) {
  if (val < min) return min;
  else if (val > max) return max;
  else return val;
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}