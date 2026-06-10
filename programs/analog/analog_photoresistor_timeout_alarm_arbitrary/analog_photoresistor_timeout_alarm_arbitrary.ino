int ani1 = A1;

int led1 = 6;//pwm

float triggerLightLevel = 500; // not ohm; arbitrary value

int readData;

unsigned long doorOpenTime;//millis
int doorTriggerTime = 1000* 10;//sec
bool wasDoorOpen = false;

void setup() {
  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  readData = analogRead(ani1);

  if (isDoorOpen(readData)) {
    if (!wasDoorOpen) {
      doorOpenTime = millis();
    }

    if (millis() - doorOpenTime > doorTriggerTime) {
      alarmOn();
    }    
  } else {
    alarmOff();
  }

  wasDoorOpen = isDoorOpen(readData);
  
}

bool isDoorOpen(float level) {
  return level < triggerLightLevel;
}

void alarmOn() {
  int brightness = (sin(millis()/100.) + 1) / 2 * 255;
  analogWrite(led1, brightness);
}

void alarmOff() {
  digitalWrite(led1, LOW);
}

float clamp(float val, float min, float max) {
  if (val < min) return min;
  else if (val > max) return max;
  else return val;
}






