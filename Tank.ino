// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 

/* ------------------------------- */
/* ------------------------------- */
/* ELITE TANK CODE BY MR. FIELDMAN */
/* ------------------------------- */
/* ------------------------------- */

/*
Front:
  Left:   11    Forward: write(0)    Back: write(180)
  Right:  9     Forward: write(180)  Back: write(0)
  
Back:
  Left:   6     Forward: writeMicrosecond(2000) Back: 1000
  Right:  3     Forward: writeMicrosecond(1000) Back: 2000

*/

 
Servo mtrFL;
Servo mtrFR;
Servo mtrRL;
Servo mtrRR;

 
void setup() { 
  mtrFL.attach(11);  // attaches the servo on pin 9 to the servo object 
  mtrFR.attach(9);
  mtrRL.attach(6);
  mtrRR.attach(3);
} 


/* Each speed must be from -1.0 to 1.0.
   -1.0 is backwards full speed
    1.0 is forwards full speed
    0.0 is stop
 */
void setTreadSpeed(float left, float right) {
  /* Sanity */
  if (left > 1.0)   left = 1.0;
  if (left < -1.0)  left = -1.0;
  if (right > 1.0)  right = 1.0;
  if (right < -1.0) right = -1.0;
  
  /* Fronts - must be 0 to 180 (from -1.0 to 1.0) */
  int iFrontLeft  = 180 - (left  + 1.0) * 90;
  int iFrontRight =       (right + 1.0) * 90;
  
  /* Backs  - must be 1000 to 2000 */
  int iBackLeft   = 1000 + (left  + 1.0) * 500;
  int iBackRight  = 2000 - (right + 1.0) * 500;
  
  /* Set motors */
  mtrFL.write(iFrontLeft);
  mtrFR.write(iFrontRight);
  mtrRL.writeMicroseconds(iBackLeft);
  mtrRR.writeMicroseconds(iBackRight);
}

 
void loop() 
{ 
  
  for (float s = -1.0; s < 1.0; s += 0.1) {
    setTreadSpeed(s, s * -1);
    delay(200);
  }
  
  setTreadSpeed(1, 1);
  delay(4000);
  setTreadSpeed(-1, -1);
  delay(4000);
  
  setTreadSpeed(0,0);
  delay(2000);
  
  
  #if 0
  static int doit = 1;
  
  if (0) {
  myservo.write(90);
  myotherservo.write(90);
  myotherservo2.write(90);
  myotherservo3.write(90);
  }
  
  if (0) {
  myservo.write(120);
  myotherservo.write(120);
  myotherservo2.write(60);
  myotherservo3.write(60);
  }
  
  if (doit) {
    doit = 0;
  myservo.write(180);
  myotherservo.write(180);
  //myotherservo2.write(0);
  //myotherservo3.write(0);
  
  myotherservo2.writeMicroseconds(1000);
  myotherservo3.writeMicroseconds(2000);
  }
  
  
  delay(3000);
  
  if (1) {
  myservo.write(90);
  myotherservo.write(90);
  myotherservo2.write(90);
  myotherservo3.write(90);
  }
  
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(200);
  
  return;
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
  #endif
} 
