int ani1 = A1;

int led1 = 6;//pwm

int maxVolt = 5;//v
int knownRes = 2000;//ohm

float triggerLightLevel = 2000;//ohm

int readData;

unsigned long doorOpenTime;//millis
int doorTriggerTime = 1000* 3;//sec
bool wasDoorOpen = false;

void setup() {
  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  readData = getRes(analogRead(ani1));

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

float getRes(int analogData) {
  float source = maxVolt;
  float measured = analogData / 1023. * maxVolt;
  float known = source - measured;

  return measured / known * knownRes;
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






