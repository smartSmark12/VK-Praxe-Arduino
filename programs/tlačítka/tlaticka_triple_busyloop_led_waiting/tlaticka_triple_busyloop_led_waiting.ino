int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int freq = 10; //Hz
int halfper = (1000 / freq) / 2; //ms

void setup() {
  pinMode(inp1, INPUT);
  pinMode(inp2, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // cekej na prvni tlacitko stisk
  while(digitalRead(inp1) == HIGH);
  digitalWrite(led1, HIGH);
  // cekej na prvni tlacitko pust
  while(digitalRead(inp1) == LOW);
  digitalWrite(led2, HIGH);

  // cekej na druhe tlacitko stisk
  while(digitalRead(inp2) == HIGH);
}

void loop() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(halfper);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(halfper);
}