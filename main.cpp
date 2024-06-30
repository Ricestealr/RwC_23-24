/* Written by Chris Wong
 * Last Updated: 27-06-2024
 * RwC 2023 - 2024
 */

#include <mbed.h>           //Required to interface with mbed
#include "definitions.h"    //Defines mbed input/output pins

// AUTOPSTOP INTERRUPT
InterruptIn AutoStopTrigger(PE_3);

// AUTOSTOP CONTROL FUNCTION
void AutoStopTriggered()
{
    if (Remote_AutoStop == 1) { //CHECK IF AUTOSTOP MODE IS ON 
        wait_us(1000000);
        Whistle = 1;
        wait_us(1000000);
        Whistle = 0; 
    }

}

int main()
{

    int Train_RTC_Circuit_Status;
    int temp_Remote_IgnitionOn;
    int temp_Remote_ReverseMode;


    // INTERRUPT for AUTOSTOP
    AutoStopTrigger.rise(&AutoStopTriggered);

    while (true) {

        // CLOSE C_BAT to power MC when control cabinet powered
        C_BAT = 1;

        // Update WHISTLE, COMPRESSOR, and PARK BRAKE status
        C_COM = Remote_C_COM;
        Whistle = Remote_Whistle;
        ParkBrake = Remote_ParkBrake;

        Train_RTC_Circuit_Status = Train_RTC_Circuit_1 + Train_RTC_Circuit_2 + Train_RTC_Circuit_3 + Train_RTC_Circuit_4 + Train_RTC_Circuit_5;

        // Read remote control switch states and store as variables
        temp_Remote_IgnitionOn = Remote_IgnitionOn;
        temp_Remote_ReverseMode = Remote_ReverseMode;

        //Check whether RTC is closed and deadman pressed
        if (Train_RTC_Circuit_Status == 0) {

            //Update MOTOR CONTROLLER status
            MC_IgnitionOn = temp_Remote_IgnitionOn;
            MC_ReverseMode = temp_Remote_ReverseMode;
        }
        else {  //Force override PARKING BRAKE and IGNITION switch states if RTC/DEADMAN open
            MC_IgnitionOn = 0; //Turn off motor controller ignition
        }

        //UPDATE TRAIN LIGHT STATUS
        if (temp_Remote_ReverseMode == 0) { // Train in forward mode and powered
            Fwd_Mode_Lights = 1;
            Rv_Mode_Lights = 0;
        }
        else{ // Train in reverse mode and powered
            Rv_Mode_Lights = 1;
            Fwd_Mode_Lights = 0;
        }

        wait_us(10000);
    }
}
