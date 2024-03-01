
#include "system_core.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
#include "mcc_generated_files/eusart.h"


void Arm_System(void)
{
    SensorPin_SetDigitalInput(); //sets sensor pin to input
    IOCCPbits.IOCCP2 = 1; //enables interrupt on change for sensor, positive edge only
    PIE0bits.TMR0IE = HIGH; //enables timer interrupt

    mainFlags.SystemArmed = LOW; //lowers system armed flag to avoid fnc reentry
    mainFlags.SystemDisarmed_ContinuousSleep = LOW; //flag for sleep loop entry
}


void Disarm_System(void)
{
    IOCCPbits.IOCCP2 = 0; //disable interrupt when system disarmed, positive edge only
    
    PIE0bits.TMR0IE = LOW; //disable timer interrupt
    TMR0_StopTimer(); //stop timer in case it is running

    mainFlags.SystemDisarmed_ContinuousSleep = HIGH;
    mainFlags.SystemDisarmed = LOW;
}


void Transmit_MotionData(void)
{
    EUSART_Write(0x4D); //M for motion
    EUSART_Write(0x44); //D for detected
    
    mainFlags.System_MotionFlag = LOW;
    
    while(!EUSART_is_tx_done()); //while there is still data in buffer, wait
}