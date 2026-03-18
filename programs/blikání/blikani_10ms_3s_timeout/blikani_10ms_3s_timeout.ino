int timeout = 3000; // čas mezi bliknutími v ms
int blink = 10; // doba blinkutí v ms

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(timeout); // počká 'timeout' času před rozsvícením
  digitalWrite(13, HIGH);
  delay(blink); // počká 'blink' času před zhasnutím
  digitalWrite(13, LOW);
}
