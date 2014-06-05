/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this module implements the library for controlling the LXRobotics Relay Shield
 * @file LXR_Relay_Shield.cpp
 * @license Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0) ( http://creativecommons.org/licenses/by-nc-sa/3.0/ )
 */

#include "LXR_Relay_Shield.h"

static int const RELAY_1_PIN = 2;
static int const RELAY_2_PIN = 3;
static int const RELAY_3_PIN = 8;
static int const RELAY_4_PIN = 9;

/**
 * @brief initializes the LXR_Relay_Shield library
 */
void LXR_Relay_Shield::begin() {
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  pinMode(RELAY_3_PIN, OUTPUT);
  pinMode(RELAY_4_PIN, OUTPUT);
  LXR_Relay_Shield::turn_off(REL1);
  LXR_Relay_Shield::turn_off(REL2);
  LXR_Relay_Shield::turn_off(REL3);
  LXR_Relay_Shield::turn_off(REL4);
}

/**
 * @brief turn a speficic relay on
 */
void LXR_Relay_Shield::turn_on(E_RELAY_SELECT const sel) {
  switch(sel) {
   case REL1: digitalWrite(RELAY_1_PIN, LOW); break; 
   case REL2: digitalWrite(RELAY_2_PIN, LOW); break;
   case REL3: digitalWrite(RELAY_3_PIN, LOW); break;
   case REL4: digitalWrite(RELAY_4_PIN, LOW); break;
   default: break;
  }
}

/**
 * @brief turn a speficic relay off
 */
void LXR_Relay_Shield::turn_off(E_RELAY_SELECT const sel) {
  switch(sel) {
   case REL1: digitalWrite(RELAY_1_PIN, HIGH); break; 
   case REL2: digitalWrite(RELAY_2_PIN, HIGH); break;
   case REL3: digitalWrite(RELAY_3_PIN, HIGH); break;
   case REL4: digitalWrite(RELAY_4_PIN, HIGH); break;
   default: break;
  }  
}

