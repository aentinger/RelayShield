/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this module implements the library for controlling the LXRobotics Relay Shield
 * @file LXR_Relay_Shield.h
 * @license Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0) ( http://creativecommons.org/licenses/by-nc-sa/3.0/ )
 */
 
#include "Arduino.h"

typedef enum {REL1=0, REL2=1, REL3=2, REL4=3} E_RELAY_SELECT;

class LXR_Relay_Shield {
public:
  /**
   * @brief initializes the LXR_Relay_Shield library
   */
   static void begin();
   
   /**
    * @brief turn a speficic relay on
    */
   static void turn_on(E_RELAY_SELECT const sel);
   
   /**
    * @brief turn a speficic relay off
    */
   static void turn_off(E_RELAY_SELECT const sel);  
};
