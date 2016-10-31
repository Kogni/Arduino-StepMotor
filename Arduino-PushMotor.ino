//Turn the switch to run the motor once
const int ledUt = 13;

//button stuff
const int  buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;
int tilstandNaa = 0;
int tilstandForrige = 0;

//servo stuff
#define servo1  8
#define servo2  9
#define servo3  10
#define servo4  11
int Steps = 0;
boolean Direction = true;
unsigned long last_time;
unsigned long currentMillis ;
int steps_left = 4095;
long time;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledUt, OUTPUT);

  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  pinMode(servo3, OUTPUT);
  pinMode(servo4, OUTPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);
  Serial.println("Sjekk_______________");

  tilstandNaa = LOW;
  if ( buttonState == HIGH ) {
    Serial.println("buttonState HIGH");
    if ( lastButtonState == HIGH ) {
      Serial.println("lastButtonState HIGH");
      tilstandNaa = HIGH;
    } else {
      Serial.println("lastButtonState LOW");
    }
  } else {
    Serial.println("buttonState LOW");
  }
  lastButtonState = buttonState;

  if ( tilstandNaa != tilstandForrige ){
    Serial.println("State change");
    digitalWrite(ledUt, HIGH);
    while (steps_left > 0) { 
      //samtlige kjøres i hver eneste tick
      //tar rundt et sekund å kjøre igjennom
      //skaper tilsvarende lagg når bryter slås av.
      currentMillis = micros();
      if (currentMillis - last_time >= 1000) {
        stepper(1);
        time = time + micros() - last_time;
        last_time = micros();
        steps_left--;
      }
    }
  } else {
    digitalWrite(ledUt, LOW);
  }



  //delay(10);
  Direction = !Direction;
  steps_left = 2047;
    tilstandForrige = tilstandNaa;
}

void stepper(int xw) {
  for (int x = 0; x < xw; x++) {
    switch (Steps) {
      case 0:
        digitalWrite(servo1, LOW);
        digitalWrite(servo2, LOW);
        digitalWrite(servo3, LOW);
        digitalWrite(servo4, HIGH);
        break;
      case 1:
        digitalWrite(servo1, LOW);
        digitalWrite(servo2, LOW);
        digitalWrite(servo3, HIGH);
        digitalWrite(servo4, HIGH);
        break;
      case 2:
        digitalWrite(servo1, LOW);
        digitalWrite(servo2, LOW);
        digitalWrite(servo3, HIGH);
        digitalWrite(servo4, LOW);
        break;
      case 3:
        digitalWrite(servo1, LOW);
        digitalWrite(servo2, HIGH);
        digitalWrite(servo3, HIGH);
        digitalWrite(servo4, LOW);
        break;
      case 4:
        digitalWrite(servo1, LOW);
        digitalWrite(servo2, HIGH);
        digitalWrite(servo3, LOW);
        digitalWrite(servo4, LOW);
        break;
      case 5:
        digitalWrite(servo1, HIGH);
        digitalWrite(servo2, HIGH);
        digitalWrite(servo3, LOW);
        digitalWrite(servo4, LOW);
        break;
      case 6:
        digitalWrite(servo1, HIGH);
        digitalWrite(servo2, LOW);
        digitalWrite(servo3, LOW);
        digitalWrite(servo4, LOW);
        break;
      case 7:
        digitalWrite(servo1, HIGH);
        digitalWrite(servo2, LOW);
        digitalWrite(servo3, LOW);
        digitalWrite(servo4, HIGH);
        break;
      default:
        digitalWrite(servo1, LOW);
        digitalWrite(servo2, LOW);
        digitalWrite(servo3, LOW);
        digitalWrite(servo4, LOW);
        break;
    }
    SetDirection();
  }
}
void SetDirection() {
  if (Direction == 1) {
    Steps++;
  }
  if (Direction == 0) {
    Steps--;
  }
  if (Steps > 7) {
    Steps = 0;
  }
  if (Steps < 0) {
    Steps = 7;
  }
}
