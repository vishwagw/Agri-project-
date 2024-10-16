//libraires
#include <Servo.h>;
Servo servo;

int eastLDR = A0;
int westLDR = A1;
int east = 0;
int west = 0;
int error = 0;
int calibration = 600;
int servoposition = 90;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  east = calibration + analogRead(eastLDR);
  west = analogRead(westLDR);

  if (east< 350 && west < 350) {
    while (servoposition <= 150) {
      servoposition++;
      servo.write(servoposition);
      delay(100);
    }
  }
  error = east - west;
  if (error > 15) {
    if (servoposition <= 150) {
      servoposition++;
      servo.write(servoposition);
    }
  }
  else if (error <- 15) {
    if (servoposition > 20) {
      servoposition--;
      servo.write(servoposition);
    }
  }
  delay(100);
}
