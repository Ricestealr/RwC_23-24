/* Written by Chris Wong
 * Last Updated: 07-06-2024
 * RwC 2023 - 2024
 */

#include <mbed.h>           //Required to interface with mbed
#include "definitions.h"    //Defines mbed input/output pins

int main()
{

    int Train_RTC_Circuit_Status;
    int temp_Remote_IgnitionOn;
    int temp_Remote_ReverseMode;

    while (true) {

        // Update WHISTLE and COMPRESSOR status
        C_COM = Remote_C_COM;
        Whistle = Remote_Whistle;

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
        if (temp_Remote_IgnitionOn == 1 && temp_Remote_ReverseMode == 0) { // Train in forward mode and powered
            Fwd_Mode_Lights = 1;
        }
        else if (temp_Remote_IgnitionOn == 1 && temp_Remote_ReverseMode == 1) { // Train in reverse mode and powered
            Rv_Mode_Lights = 1;
        }


        wait_us(10000);
    }
}
