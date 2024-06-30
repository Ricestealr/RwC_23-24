/* Written by Chris Wong
 * Last Updated: 07-06-2024
 * RwC 2023 - 2024
 */

 /// NOTE: PINS TO BE FILLED IN ///

#include <mbed.h>
#include "definitions.h"

// SYSTEM INPUTS

//REMOTE CONTROL - MOTOR CONTROLLER
DigitalIn Remote_IgnitionOn(PG_6, PullDown);
DigitalIn Remote_ReverseMode(PG_5, PullDown);

//REMOTE CONTROL - COMPRESSOR
DigitalIn Remote_C_COM(PG_8, PullDown);

//REMOTE CONTROL - PARKING BRAKES
DigitalIn Remote_ParkBrake(PE_0, PullDown);

//REMOTE CONTROL - WHISTLE
DigitalIn Remote_Whistle(PF_11, PullDown);

//REMOTE CONTROL - AUTOSTOP
DigitalIn Remote_AutoStop(PF_15, PullDown);

//RTC STATUS INPUT
DigitalIn Train_RTC_Circuit_1(PD_13, PullDown);
DigitalIn Train_RTC_Circuit_2(PD_12, PullDown);
DigitalIn Train_RTC_Circuit_3(PD_11, PullDown);
DigitalIn Train_RTC_Circuit_4(PF_4, PullDown);
DigitalIn Train_RTC_Circuit_5(PE_12, PullDown);

//SYSTEM OUTPUTS

//MOTOR CONTROLLER (MC)
DigitalOut MC_IgnitionOn(PG_12);
DigitalOut MC_ReverseMode(PG_9);
DigitalOut C_BAT(PA_14);

//COMPRESSOR
DigitalOut C_COM(PD_6);

//PARKING BRAKES
DigitalOut ParkBrake(PF_1);

//WHISTLE
DigitalOut Whistle(PD_5);

//TRAIN LIGHTS
DigitalOut Fwd_Mode_Lights(PF_10);
DigitalOut Rv_Mode_Lights(PE_8);