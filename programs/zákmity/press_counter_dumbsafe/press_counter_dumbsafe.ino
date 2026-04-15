int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int presses = 0;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  while (digitalRead(inp1) == HIGH);
  presses += 1;
  Serial.println("presses: " + String(presses));
  delay(dumbDelay);
  while (digitalRead(inp1) == LOW);
  delay(dumbDelay);
}