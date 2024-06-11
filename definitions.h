/* Written by Chris Wong
 * Last Updated: 07-06-2024
 * RwC 2023 - 2024
 */

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <mbed.h>

// SYSTEM INPUTS

//REMOTE CONTROL - MOTOR CONTROLLER
extern DigitalIn Remote_IgnitionOn;
extern DigitalIn Remote_ReverseMode;
extern DigitalIn Remote_C_BAT;

//REMOTE CONTROL - COMPRESSOR
extern DigitalIn Remote_C_COM;

//REMOTE CONTROL - PARKING BRAKES
extern DigitalIn Remote_ParkBrake;

//REMOTE CONTROL - WHISTLE
extern DigitalIn Remote_Whistle;

//REMOTE CONTROL - DEADMAN
extern DigitalIn Remote_Deadman;

//RTC STATUS INPUT
extern DigitalIn Train_RTC_Circuit;

//SYSTEM OUTPUTS

//MOTOR CONTROLLER (MC)
extern DigitalOut MC_IgnitionOn;
extern DigitalOut MC_ReverseMode;
extern DigitalOut C_BAT;

//COMPRESSOR
extern DigitalOut C_COM;

//PARKING BRAKES
extern DigitalOut ParkBrakeFront;
extern DigitalOut ParkBrakeRear;

//WHISTLE
extern DigitalOut Whistle;

#endif