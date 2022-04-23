//Roboterprogramm geschrieben von Leon Beckert
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
    Serial.println("--BEISPIELPROGRAMME ARDUINO UNO BRACCIO--");
    Serial.println("");
    Serial.println("!!HINWEIS!! VOR DEM UPLOAD EINES ANGEPASSTEN PROGRAMMS DEN ROBOTER IN DIE GRUNDPOSITION BRINGEN,  DA ER SONST SCHADEN NEHMEN KANN");
    Serial.println("");
    Serial.println("Zahlen in die Eingabe oben eingeben und Enter drücken, um den Roboter zu steuern:");
    Serial.println("1: Grundposition");
    Serial.println("2: Mausklick");
    Serial.println("3: Schwamm aufheben, betrachten und zurücklegen");
    Serial.println("4: Schwamm entgegennehmen und rechts ablegen");
    Serial.println("5: Schwamm aufheben und anbieten");
    Serial.println("6: Schwamm ablegen");
    Serial.println("7: Roboter wiederholt mehrmals vorgegebene Bewegungen");
    Serial.println("8: Roboter verneigt sich");
    Serial.println("9: Roboter greift weit entfernten Schwamm und bietet ihn an");
    Serial.println("");
    Serial.println("Code in ASCII, den der Roboter sieht:");
    Serial.println("");
    Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
    firstRun = false;
  }
  if (Serial.available() > 0)
  {
    //Arduino liest den Serial Monitor aus (Tools -> Serial Monitor) 
    //und gibt das gelesene in ASCII zurück
    //Nutzer können Zahlen oder Buchstaben an den Roboter senden
    //Roboter reagiert anhand von Fallunterscheidungen
    serialData = Serial.read();
    Serial.println(serialData);
      //Das gelesene wird mit den vorprogrammierten Befehlen verglichen
      //und bei Übereinstimmung ausgeführt
      if(serialData == 49){
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
      }  else if(serialData == 50) {
        //Roboter klickt auf eine Maus, die man richtig positionieren muss
         Braccio.ServoMovement(20,         180, 50, 90, 10, 90,  73);
         delay(1000);
         Braccio.ServoMovement(20,         180, 50, 55, 10, 90,  73);
         Braccio.ServoMovement(20,         180, 50, 90, 10, 90,  73);
      }  else if(serialData == 51) {
        //Roboter hebt Schwamm auf und legt ihn an die gleiche Stelle zurück
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
        //Roboter nimmt Schwamm entgegen und legt ihn rechts neben sich
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  10);
        delay(2000);
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  40);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  40);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
      }  else if(serialData == 53) {
        //Roboter nimmt Schwamm rechts auf und bietet ihn an, nach 5 sekunden legt er ihn wieder ab
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
        Braccio.ServoMovement(20,         0, 50, 60, 10, 90,  10);
        delay(1000);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  10);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  35);
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  35);
        delay(5000);
        Braccio.ServoMovement(20,         90, 90, 90, 45, 90,  40);
      }  else if(serialData == 54) {
        //Roboter nimmt Schwamm rechts auf und bietet ihn an
        Braccio.ServoMovement(20,         0, 50, 60, 10, 90,  35);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  35);
        Braccio.ServoMovement(20,         0, 50, 45, 10, 90,  10);
      }  else if(serialData == 55) {
        //Roboter macht mehrmals vorgegebene Bewegungen
        for(int i = 0; i < 5; i++){
          Braccio.ServoMovement(20,           0,  15, 180, 170, 0,  73);
          delay(1000);
          Braccio.ServoMovement(20,           180,  165, 0, 0, 180,  10);  
          delay(1000);
        }
        Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);
      }  else if(serialData == 56) {
        //Roboter verneigt sich
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
        //Roboter greift weit entfernten Schwamm rechts
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
