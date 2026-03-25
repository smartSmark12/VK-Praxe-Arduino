int targetPin1 = 9;

int freq1 = 1;
int freqReset1 = 1;
int freqDelta1 = 1; // zbytecne? mozna XD
int freqMax1 = 30; //Hz

int period = (1000 / freq1); // recalc this

void setup() {
  pinMode(targetPin1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  blinkRepeatedly(targetPin1, freqMax1);
}

void blinkRepeatedly(int pinID, int repeatTimes) {
  for (int i = 0; i < repeatTimes; i++) {
    freq1 += freqDelta1;

    for (int j = 0; j < freq1; j++) {
      period = (1000 / freq1);
      blink(pinID, period);
    }
  }

  freq1 = freqReset1;
}

void blink(int pinID, int delayTime) {
  digitalWrite(pinID, HIGH);
  delay(delayTime / 2);
  digitalWrite(pinID, LOW);
  delay(delayTime / 2);
}