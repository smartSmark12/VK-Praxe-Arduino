int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int freq = 5; //Hz
int halfper = (1000 / freq) / 2; //ms

void setup() {
  pinMode(inp1, INPUT);
  pinMode(inp2, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  while (digitalRead(inp1) == HIGH); //busyloop go brrr
  digitalWrite(led1, HIGH);
  delay(halfper);
  digitalWrite(led1, LOW);
  delay(halfper);
}