int targetPin = 9;

byte startPeriod = 10; // ms
byte deltaPeriod = 20;

byte period = startPeriod;

void setup() {
  pinMode(targetPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println(period / 2);

  digitalWrite(targetPin, HIGH);
  delay(period / 2);
  digitalWrite(targetPin, LOW);
  delay(period / 2);

  period += deltaPeriod;
}
