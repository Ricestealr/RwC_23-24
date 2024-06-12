/* Written by Chris Wong
 * Last Updated: 07-06-2024
 * RwC 2023 - 2024
 */

#include <mbed.h>           //Required to interface with mbed
#include "definitions.h"    //Defines mbed input/output pins

// void debugPrint(bool debugState, std::string& text) // Print debug messages to terminal if debug mode on
// {
//     if (debugState == true){
//         printf(text + "\r\n");
//     }
// }


int main()
{

    //SET DEBUG MODE
    bool debugState = false;

    //MAIN VARIABLE DECLARATIONS
    int brakeStatus;

    // Turn on C_BAT to provide MOTOR CONTROLLER (MC) power
    C_BAT = 1; 

    while (true) {
        // Whistle = 1;
        // C_COM = 1;

        // Update WHISTLE and COMPRESSOR status
        C_COM = Remote_C_COM;
        Whistle = Remote_Whistle;

        //Check whether RTC is closed and deadman pressed
        if (Remote_Deadman == 1 && Train_RTC_Circuit == 0) {

            //Update PARKING BRAKE status
            brakeStatus = Remote_ParkBrake; //Read variable only once
            ParkBrakeFront = brakeStatus;
            ParkBrakeRear = brakeStatus;

            //Update MOTOR CONTROLLER status
            MC_IgnitionOn = Remote_IgnitionOn;
            MC_ReverseMode = Remote_ReverseMode;
        }
        else {  //Force override PARKING BRAKE and IGNITION switch states if RTC/DEADMAN open
            ParkBrakeFront = 1; //Activate parking brakes
            ParkBrakeRear = 1;
            MC_IgnitionOn = 0; //Turn off motor controller ignition
        }

        // STUFF BELOW MIGHT NOT WORK - COMMENT OUT IF PROGRAM CRASHES
        // std::string status = MC_CBattery + MC_CBattery + MC_CBattery;
        // debugPrint(debugState, status);

        wait_us(10000);
    }
}
