/* Written by Chris Wong
 * Last Updated: 03-06-2024
 * RwC 2023 - 2024
 */

 /// NOTE: PINS TO BE FILLED IN ///

#include <mbed.h>
#include "definitions.h"

// SYSTEM INPUTS
// Currently input only comes from the remote control

//REMOTE CONTROL - INPUTS
DigitalIn Remote_CBattery(, PullDown);
DigitalIn Remote_IgnitionOn(, PullDown);
DigitalIn Remote_ReverseMode(, PullDown);



//SYSTEM OUTPUTS
// System currently only outputs to motor controller

//MOTOR CONTROLLER (MC)
DigitalOut MC_CBattery();
DigitalOut MC_IgnitionOn();
DigitalOut MC_ReverseMode();