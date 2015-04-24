/*
  eeZee microSD test jig firmware

  Tests boards with feedback via RG LED and Digole OLED display.

  Creates and removes a file on the SD card. If it can do that, the
  board is good.

  SD card attached to SPI bus as follows:

  MOSI - pin 11
  MISO - pin 12
  CLK - pin 13
  CS - pin 10

Based on example code:
 created   Nov 2010
 by David A. Mellis

 modified 9 Apr 2012
 by Tom Igoe

 modified 24 Apr 2015
 by Michael Shimniok

 MIT License

*/
#include <SD.h>
#include <SoftwareSerial.h>

#define RED   19
#define GREEN 18

File myFile;

SoftwareSerial lcd(7, 8); // RX, TX

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);

  lcd.begin(9600);
  lcd.print("CL");
  
  digitalWrite(10, HIGH);
  pinMode(10, OUTPUT);

  pinMode(RED, OUTPUT);
  digitalWrite(RED, LOW);
  
  pinMode(GREEN, OUTPUT);
  digitalWrite(GREEN, LOW);
  
  for (int i=0; i < 3; i++) {
    digitalWrite(GREEN, HIGH);
    delay(50);
    digitalWrite(GREEN, LOW);
    delay(200);
  }

  while(!SD.begin(10)) {
    lcd.println("TT[F]init\nTRT");
    Serial.println("[FAIL] initialization failed.");
    digitalWrite(RED, HIGH);
    delay(1000);
  }
  digitalWrite(RED, LOW);
  lcd.println("TT[P]init card\nTRT");
  Serial.println("[PASS] initialization done.");


  bool pass = true;
  
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
  if (SD.exists("example.txt")) {
    Serial.println("[FAIL] example.txt already exists.");
    lcd.println("TT[F]file exists\nTRT");
    pass = false;
  } else {
    Serial.println("[PASS] no example.txt, good.");
  }

  // open a new file and immediately close it:
  myFile = SD.open("example.txt", FILE_WRITE);
  myFile.close();

  // Check to see if the file exists: 
  if (SD.exists("example.txt")) {
    Serial.println("[PASS] example.txt created.");
    lcd.println("TT[P]create file\nTRT");
  } else {
    Serial.println("[FAIL] example.txt not created.");  
    lcd.println("TT[F]create file\nTRT");
    pass = false;
  }

  // delete the file:
  SD.remove("example.txt");

  if (SD.exists("example.txt")){ 
    lcd.println("TT[F]remove file\nTRT");
    Serial.println("[FAIL] example.txt not removed.");  
    pass = false;
  } else {
    lcd.println("TT[P]remove file\nTRT");
    Serial.println("[PASS] example.txt removed.");
  }

  if (pass) {
    lcd.println("TT---------------\nTRT");
    lcd.println("TT[P]BOARD OK\nTRT");
    Serial.println("----\n[PASS] ALL TESTS PASS\n----\n");
  } else {
    Serial.println("----\n[FAIL] one or more tests failed\n----\n");
  }
  
  digitalWrite(pass ? GREEN : RED, HIGH);
  digitalWrite(10, LOW);
}

void loop() {
  while(1);
}
