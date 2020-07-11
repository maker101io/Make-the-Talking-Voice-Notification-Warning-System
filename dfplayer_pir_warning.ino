#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#define SENSORPIN 9
#define PAUSETIME 20000

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  pinMode(SENSORPIN, INPUT);

  Serial.println();
  Serial.println(F("Initializing DFPlayer..."));

  //Use softwareSerial to communicate with MP3
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  //Set volume value (From 0 to 30)
  myDFPlayer.volume(25);
}

void sensorActivated() {
  int pirSensor = digitalRead(SENSORPIN);
  if(pirSensor == HIGH)
  {
    Serial.println("Sensor Activated");
    Serial.println("DFPlayer Working...");
    myDFPlayer.play(1);
  }
  return;
}

void loop() {
  sensorActivated();
  delay(PAUSETIME);
}
