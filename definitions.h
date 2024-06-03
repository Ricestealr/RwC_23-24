/* Written by Chris Wong
 * Last Updated: 03-06-2024
 * RwC 2023 - 2024
 */

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <mbed.h>

// SYSTEM INPUTS
// Currently input only comes from the remote control

//REMOTE CONTROL - INPUTS
extern DigitalIn Remote_CBattery;
extern DigitalIn Remote_IgnitionOn;
extern DigitalIn Remote_ReverseMode;



//SYSTEM OUTPUTS
// System currently only outputs to motor controller

//MOTOR CONTROLLER (MC)
extern DigitalOut MC_CBattery;
extern DigitalOut MC_IgnitionOn;
extern DigitalOut MC_ReverseMode;

#endif