int led1 = 7;
int led2 = 9;

int inp1 = 4;

int dumbDelay = 100; //ms

unsigned long minTime = 1000;
unsigned long maxTime = 3000;

unsigned long testStartTime;
unsigned long testEndTime;

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  reactionTest();
}

void reactionTest() {
  unsigned long ledDelay = random(minTime, maxTime + 1);
  delay(ledDelay);

  ledOn(led1);
  testStartTime = millis(); 

  while (digitalRead(inp1) == HIGH);
  testEndTime = millis();

  unsigned long finalTime = testEndTime - testStartTime;
  Serial.println("reakce: " + String(finalTime) + " ms");
  ledOff(led1);
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}