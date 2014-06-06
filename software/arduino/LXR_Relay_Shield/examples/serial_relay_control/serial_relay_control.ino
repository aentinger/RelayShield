/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch demonstrates how the 4 relay of the LXRobotics Relay Shield can be controlled via a simple serial protocol
 * @file serial_relay_control.ino
 */

// PROTOCOL Description
// Turn Relay 1 on -> 'R11'
// Turn Relay 1 off -> 'R10'
// Turn Relay 2 on -> 'R21'
// Turn Relay 2 off -> 'R20'
// 3 Byte Protcol = [START_SIGN, RELAY_SELECTION, RELAY_STATE]
// Start Sign = 'R'
// Relay Selection = '1' | '2' | '3' | '4'
// Relay State = '0' (OFF) | '1' (ON)

 
#include "LXR_Relay_Shield.h"
 
void setup() {
  LXR_Relay_Shield::begin();
  Serial.begin(115200);
}
 
void loop() {
  while(Serial.available() > 0) {
   byte const received_byte =  Serial.read();
   parse_byte(received_byte);
  }
}

void parse_byte(char const b) {
  typedef enum {START=0, RELAY_NUMBER=1, RELAY_STATE=2} E_PARSE_STATE;
  static E_PARSE_STATE state = START;
  static E_RELAY_SELECT relay_number = REL1;

  switch(state) {
   case START: {
     state = RELAY_NUMBER;
   } break;
   case RELAY_NUMBER: {
     if(b == 'R') state = START;
     else state = RELAY_STATE;

     switch(b) {
      case '1': relay_number = REL1; break;
      case '2': relay_number = REL2; break;
      case '3': relay_number = REL3; break;
      case '4': relay_number = REL4; break;
      default: state = START; break;
     }
   } break;
   case RELAY_STATE: {
     if(b == '0') LXR_Relay_Shield::turn_off(relay_number);
     else if(b == '1') LXR_Relay_Shield::turn_on(relay_number);
     if(b == '0' || b == '1') Serial.println("ACK");
     else Serial.println("NOT ACK");
     state = START;
   } break;
   default: break;
  }
}
