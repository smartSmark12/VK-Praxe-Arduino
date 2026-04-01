int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

bool status = false;

void setup() {
  pinMode(inp1, INPUT);
  pinMode(inp2, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (digitalRead(inp1) == LOW) {
    status = true;
  }

  if (digitalRead(inp2) == LOW) {
    status = false;
  }

  if (status) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}