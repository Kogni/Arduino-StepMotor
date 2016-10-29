const int LED1 = 13;

const int servoOut1 = 12;
const int servoOut2 = 11;
const int servoOut3 = 10;
const int servoOut4 = 9;

int val = 0;

#define IN1  9
#define IN2  10
#define IN3  11
#define IN4  12
int Steps = 0;
boolean Direction = true;// gre
unsigned long last_time;
unsigned long currentMillis ;
int steps_left = 4095;
long time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(servoOut1, OUTPUT);
  pinMode(servoOut2, OUTPUT);
  pinMode(servoOut3, OUTPUT);
  pinMode(servoOut4, OUTPUT);
  pinMode(LED1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(servoOut1, HIGH);
  digitalWrite(servoOut2, HIGH);
  digitalWrite(servoOut3, HIGH);
  digitalWrite(servoOut4, HIGH);
  /*
    val = digitalRead(servoIn);
    digitalWrite(LED1, val);
    digitalWrite(servoOut, HIGH);
    if ( val == LOW ) {
      //digitalWrite(servoOut, !val);
    } else {
      //digitalWrite(servoOut, !val);
    }
  */
  digitalWrite(LED1, HIGH);
  //delay(100);
  //digitalWrite(LED1, LOW);
  //delay(100);

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
  //4095 steps/380 grader=11 steps/1 grad
  //1800 grader=2047
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