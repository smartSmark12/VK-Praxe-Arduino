int led1 = 7;

int inp1 = 4;

int dumbDelay = 100; //ms

unsigned long timeLastPress;
unsigned long timeCurrentPress;
unsigned long timeDelta;

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);

  Serial.begin(9600);

  timeLastPress = millis();
}

void loop() {
  handleClickExtended(inp1);
}

bool handleClickExtended(int buttonID) {
  if (digitalRead(buttonID) == LOW) {
    timeCurrentPress = millis();
    timeDelta = timeCurrentPress - timeLastPress;
    timeLastPress = timeCurrentPress;
    Serial.println("rozdíl: " + String(timeDelta));
    //delay(dumbDelay);
    while (digitalRead(buttonID) == LOW);
    //delay(dumbDelay);
    return true;
  }
  return false;
}