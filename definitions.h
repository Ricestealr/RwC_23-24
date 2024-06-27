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

//REMOTE CONTROL - COMPRESSOR
extern DigitalIn Remote_C_COM;

//REMOTE CONTROL - PARKING BRAKES
//extern DigitalIn Remote_ParkBrake;

//REMOTE CONTROL - WHISTLE
extern DigitalIn Remote_Whistle;

//RTC STATUS INPUT
extern DigitalIn Train_RTC_Circuit_1;
extern DigitalIn Train_RTC_Circuit_2;
extern DigitalIn Train_RTC_Circuit_3;
extern DigitalIn Train_RTC_Circuit_4;
extern DigitalIn Train_RTC_Circuit_5;

//SYSTEM OUTPUTS

//MOTOR CONTROLLER (MC)
extern DigitalOut MC_IgnitionOn;
extern DigitalOut MC_ReverseMode;

//COMPRESSOR
extern DigitalOut C_COM;

//PARKING BRAKES
//extern DigitalOut ParkBrakeFront;
//extern DigitalOut ParkBrakeRear;

//WHISTLE
extern DigitalOut Whistle;

//TRAIN LIGHTS
extern DigitalOut Fwd_Mode_Lights;
extern DigitalOut Rv_Mode_Lights;

#endif