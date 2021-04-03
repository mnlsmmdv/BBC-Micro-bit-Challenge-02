/*
Authors: Ahmed Affaan, Ahmed Ahsan Azim
Country: Maldives
Language: C++
Email: mnlsmmdv13@protonmail.com , ahsanazim34@gmail.com
GitHub/GitLab: https://github.com/mnlsmmdv13 , https://gitlab.uwe.ac.uk/aa2-azim
Latest Modified: 03/04/2021 16:45PM
Advice: None
//*/


#include "MicroBit.h"

MicroBit uBit;

MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);

void EchoTime();
void CLockCalc ();
void Terminal();
bool pressed = false;
uint64_t StartPoint;
uint64_t clockDifference;

/*
 * Function Name: EchoTime
 * Parameters: N/A
 * Description: Publishes available current time in function  "Echo Time"
 */
void EchoTime()
{

    StartPoint = system_timer_current_time();

}


/*
 * Function Name: ClockCalc
 * Parameters: N/A
 * Desc: Calculation of time difference
 */
void ClockCalc() 
{

    clockDifference = system_timer_current_time()-StartPoint;

}
   
/*
 * Function name: Terminal
 * Parameters: N/A
 * Desc: Displays "-" if button is held between 250-500 seconds.
 *       Displays a "." if button is held for < 250 seconds.
 */
void Terminal() 
{

          //If-Else statement issued for "." and "-" probabilities
          if (clockDifference < 250) {

            uBit.display.print(".");
            uBit.sleep(500);

          }

          else if (clockDifference > 250) {

            uBit.display.print("-");
            uBit.sleep(500);

          }

          //Clears the screen
          uBit.display.clear();

}

//Main function
int main()
{

    //BBC Micro:bit runtime initialised
    uBit.init();

    while(1) 
    {

        //Function initialised to recvieve current time
        EchoTime();
        
        //Signal sent to Micro:bit #2 when button B is pressed
        while (buttonB.isPressed()){
        pressed = true;
        uBit.io.P0.setDigitalValue(1);

    }
    
    //Requests ClockCalc when transmission ends  
    uBit.io.P0.setDigitalValue(0);
    ClockCalc();

    //Display manager requested to show results
    if(pressed)
    {
        Terminal();

        pressed = false;

    }

        uBit.io.P0.setDigitalValue(0);

    }

    release_fiber();

}
