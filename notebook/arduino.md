<!-- VK -->


<!-- obsah -->
Obsah hehe
- [Arduino UNO](#arduino-uno)
- [Reference příkazů](#reference-příkazů)
  - [IO](#io)
- [Jednoduché příklady](#jednoduché-příklady)
    - [Blikání LEDky](#blikání-ledky)
    - [Blikání LEDky pomocí periody](#blikání-ledky-pomocí-periody)
    - [Blikání LEDky pomocí frekvence](#blikání-ledky-pomocí-frekvence)


<!-- actually data -->
# Arduino UNO
- Jednodeskový počítač **ATMega328**
- Mem:
  - Data **2kB** SRAM
  - Program **32kB** Flash
  - Data **1kB** EEPROM
- Krystalový oscilátor (*hodinový signál*) - **16MHz** (*chip nominal 20MHz*)
- Napájení:
  - USB *5V*
  - Napájecí konektor *6-12V*
- GPIO:
  - Digitální vývody:
    - 0-13 (*nepoužíváme 0 - RX, 1 - TX, 13 - inbuilt LED*)
    - používáme **2-12**
    - low/HIGH (*0V / +5V*)
    - obousměrné (*In / Out*)
    - PWM:
      - 3, 5, 6, 9, 10, 11
  - Analogové vstupy:
    - **A0-A5**
    - napětí (*0-5V*) v digitálních hodnotách (*0-1023*) 
- [*oficiální stránky*](https://www.arduino.cc)

# Reference příkazů
## IO
- pinMode( vývod: int, režim: OUTPUT | INPUT | INPUT_PULLUP )
    ``` c
    pinMode(13, OUTPUT);
    pinMode(8, INPUT);
    ```
    - [příklad blikání LEDky](#blikání-ledky)
- digitalWrite( vývod: int, stav: LOW | HIGH )
    ``` c
    digitalWrite(13, HIGH);
    digitalWrite(5, LOW);
    ```
    - [příklad blikání LEDky](#blikání-ledky)

# Jednoduché příklady

### Blikání LEDky
``` c
void setup () {
    pinMode(13, OUTPUT);      // povolíme výstup na pinu 13 (inbuilt LEDka)
    Serial.begin(9600);       // nastavíme komunikaci s PC přes seriovou linku s baudrate 9600
}

void loop () {
    digitalWrite(13, HIGH);   // rozsvítí LEDku (na pinu 13)
    delay(500);               // pozastaví kód na 0.5s
    digitalWrite(13, LOW);    // zhasne LEDku
    delay(500);
}
```

### Blikání LEDky pomocí periody
``` c
int perioda = 320;          // perioda (T) 320ms
int delayTime = perioda / 2;// T/2

void setup () {
    pinMode(13, OUTPUT);    // povolíme výstup na pinu 13 (inbuilt LEDka)
    Serial.begin(9600);     // nastavíme komunikaci s PC přes seriovou linku s baudrate 9600
}

void loop () {
    digitalWrite(13, HIGH); // rozsvítí LEDku (na pinu 13)
    delay(delayTime);       // pozastaví kód na T/2
    digitalWrite(13, LOW);  // zhasne LEDku
    delay(delayTime);
}
```

### Blikání LEDky pomocí frekvence
``` c
int frekvence = 50;             // frekvence (f) 50 Hz
int perioda = 1000 / frekvence; // perioda (1/f)
int delayTime = perioda / 2;    // T/2

void setup () {
    pinMode(13, OUTPUT);        // povolíme výstup na pinu 13 (inbuilt LEDka)
    Serial.begin(9600);         // nastavíme komunikaci s PC přes seriovou linku s baudrate 9600
}

void loop () {
    digitalWrite(13, HIGH);     // rozsvítí LEDku (na pinu 13)
    delay(delayTime);           // pozastaví kód na T/2
    digitalWrite(13, LOW);      // zhasne LEDku
    delay(delayTime);
}
```