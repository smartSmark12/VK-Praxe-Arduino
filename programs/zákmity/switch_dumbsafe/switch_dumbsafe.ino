int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

bool status = false;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  while (digitalRead(inp1) == HIGH);
  digitalWrite(led1, HIGH);
  delay(dumbDelay);
  while (digitalRead(inp1) == LOW);
  delay(dumbDelay);

  while (digitalRead(inp1) == HIGH);
  digitalWrite(led1, LOW);
  delay(dumbDelay);
  while (digitalRead(inp1) == LOW);
  delay(dumbDelay);
}