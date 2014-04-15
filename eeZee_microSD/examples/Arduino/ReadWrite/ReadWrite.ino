/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
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
  Serial.print("Initializing SD card......");
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
  pinMode(10, OUTPUT);
   
  if (!SD.begin(10)) {
    Serial.println("FAIL");
  } else {
    Serial.println("PASS");
  
    boolean result = true;
    char *teststring = "abcdefghijklmnop";
  
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    myFile = SD.open("test.txt", FILE_WRITE);
    
    // if the file opened okay, write to it:
    if (myFile) {
      Serial.print("Writing to test.txt.......");
      myFile.print(teststring);
  	// close the file:
      myFile.close();
      Serial.println("PASS");
    } else {
      // if the file didn't open, print an error:
      Serial.println("FAIL - error opening test.txt");
      result = false;
    }
  
    // re-open the file for reading:
    char s[128];
    char *t = s;
    char c;
    Serial.print("Reading test.txt..........");
    myFile = SD.open("test.txt");
    if (myFile) {
      Serial.println("PASS");
      Serial.print("Verifying test.txt........");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        *t++ = myFile.read();
      }
      *t = 0;
      myFile.close();
      // Are the contents a match?
      if (!strcmp(s, teststring)) {
        Serial.println("PASS");
      } else {
        Serial.println("FAIL");
        Serial.print("/");
        Serial.print(s);
        Serial.print("/");
        //Serial.print(teststring);
        Serial.print("/");
        Serial.println();
        result = false;
      }
      
    } else {
      // if the file didn't open, print an error:
      Serial.println("FAIL");
      result = false;    
    }
    Serial.print("Does test.txt exist? .....");
    if (SD.exists("test.txt")) {
      Serial.println("PASS");
    }
    else {
      Serial.println("FAIL");
      result = false;
    }  
    
    // delete the file:
    Serial.print("Removing test.txt.........");
    SD.remove("test.txt");
    if (SD.exists("test.txt")){ 
      Serial.println("FAIL");
      result = false;
    }
    else {
      Serial.println("PASS");  
    }
  
    Serial.println();
    if (result) {
      Serial.println("+++ ALL PASS +++");
    } else {
      Serial.println("!!! FAIL !!! ");
    }  
    Serial.println();
    Serial.println();
  }
  delay(5000);
}



