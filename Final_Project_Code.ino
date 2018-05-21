/*------------------------------------------------------------------------
  Example sketch for Adafruit Thermal Printer library for Arduino.
  Demonstrates a few text styles & layouts, bitmap printing, etc.

  IMPORTANT: DECLARATIONS DIFFER FROM PRIOR VERSIONS OF THIS LIBRARY.
  This is to support newer & more board types, especially ones that don't
  support SoftwareSerial (e.g. Arduino Due).  You can pass any Stream
  (e.g. Serial1) to the printer constructor.  See notes below.

  You may need to edit the PRINTER_FIRMWARE value in Adafruit_Thermal.h
  to match your printer (hold feed button on powerup for test page).
  ------------------------------------------------------------------------*/
#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_8 = CapacitiveSensor(4, 8); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
#include "Adafruit_Thermal.h"
#include "adalogo.h"
#include "adaqrcode.h"

int LED = 8;
int buttonpin = 3;
//FIND A 10K resistor! Check if this is still relevant.

// Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
// If using hardware serial instead, comment out or remove these lines:

#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
// Then see setup() function regarding serial & printer begin() calls.

// Here's the syntax for hardware serial (e.g. Arduino Due) --------------
// Un-comment the following line if using hardware serial:

//Adafruit_Thermal printer(&Serial1);      // Or Serial2, Serial3, etc.

// -----------------------------------------------------------------------

void setup() {
  cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
  pinMode(7, OUTPUT);
  // pinMode(7, OUTPUT); digitalWrite(7, LOW);
  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  pinMode(5, OUTPUT); digitalWrite(5, LOW);
  pinMode (buttonpin, INPUT);
  // cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
  // Serial.begin(9600);
  // pinMode(7, OUTPUT);
  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  pinMode(LED, OUTPUT); digitalWrite(LED, LOW);
  Serial.begin(9600);
  mySerial.begin(19200);  // Initialize SoftwareSerial
  //Serial1.begin(9600); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)



}
void box(char *string) {
  uint8_t i, len = strlen(string);
  //printer.write(0xDA);//upper-left corner
  for (i = 0; i < len; i++)printer.write(0xC4);// Top Edge
 // printer.write(0xBF);// Upper-right corner
  printer.setSize('S'); //Size 
  //printer.println();//NewLine/Feed
  //printer.write(0xB3); //left edge
  printer.print(string);
  //printer.println(sensor1); How to print the capacity ?
  //printer.println(0xB3);
 // printer.println(0xB3);
  //printer.println();//Newline/Feed
 // printer.write(0xC0); //Lower-Left corner
  for (i = 0; i < len; i++) printer.write(0xC4);//Bottom Edge
  //printer.write(0xD9); //Lower-right Corner
  printer.println();//NewLine/Feed
}


void loop() {
  long sensor1 =  cs_4_8.capacitiveSensor(50);

  Serial.println(sensor1);  // print sensor output
  //if(4999 % 3 == 0)

  if (sensor1 >= 4000) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      // printer.println(F("The world is your oyster+"));
      box("The World is Your Oyster+");
    } else {
      box("You Are Special-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

      } else if (sensor1 >= 2950) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Have Empathy+");
    } else {
      box("Don't Be Too Manipulated By Emotions-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 2750) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Clean Your Environment. Your Making Someone Suffer+");
    } else {
      box("You Don't Have to Clean Up Everybodies Mess-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

      } else if (sensor1 >= 2650) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Take a Break+");
    } else {
      box("Work Harder-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

      } else if (sensor1 >= 2550) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Do Not Punish People with Your Pettiness+");
    } else {
      box("Do Not Punish Those Who Try. Punish Those Who Deliberately Disregard-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults
    
      } else if (sensor1 >= 2500) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Take the Risk+");
    } else {
      box("Don't Take the Risk-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

      } else if (sensor1 >= 2450) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Beware. Your Home Relationship Is Dissolving+");
    } else {
      box("Do Not Neglect the Needs of Others-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults
        
  } else if (sensor1 >= 2300) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Go Home. Rest+");
    } else {
      box("Go Out. Luck Awaits You-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 2250) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Communicate, No One Can Read Your Mind+");
    } else {
      box("Communicate, Use Your Words-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 2150) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Realize That The World Doesn't Revolve Around You+");
    } else {
      box("Realize That Despite Your Smallness You Have Infinite Potential-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 2000) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Recognize and Respect the Power of Others in Your Life+");
    } else {
      box("Come Again Later-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 1850) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("You Need to Think of Who You Are Hurting+");
    } else {
      box("You Need to Think of REALLY Why You are Behaving this Way-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 1750) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Think Strategically and be Kind +");
    } else {
      box("Think Strategically and Pick Your Battles -");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 1650) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("You Will Reap What You Sow Very Soon+");
    } else {
      box("You Will Reap What You Sow in the Fall-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 1500) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Treat Yo Self+");
    } else {
      box("Treat Yo Savings-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  } else if (sensor1 >= 1300) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Be Aware of +");
    } else {
      box("Be Aware of the Ides of August.-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults
    
  } else if (sensor1 >= 1250) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Be Considerate, Don't be Petty+");
    } else {
      box("Be Considerate, Not Acquiescent. You are Hurting Yourself-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  }   else if (sensor1 >= 1000) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    if (sensor1 % 2 == 0) {
      box("Take the Higher Road+");
    } else {
      box("The Low Road Will Hurt Everyone, Especially You.-");
    }

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  }   else if (sensor1 == 666) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    printer.println(F("Touch Me"));

    printer.println(F(""));
    printer.println(F(""));
    printer.println(F(""));
    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(3000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults

  }


}



