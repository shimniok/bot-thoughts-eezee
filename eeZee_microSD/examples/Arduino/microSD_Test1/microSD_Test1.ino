/*
  SD card basic file example
 
 This example shows how to create and destroy an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
 
 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 
 */
#include <SD.h>

File myFile;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
}

void loop()
{
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
  pinMode(10, OUTPUT);

  delay(5000);

  if (!SD.begin(10)) {
    Serial.println("[FAIL] initialization failed.");
  } else {
    Serial.println("[PASS] initialization done.");
  
    if (SD.exists("example.txt")) {
      Serial.println("[FAIL] example.txt already exists.");
    }
    else {
      Serial.println("[PASS] no example.txt, good.");
    }
  
    // open a new file and immediately close it:
    myFile = SD.open("example.txt", FILE_WRITE);
    myFile.close();
  
    // Check to see if the file exists: 
    if (SD.exists("example.txt")) {
      Serial.println("[PASS] example.txt created.");
    }
    else {
      Serial.println("[FAIL] example.txt not created.");  
    }
  
    // delete the file:
    SD.remove("example.txt");
  
    if (SD.exists("example.txt")){ 
      Serial.println("[FAIL] example.txt removed.");
    }
    else {
      Serial.println("[PASS] example.txt not removed.");  
    }
  }
  
}



