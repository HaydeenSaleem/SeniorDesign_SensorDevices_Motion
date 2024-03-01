
#include "system_core.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"


void Arm_System(void)
{
    SensorPin_SetDigitalInput(); //sets sensor pin to input
    PIE0bits.IOCIE = HIGH; //enables interrupt on change for sensor
    PIE0bits.TMR0IE = HIGH; //enables timer interrupt

    mainFlags.SystemArmed = LOW; //lowers system armed flag to avoid fnc reentry
    mainFlags.SystemDisarmed_ContinuousSleep = LOW; //flag for sleep loop entry
}


void Disarm_System(void)
{
    //SensorPin_SetDigitalOutput();
    PIE0bits.IOCIE = LOW; //disable interrupt when system disarmed
    PIE0bits.TMR0IE = LOW; //disable timer interrupt
    TMR0_StopTimer(); //stop timer in case it is running


    mainFlags.SystemDisarmed_ContinuousSleep = HIGH;
    mainFlags.SystemDisarmed = LOW;
}
