<!-- VK -->


<!-- obsah - autogen -->
Obsah hehe
- [Arduino UNO](#arduino-uno)
  - [Odpory LED](#odpory-led)
- [Reference příkazů](#reference-příkazů)
  - [Časování](#časování)
  - [IO](#io)
- [Jednoduché příklady](#jednoduché-příklady)
  - [Blikání LED](#blikání-led)
    - [Blikání LEDky](#blikání-ledky)
    - [Blikání LEDky pomocí periody](#blikání-ledky-pomocí-periody)
    - [Blikání LEDky pomocí frekvence](#blikání-ledky-pomocí-frekvence)
    - [Blikání dvou externích LEDek nastřídačku](#blikání-dvou-externích-ledek-nastřídačku)
  - [Tlačítka](#tlačítka)
    - [Dvě tlačítka ovládající dvě ledky](#dvě-tlačítka-ovládající-dvě-ledky)
    - ['Hloupá' ochrana zákmitu](#hloupá-ochrana-zákmitu)
    - [Zjednodušená 'hloupá' ochrana zákmitu](#zjednodušená-hloupá-ochrana-zákmitu)


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

## Odpory LED
- směr:
  - *Anoda* ($+$), **delší**
  - *Katoda* ($-$), **kratší**
  - *od + do -*
- **I<sub>F</sub>** - dopředný proud (e.g. **20mA**) - překročení zkracuje životnost, zvyšuje jas
- **VA** (*VoltAmperová*) **charakteristika**:
  - LEDka začne svítit až po překročení minimálního napětí (e.g. **1.2V**)
- **počítání**:
  - zdrojové $U = 5V$ (*Arduino*)
  - cílové $U = 1.8V$ (*jedna LED*)
  - resistor cílové $U = 5V-1.8V = 3.2V$
  - resistor cílový $R =$ $?$
  - $R = \frac{U}{I} = \frac{3.2V}{20mA} = \frac{3.2V}{0.02A} = 160 Ω$
  - [*příklady*](/notebook/příklady_resistory.md)


<!-- příkazy -->
# Reference příkazů
Reference a příklady použití základních příkazů

## Časování
- delay ( čas: long )
    ``` c
    delay(500);
    delay(perioda / 2);
    ```

- millis () -> čas v ms od spuštění programu
  ```c
  unsigned long time = millis();
  ```
  - *pozn.: z důvodu přetékání času **nepoužíváme byte** ani **int**; lze použít long, ale jelikož čas nemůže být záporný, používá se **unsigned long***
  - [příklad využití millis](/programs/millis/millis_held_for_nonblocking/millis_held_for_nonblocking.ino)

## IO
- pinMode( vývod: int, režim: OUTPUT | INPUT | INPUT_PULLUP )
    ``` c
    pinMode(13, OUTPUT);
    pinMode(8, INPUT);
    ```
    - [příklad blikání LEDky](#blikání-ledky)
    - [příklad na použití pullup](/programs/tlačítka/tlacitka_on3s_on2s_chooser_pullup/tlacitka_on3s_on2s_chooser_pullup.ino)

- digitalWrite( vývod: int, stav: LOW | HIGH )
    ``` c
    digitalWrite(13, HIGH);
    digitalWrite(5, LOW);
    ```
    - [příklad blikání LEDky](#blikání-ledky)

- digitalRead( vývod: int ) -> stav: LOW | HIGH
    ``` c
    digitalRead(4);
    status = digitalRead(4);
    if (digitalRead(4) == LOW) doSomething();
    ```
    - *pozn.: při použití **pinMode INPUT** a pull-up **resistoru** je stisknutí značeno stavem **LOW**, ne HIGH*
    - [příklad ochrany zákmitu](#hloupá-ochrana-zákmitu)


<!-- příklady -->
# Jednoduché příklady
Příklady a zadání z hodin v [programs](/programs/)

## Blikání LED
Další příklady v [programs/blikání](/programs/blikání/)

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

### Blikání dvou externích LEDek nastřídačku
``` c
int targetPin1 = 7;               // nastavení pinů, na kterých jsou LEDky
int targetPin2 = 9;

int freq = 5;                     // frekvence blikání v Hz

int timeout = (1000 / freq) / 2;  // T/2

void setup() {
    pinMode(targetPin1, OUTPUT);  // povolí výstup na dané piny
    pinMode(targetPin2, OUTPUT);
}

void loop() {
    blinkByPinID(targetPin1);
    blinkByPinID(targetPin2);
}

void blinkByPinID (int pinID) {   // funkce, která blikne danou ledkou po dobu timeout
    digitalWrite(pinID, HIGH);
    delay(timeout);
    digitalWrite(pinID, LOW);
}
```

## Tlačítka
Další příklady v [programs/tlačítka](/programs/tlačítka/), popř. příklady na ochranu zákmitu v [programs/zákmity](/programs/zákmity/)

### Dvě tlačítka ovládající dvě ledky
``` c
int led1 = 7;                   // LEDky ukazující stavy
int led2 = 9;

int inp1 = 4;                   // čtecí tlačítka
int inp2 = 5;

void setup() {
    pinMode(inp1, INPUT);       // nastavení čtení na vstupních pinech (tlačítka)
    pinMode(inp2, INPUT);

    pinMode(led1, OUTPUT);      // nastavení výstupu na LEDky
    pinMode(led2, OUTPUT);
}

void loop() {
    if (digitalRead(inp1) == LOW) {
      digitalWrite(led1, HIGH); // pokud tlačítko stisknuto, rozsviť LEDku
    } else {
      digitalWrite(led1, LOW);  // jinak zhasni
    }

    if (digitalRead(inp2) == LOW) {
      digitalWrite(led2, HIGH); // to samé pro druhé tlačítko
    } else {
      digitalWrite(led2, LOW);
    }
}
```

### 'Hloupá' ochrana zákmitu
``` c
int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

bool status = false;

int dumbDelay = 100; //ms

void setup() {
    pinMode(inp1, INPUT_PULLUP);        // *využito pullup zapojení
    pinMode(inp2, INPUT_PULLUP);

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    while (digitalRead(inp1) == HIGH);  // čekáme na stisk tlačítka
    digitalWrite(led1, HIGH);           // rozsvítíme ledku
    delay(dumbDelay);                   // počkáme po dobu možného zákmitu
    while (digitalRead(inp1) == LOW);   // čekáme na rozepnutí tlačítka
    delay(dumbDelay);                   // znovu počkáme při zákmitu

    while (digitalRead(inp1) == HIGH);
    digitalWrite(led1, LOW);
    delay(dumbDelay);
    while (digitalRead(inp1) == LOW);
    delay(dumbDelay);
}
```

### Zjednodušená 'hloupá' ochrana zákmitu
``` c
int led1 = 7;
int led2 = 9;

int inp1 = 4;
int inp2 = 5;

int counter1 = 0;                             // dvě oddělená počítadla
int counter2 = 0;

int dumbDelay = 100; //ms

void setup() {
    pinMode(inp1, INPUT_PULLUP);
    pinMode(inp2, INPUT_PULLUP);

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    if (handleClick(inp1)) counter1++;         // při rozepnutí daného tlačítka se k danému počítadlu přičte 1
    if (handleClick(inp2)) counter2++;

    if (counter1 > 5-1 || counter2 > 8-1) {    // pokud counter1 dosáhl 5 stisků nebo counter2 8, rozsvítíme ledku
      ledOn(led1);
    }
}

bool handleClick(int buttonID) {               // funkce vracející true nebo false na základě toho, jestli dané tlačítko bylo stisknuto (blokující) a rozepnuto
    if (digitalRead(buttonID) == LOW) {        // nečeká na stisknutí, jen ho přečte (neblokující)
        delay(dumbDelay);
        while (digitalRead(buttonID) == LOW);  // počká na rozepnutí (blokující)
        delay(dumbDelay);
        return true;
    }
    return false;
}

void ledOn(int ledID) {                        // pomocné funkce na rozsvěcení a zhasínání ledek
    digitalWrite(ledID, HIGH);
}

void ledOff(int ledID) {
    digitalWrite(ledID, LOW);
}
```