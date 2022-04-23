#include <Braccio.h>
#include <Servo.h>
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;
int serialData = 0;
int firstRun = true;
void setup()
{
  Serial.begin(9600);
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees
  //Shoulder (M2): 45 degrees
  //Elbow (M3): 180 degrees
  //Wrist vertical (M4): 180 degrees
  //Wrist rotation (M5): 90 degrees
  //gripper (M6): 10 degrees
  Braccio.begin();
}
void loop()
{
  if (firstRun) {
    Serial.println("--EXAMPLE PROGRAM FOR ARDUINO AND BRACCIO--");
    Serial.println("");
    Serial.println("!!ATTENTION!! BEFORE UPLOADING AN UPDATED VERSION OF THE PROGRAM BRING THE ROBOT IN ITS DEFAULT POSITION TO AVOID DAMAGE TO THE DEVICE");
    Serial.println("");
    Serial.println("Type numbers in the input above and press Enter to control the robot:");
    Serial.println("1: Default position");
    Serial.println("2: Mouse click");
    Serial.println("3: Pick up the sponge, look at it and put it back");
    Serial.println("4: Take the sponge and place it on the right");
    Serial.println("5: Pick up and offer sponge");
    Serial.println("6: Discard sponge");
    Serial.println("7: Robot repeats given movements several times");
    Serial.println("8: Robot bows");
    Serial.println("9: Robot grabs distant sponge and offers it");
    Serial.println("");
    Serial.println("Code in ASCII that the robot sees:");
    Serial.println("");
    Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
    firstRun = false;
  }
  if (Serial.available() > 0)
  {
    //Arduino reads the Serial Monitor (Tools -> Serial Monitor)
    //and returns what was read in ASCII
    //Users can send numbers or letters to the robot
    //Robot reacts based on case distinctions
    serialData = Serial.read();
    Serial.println(serialData);
      //The read is compared with the pre-programmed commands
      //and executed if matched
      if(serialData == 49){
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
      }  else if(serialData == 50) {
        //Robot clicks on a mouse that needs to be positioned correctly
         Braccio.ServoMovement(20,         180, 50, 90, 10, 90,  73);
         delay(1000);
         Braccio.ServoMovement(20,         180, 50, 55, 10, 90,  73);
         Braccio.ServoMovement(20,         180, 50, 90, 10, 90,  73);
      }  else if(serialData == 51) {
        //Robot picks up sponge and puts it back in the same spot
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
        Braccio.ServoMovement(20,         90, 50, 45, 10, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         90, 50, 45, 10, 90,  30);
        delay(1000);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  30);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  30);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 0,  30);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 180,  30);
        Braccio.ServoMovement(20,         90, 50, 45, 10, 90,  30);
        Braccio.ServoMovement(20,         90, 50, 45, 10, 90,  10);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  10);
      }  else if(serialData == 52) {
        //Robot takes sponge and puts it to the right
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  10);
        delay(2000);
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  40);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  40);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
      }  else if(serialData == 53) {
        //Robot picks up sponge on the right and offers it, after 5 seconds it puts it down again
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
        Braccio.ServoMovement(20,         0, 50, 60, 10, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  10);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  35);
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  35);
        delay(5000);
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  40);
      }  else if(serialData == 54) {
        //Robot picks up sponge on the right and offers it
        Braccio.ServoMovement(20,         0, 50, 60, 10, 90,  35);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  35);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  10);
      }  else if(serialData == 55) {
        //Robot makes specified movements several times
        for(int i = 0; i < 5; i++){
          Braccio.ServoMovement(20,           0,  15, 180, 170, 0,  73);
          delay(1000);
          Braccio.ServoMovement(20,           180,  165, 0, 0, 180,  10);  
          delay(1000);
        }
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
      }  else if(serialData == 56) {
        //Robot bows
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         90, 45, 45, 45, 90,  10);
        delay(2000);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         45, 90, 90, 90, 90,  10);
        Braccio.ServoMovement(20,         45, 45, 45, 45, 90,  10);
        delay(2000);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         135, 90, 90, 90, 90,  10);
        Braccio.ServoMovement(20,         135, 45, 45, 45, 90,  10);
        delay(2000);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
      }  else if(serialData == 57) {
        //Robot grabs distant sponge on the right
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
        Braccio.ServoMovement(20,         0, 90, 90, 90, 90,  10);
        Braccio.ServoMovement(20,         0, 10, 65, 80, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         0, 10, 65, 80, 90,  35);
        delay(1000);
        Braccio.ServoMovement(20,         0, 90, 90, 90, 90,  35);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  35);
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  35);
        delay(5000);
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  40);
    }
  } 
  delay(1000); 
}
