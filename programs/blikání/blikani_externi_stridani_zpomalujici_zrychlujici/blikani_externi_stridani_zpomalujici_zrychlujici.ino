int targetPin1 = 7;
int targetPin2 = 9;

byte T1 = 10; //ms
byte T2 = 250;

byte deltaT1 = 10;
byte deltaT2 = 10;

void setup() {
  pinMode(targetPin1, OUTPUT);
  pinMode(targetPin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  blink(targetPin1, T1);
  blink(targetPin2, T2);
}

void blink(int pinID, byte period) {
  digitalWrite(pinID, HIGH);
  delay(period);
  digitalWrite(pinID, LOW);

  T1 += deltaT1;
  T2 -= deltaT2;

  Serial.println("T1: " + String(T1) + " T2: " + String(T2));
}
