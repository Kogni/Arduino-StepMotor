#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
#define Lys1  2
#define Lys2  3
#define Lys3  4
#define Lys4  5
#define Lys5  13

int Steps = 0;
boolean Direction = true;// gre
unsigned long last_time;
unsigned long currentMillis ;
int steps_left = 4095;
long time;

boolean light = false;

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello World");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Lys1, OUTPUT);
  pinMode(Lys2, OUTPUT);
  pinMode(Lys3, OUTPUT);
  pinMode(Lys4, OUTPUT);
  pinMode(Lys5, OUTPUT);
  // delay(1000);

}
void loop()
{

  digitalWrite(Lys1, HIGH);
  digitalWrite(Lys2, HIGH);
  digitalWrite(Lys3, HIGH);
  digitalWrite(Lys4, HIGH);
  digitalWrite(Lys5, HIGH);

  /*
      if (light == true) {
        light = false;
        Serial.println("Turn off");
        digitalWrite(Lys1, HIGH);
        digitalWrite(Lys2, HIGH);
        digitalWrite(Lys3, HIGH);
        digitalWrite(Lys4, HIGH);
        digitalWrite(Lys5, HIGH);
      } else {
        light = true;
        Serial.println("Turn on");
        digitalWrite(Lys1, LOW);
        digitalWrite(Lys2, LOW);
        digitalWrite(Lys3, LOW);
        digitalWrite(Lys4, LOW);
        digitalWrite(Lys5, LOW);
      }*/

  while (steps_left > 0) {
    currentMillis = micros();
    if (currentMillis - last_time >= 1000) {
      stepper(1);
      time = time + micros() - last_time;
      last_time = micros();
      steps_left--;
    }
  }
  Serial.println(time);
  Serial.println("Wait...!");
  delay(100);
  Direction = !Direction;
  steps_left = 2047;
}

void stepper(int xw) {
  for (int x = 0; x < xw; x++) {
    switch (Steps) {
      case 0:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;
      case 1:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
        break;
      case 2:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break;
      case 3:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break;
      case 4:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      case 5:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      case 6:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      case 7:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;
      default:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
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
