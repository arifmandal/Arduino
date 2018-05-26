#include <X113647Stepper.h>

static const int STEPS_PER_REVOLUTION = 64 * 32;  // change this to fit the number of steps per revolution for your motor

// initialize the stepper library on pins 8 through 11:
X113647Stepper myStepper(STEPS_PER_REVOLUTION, 8, 9, 10, 11);

void setup() {
  // set the speed in rpm:
  myStepper.setSpeed(20);
}

void loop() {
  // step one revolution  in one direction:
  myStepper.step(STEPS_PER_REVOLUTION);
  delay(500);

  // step one revolution in the other direction:
  myStepper.step(-STEPS_PER_REVOLUTION);
  delay(500);
}

