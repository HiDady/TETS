#include <Servo.h>

Servo Servo_X;
Servo Servo_Y;
Servo Servo_Grip;

#define BUTTON 2

boolean state = false;
boolean automatedMode = true; // Set to true for automated movement

void setup()
{
  Servo_X.attach(3);
  Servo_Y.attach(5);
  Servo_Grip.attach(6);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
  if (automatedMode) {
    // Automated movement sequence
    automatedMovement();
  } else {
    // Manual control via button press
    manualControl();
  }
}

void automatedMovement() {
  // Default position
  defaultPosition();

  // Move to the right and pick up the ball
  moveRightAndPickUpBall();

  // Go to the left and put down the ball
  goLeftAndPutDownBall();
}

void defaultPosition() {
  // Move to default position
  Servo_X.write(90); // Middle position for Servo_X
  Servo_Y.write(90); // Middle position for Servo_Y
  Servo_Grip.write(0); // Close the grip
  delay(1000); // Wait for 1 second
}

void moveRightAndPickUpBall() {
  // Move arm to the right
  Servo_X.write(180); // Move Servo_X to the rightmost position
  delay(1000); // Wait for the arm to reach the position

  // Open the grip
  Servo_Grip.write(90); // Open the grip
  delay(1000); // Wait for the grip to open

  // Lower Servo_Y
  Servo_Y.write(5); // Lower Servo_Y to pick up the ball
  delay(1000); // Wait for the arm to lower

  // Close the grip to pick up the ball
  Servo_Grip.write(0); // Close the grip
  delay(1000); // Wait for the grip to close

  // Raise Servo_Y
  Servo_Y.write(100); // Raise Servo_Y
  delay(1000); // Wait for the arm to raise
}

void goLeftAndPutDownBall() {
  // Lower Servo_Y
  Servo_Y.write(100); // Lower Servo_Y
   Servo_X.write(180); //down the second servp
  delay(1000); // Wait for the arm to lower

  // Open the grip
  Servo_Grip.write(0); // Open the grip
  delay(1000); // Wait for the grip to open

  // Move arm to the left
  Servo_X.write(0); // Move Servo_X to the leftmost position
  delay(1000); // Wait for the arm to reach the position
 // Raise Servo_Y
 

   Servo_Y.write(50); // Raise Servo_Y
  delay(1000); // Wait for the arm to raise
    Servo_Grip.write(80); // Close the grip
  delay(1000); // Wait for the grip to close
  // Close the grip to put down the ball
   Servo_Y.write(180); // Raise Servo_Y
  delay(1000); // Wait for the arm to raise
  // Close the grip to put down the ball


 
}

void manualControl() {
  // Your manual control logic goes here
}
