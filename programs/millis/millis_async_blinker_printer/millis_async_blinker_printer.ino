int led1 = 7;
int led2 = 9;

int inp1 = 4;

int freq1 = 5;//Hz
int period1 = 1000 / freq1;//ms

int period2 = 1000 * 2;

int lightupTime2 = 10;//ms

int printTimeout = 1000* 3;
unsigned long timeOfLastPrint = 0;
unsigned long lastPrintTime = 0;
String printText = "AHOJ";

void setup() {
  pinMode(inp1, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  asyncBlinkLed(led1, period1);
  asyncBlinkLedLightup(led2, period2, lightupTime2);
  timeOfLastPrint = asyncPrint(printText, printTimeout, timeOfLastPrint);
}

unsigned long asyncPrint(String textToPrint, int period, unsigned long lastPrintTime) {
  if (millis() - lastPrintTime >= period) {
    Serial.println(textToPrint);
    return millis();
  } else {
    return lastPrintTime;
  }
}

void asyncBlinkLed(int ledID, int period) {
  if (millis() % period < period / 2) {
    ledOn(ledID);
  } else {
    ledOff(ledID);
  }
}

void asyncBlinkLedLightup(int ledID, int period, int lightupTime) {
  if (millis() % period < lightupTime) {
    ledOn(ledID);
  } else {
    ledOff(ledID);
  }
}

void ledOn(int ledID) {
  digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
  digitalWrite(ledID, LOW);
}