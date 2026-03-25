int targetPin1 = 7;
int targetPin2 = 9;

int freq = 5;

int timeout = (1000 / freq) / 2;

void setup() {
  pinMode(targetPin1, OUTPUT);
  pinMode(targetPin2, OUTPUT);
}

void loop() {
  blinkByPinID(targetPin1);
  blinkByPinID(targetPin2);
}

void blinkByPinID (int pinID) {
  digitalWrite(pinID, HIGH);
  delay(timeout);
  digitalWrite(pinID, LOW);
}