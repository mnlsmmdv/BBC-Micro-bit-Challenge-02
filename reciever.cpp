/////////////////////////////////////////////////////////////////////////////////////////////////
//File Name: reciever.cpp                                                                      //
//File Type: .cpp                                                                              //
//Language: C++                                                                                //
//Size: -                                                                                      //
//Authors: Ahmed Affaan, Ahmed Ahsan Azim                                                      //
//Country: Republic of Maldives                                                                //
//GitHub/GitLab: https://github.com/mnlsmmdv , https://gitlab.uwe.ac.uk/aa2-azim               //
//Last Modified: -                                                                             //
//Description: BBC Micro:bit Challenge 02 Morse Code Reciever                                  //
//Advice: -                                                                                    //
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "MicroBit.h"

MicroBit uBit;
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);
void compare();
void timeNow();
void manageDisplay();
void calcTime();
uint64_t firstTime;
uint64_t differenceInTime = 0;
ManagedString order;

//Morse code for the alphabet and numbers from 0-9
ManagedString list[36] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----."  // 9
};

//The corrosponding letters and numbers for the morse code above
ManagedString reference[36] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

/*
 * Function: timeNow
 * Desc: This function takes the current time and stores it in a variable called firstTime
 */
void timeNow()
{
    firstTime = system_timer_current_time();
}

/*
 * Function: calcTime
 * Desc: Simply calculates the difference in time
 */
void calcTime()
{
    differenceInTime = system_timer_current_time() - firstTime;
}

/*
 * Function: compre
 * Desc: Compares the series recieved with the lists above. If the series recieved matches then displays the corrorsponding number otherwise displays mismtach.
 */
void compare()
{
    while (1)
    {
        for (int i = 0; i <= 36; i++)
        {
            if (order == (list[i]))
            {
                uBit.display.print(reference[i]);
                uBit.sleep(500);
                uBit.reset();
            }
        }
        uBit.display.scroll("MISMATCH", 50);
        uBit.sleep(500);
        uBit.reset();
    }
}

/*
 * Function: manageDisplay
 * Parameters: N/A
 * Desc: Checks for the input. If the user short presses the button displays a dot, if long pressed then displays a dash.
 */
void manageDisplay()
{
    if (differenceInTime < 250)
    {
        uBit.display.print(".");
        order = order + ".";
        uBit.sleep(500);
    }
    else if (differenceInTime > 250)
    {
        uBit.display.print("-");
        order = order + "-";
        uBit.sleep(500);
    }
    uBit.display.clear();
}

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();
    bool checkForPress; //boolean to see if the button is pressed
    while (1)
    {
        timeNow();                  //call to get current time
        while (buttonB.isPressed()) //loop while button b is pressed
        {
            compare(); //call compare function to match patterns
        }
        while (uBit.io.P0.getDigitalValue() == 1) //loop while receiving signal
        {
            checkForPress = true; //set boolean to true
            calcTime();           //call to get difference in time
        }
        if (checkForPress == true) //if button pressed
        {
            manageDisplay(); //call to display values
        }
        checkForPress = false; //set boolean to false
    }
    //release_fiber();
}