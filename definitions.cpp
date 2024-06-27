/* Written by Chris Wong
 * Last Updated: 07-06-2024
 * RwC 2023 - 2024
 */

 /// NOTE: PINS TO BE FILLED IN ///

#include <mbed.h>
#include "definitions.h"

// SYSTEM INPUTS

//REMOTE CONTROL - MOTOR CONTROLLER
DigitalIn Remote_IgnitionOn(PD_11, PullDown);
DigitalIn Remote_ReverseMode(PE_10, PullDown);

//REMOTE CONTROL - COMPRESSOR
DigitalIn Remote_C_COM(PE_12, PullDown);

//REMOTE CONTROL - PARKING BRAKES
//DigitalIn Remote_ParkBrake(PE_15, PullUp);

//REMOTE CONTROL - WHISTLE
DigitalIn Remote_Whistle(PE_14, PullDown);

//RTC STATUS INPUT
DigitalIn Train_RTC_Circuit_1(PA_3, PullDown);
DigitalIn Train_RTC_Circuit_2(PA_3, PullDown);
DigitalIn Train_RTC_Circuit_3(PA_3, PullDown);
DigitalIn Train_RTC_Circuit_4(PA_3, PullDown);
DigitalIn Train_RTC_Circuit_5(PA_3, PullDown);

//SYSTEM OUTPUTS

//MOTOR CONTROLLER (MC)
DigitalOut MC_IgnitionOn(PE_0);
DigitalOut MC_ReverseMode(PG_8);

//COMPRESSOR
DigitalOut C_COM(PG_6);

//PARKING BRAKES (NOTE: Parking brake uses two pins)
//DigitalOut ParkBrakeFront(PF_3);
//DigitalOut ParkBrakeRear(PF_15);

//WHISTLE
DigitalOut Whistle(PF_11);

//TRAIN LIGHTS
DigitalOut Fwd_Mode_Lights(PF_11);
DigitalOut Rv_Mode_Lights(PF_11);