//Turn the switch to toggle LED on/off
const int buttonIn = 3;     // the number of the pushbutton pin
const int buttonOut = 2;
const int ledPin =  13;      // the number of the LED pin

// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState = LOW;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin
int reading;

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(115200);
  pinMode(buttonIn, INPUT);
  pinMode(buttonOut, OUTPUT);
  pinMode(ledPin, OUTPUT);
}


void loop() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buttonOut, HIGH);
  
  reading = digitalRead(buttonIn);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
    lastButtonState = reading;
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    //digitalWrite(ledPin, HIGH);
    /*
    digitalWrite(ledPin, !reading);
    if ( reading == HIGH ) {
      Serial.println("Reading=HIGH");
      digitalWrite(ledPin, LOW);
    } else {
      Serial.println("Reading=LOW");
      digitalWrite(ledPin, HIGH);
    }*/
    if ( lastButtonState == HIGH ) {
      Serial.println("lastButtonState=HIGH");
    } else {
      Serial.println("lastButtonState=LOW");
    }
    if (buttonState != lastButtonState) {
      buttonState = lastButtonState;
      if (buttonState == HIGH) {
        ledState = !ledState;
        //digitalWrite(ledPin, ledState);
      }
    }
  }
}
