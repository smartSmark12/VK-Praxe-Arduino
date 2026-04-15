int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int period = 50;
int lastPeriod = 0;

int dumbDelay = 100; //ms

void setup() {
  pinMode(inp1, INPUT_PULLUP);
  pinMode(inp2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (handleClick(inp1)) period -= 50;
  if (handleClick(inp2)) period += 50;

  period = clamp(period, 50, 750);

  if (lastPeriod != period) { //only print
    Serial.println(String(period) + " ms");
    lastPeriod = period;
  }

  blink(led1, period);
  
}

void blink(int ledID, int blinkPeriod) {
  ledOn(ledID);
  delay(blinkPeriod / 2);
  ledOff(ledID);
  delay(blinkPeriod / 2);
}

bool handleClick(int buttonID) {
  if (digitalRead(buttonID) == LOW) {
    delay(dumbDelay);
    while (digitalRead(buttonID) == LOW);
    delay(dumbDelay);
    return true;
  }
  return false;
}

int clamp(int num, int min, int max) {
  if (num < min) num = min;
  if (num > max) num = max;
  return num;
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}