//Turn the switch to turn the LED on/off
const int  buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
int lastButtonState = 0;
int tilstand = 0;
int buttonStateForrigeForrige = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  buttonState = digitalRead(buttonPin);
  
  tilstand = LOW;
  if ( buttonState == HIGH ) {
    Serial.println("buttonState HIGH");
    if ( lastButtonState == HIGH ) {
      Serial.println("lastButtonState HIGH");
      tilstand = HIGH;
    } else {
      Serial.println("lastButtonState LOW");
    }
  } else {
    //Serial.println("buttonState LOW");
  }
  
  if (buttonState != lastButtonState) {

    if (buttonState == HIGH) {
      Serial.println("on");
    } else {
      Serial.println("off");
    }
  }
  buttonStateForrigeForrige = lastButtonState;
  lastButtonState = buttonState;
  if (tilstand == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
