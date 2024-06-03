/* Written by Chris Wong
 * Last Updated: 03-06-2024
 * RwC 2023 - 2024
 */

#include <mbed.h>           //Required to interface with mbed
#include "definitions.h"    //Defines mbed input/output pins

void debugPrint(bool debugState, std::string& text) // Print debug messages to terminal if debug mode on
{
    if (debugState == true){
        printf(text + "\r\n");
    }
}


int main()
{

    //SET DEBUG MODE
    bool debugState = false;

    while (true) {

        // Map remote switch status to motor controller
        MC_CBattery = Remote_CBattery;
        MC_IgnitionOn = Remote_IgnitionOn;
        MC_ReverseMode = Remote_ReverseMode;

        // STUFF BELOW MIGHT NOT WORK - COMMENT OUT IF PROGRAM CRASHES
        std::string status = MC_CBattery + MC_CBattery + MC_CBattery;
        debugPrint(debugState, status);
    }
}
