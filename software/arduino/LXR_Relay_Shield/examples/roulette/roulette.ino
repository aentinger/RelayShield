/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch demonstrates how to use the LXR_Relay_Shield library by creating a roulette-like rotating light on the relay shield
 * @file roulette.ino
 */
 
 #include "LXR_Relay_Shield.h"
 
 void setup() {
   LXR_Relay_Shield::begin();
 }
 
 void loop() {
   static E_RELAY_SELECT current_relais = REL1;
   
   LXR_Relay_Shield::turn_on(current_relais);
   delay(250);
   LXR_Relay_Shield::turn_off(current_relais);
   delay(250);
   
   switch(current_relais) {
   case REL1: current_relais = REL2; break; 
   case REL2: current_relais = REL3; break;
   case REL3: current_relais = REL4; break;
   case REL4: current_relais = REL1; break;
   default: break;
  }  
 }
