const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int tilstand = 0;

int buttonStateForrigeForrige = 0;

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  buttonState = digitalRead(buttonPin);
  //if ((millis() - forrigeSjekk) > 2000) {
  //Serial.println((millis() - forrigeSjekk));
  //forrigeSjekk = millis();
  Serial.println("Sjekk");
  tilstand = HIGH;
  if ( buttonState == LOW ) {
    if ( lastButtonState == LOW ) {
      tilstand = LOW;
    }
  }

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    //Serial.println("tilstand=" + tilstand);


    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      //Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
  }
  buttonStateForrigeForrige = lastButtonState;
  lastButtonState = buttonState;

  /*if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
    } else {
    digitalWrite(ledPin, LOW);
    }*/

  if (tilstand == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  //delay(10);

}
