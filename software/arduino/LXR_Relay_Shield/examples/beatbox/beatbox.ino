/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch demonstrates how an LXRobotics Relay Shield can be utilized to be a beatbox
 * @file beatbox.ino
 */
 
 #include "LXR_Relay_Shield.h"
 
 void setup() {
   LXR_Relay_Shield::begin();
 }
 
 void loop() {
   LXR_Relay_Shield::turn_on(REL1);
   delay(250);
   LXR_Relay_Shield::turn_off(REL1);
   delay(250);
   LXR_Relay_Shield::turn_on(REL2);
   delay(250);
   LXR_Relay_Shield::turn_off(REL2);
   delay(250);
   LXR_Relay_Shield::turn_on(REL3);
   LXR_Relay_Shield::turn_on(REL4);
   delay(500);
   LXR_Relay_Shield::turn_off(REL3);
   LXR_Relay_Shield::turn_off(REL4);
   delay(500);
 }
