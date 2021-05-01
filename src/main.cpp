#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFPlayerMini_Fast.h"
SoftwareSerial mySoftwareSerial(10, 11);
DFPlayerMini_Fast DFPlayer;

int button1 = 3; //Loop sound.
int button2 = 6;  
int button3 = 5;
int button4 = 4;
int button5 = 7;
int debounce = 250; //Prevent duplicate button presses
int slowDownCalls = 25; //If calls are sent too close together the last one won't execute, 25ms seems to work well
bool playLoop = false; //Keep track of if we're playing the loop sound
bool buttonpress = false; //Used to determine when to exit while loops
void setup () {
  pinMode(button1, INPUT);
  digitalWrite(button1,HIGH);
  pinMode(button2, INPUT);
  digitalWrite(button2,HIGH);
  pinMode(button3, INPUT);
  digitalWrite(button3,HIGH);
  pinMode(button4, INPUT);
  digitalWrite(button4,HIGH);
  pinMode(button5, INPUT);
  digitalWrite(button5,HIGH);

  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!DFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  DFPlayer.volume(25); //Set volume here.
  DFPlayer.stopRepeat(); //Incase arduino is reset during loop, start with known state.
  delay(slowDownCalls); //Prevent inital loop sound call from failing if button pressed / held during startup.
}

bool soundIsPlaying() {
  delay(25); //Calling this too often results in false being returned incorrectly.
  bool result = DFPlayer.isPlaying();
  return result;
}

void playLoopSound(){
    buttonpress = true;
    while (buttonpress){
      if (!soundIsPlaying()){
        playLoop = true;
        DFPlayer.playFolder(1, 001);
        DFPlayer.startRepeat();
        Serial.println("Start sound loop");
        buttonpress = false;
        delay(debounce);
      }
    }
}


void stopLoopSound(){
    playLoop = false;
    DFPlayer.stopRepeat();
    Serial.println("Stop sound loop");
    delay(debounce);
}

void loop () { 

//Button 1 / background loop sound
 if (digitalRead(button1) == LOW)
  {
    if (!playLoop){
      delay(slowDownCalls);
      playLoopSound();
      delay(debounce);
    }
    else {
      delay(slowDownCalls);
      stopLoopSound();
      delay(debounce);
    }
  }

  //BYC
  if (digitalRead(button2) == LOW)
  { 
    buttonpress = true;
    if (playLoop)
    {
      stopLoopSound();
      while ((buttonpress) == true){
        if (!soundIsPlaying()){
          delay(slowDownCalls);
          DFPlayer.playFolder(2, 102);
          Serial.println("By your command with loop");
          while ((buttonpress) == true)
          {
            if (!soundIsPlaying())
            {
              delay(slowDownCalls);
              playLoopSound();
              buttonpress = false;
              delay(slowDownCalls);
            }
          }       
        }
      }
    }
    else {
      while (buttonpress && !soundIsPlaying())
      {
      delay(slowDownCalls);
      DFPlayer.playFolder(2, 002);
      Serial.println("By your command without loop");
      buttonpress = false;
      delay(slowDownCalls);
      }     
    }
  }

  //WIYC
  if (digitalRead(button3) == LOW)
  { 
    buttonpress = true;
    if (playLoop)
    {
      stopLoopSound();
      while ((buttonpress) == true){
        if (!soundIsPlaying()){
          delay(slowDownCalls);
          DFPlayer.playFolder(3, 103);
          Serial.println("What is your command with loop");
          while ((buttonpress) == true)
          {
            if (!soundIsPlaying())
            {
              delay(slowDownCalls);
              playLoopSound();
              buttonpress = false;
              delay(slowDownCalls);
            }
          }       
        }
      }
    }
    else {
      while (buttonpress && !soundIsPlaying())
      {
      delay(slowDownCalls);
      DFPlayer.playFolder(3, 003);
      Serial.println("What is your command without loop");
      buttonpress = false;
      delay(slowDownCalls);
      }     
    }
  }

  //TISNC
  if (digitalRead(button4) == LOW)
  { 
    buttonpress = true;
    if (playLoop)
    {
      stopLoopSound();
      while ((buttonpress) == true){
        if (!soundIsPlaying()){
          delay(slowDownCalls);
          DFPlayer.playFolder(4, 104);
          Serial.println("The information is not complete with loop");
          while ((buttonpress) == true)
          {
            if (!soundIsPlaying())
            {
              delay(slowDownCalls);
              playLoopSound();
              buttonpress = false;
              delay(slowDownCalls);
            }
          }       
        }
      }
    }
    else {
      while (buttonpress && !soundIsPlaying())
      {
      delay(slowDownCalls);
      DFPlayer.playFolder(4, 004);
      Serial.println("The information is not complete without loop");
      buttonpress = false;
      delay(slowDownCalls);
      }     
    }
  }


  //SFID
  if (digitalRead(button5) == LOW)
  { 
    buttonpress = true;
    if (playLoop)
    {
      stopLoopSound();
      while ((buttonpress) == true){
        if (!soundIsPlaying()){
          delay(slowDownCalls);
          DFPlayer.playFolder(5, 105);
          Serial.println("Scan for ID with loop");
          while ((buttonpress) == true)
          {
            if (!soundIsPlaying())
            {
              delay(slowDownCalls);
              playLoopSound();
              buttonpress = false;
              delay(slowDownCalls);
            }
          }       
        }
      }
    }
    else {
      while (buttonpress && !soundIsPlaying())
      {
      delay(slowDownCalls);
      DFPlayer.playFolder(5, 005);
      Serial.println("Scan for ID without loop");
      buttonpress = false;
      delay(slowDownCalls);
      }     
    }
  }
}