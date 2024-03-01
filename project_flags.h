/* 
 * File:   project_flags.h
 * Author: hshod
 *
 * Created on January 25, 2024, 10:46 PM
 */

#include <stdint.h>


#ifndef PROJECT_FLAGS_H
#define	PROJECT_FLAGS_H

typedef struct ProjectFlags
{
    uint8_t SystemArmed     :1;
    uint8_t SystemDisarmed  :1;
    uint8_t SystemDisarmed_ContinuousSleep  :1;
    uint8_t System_MotionFlag :1;
    uint8_t System_BluetoothReceive :1;
} ProjectFlags;


#endif	/* PROJECT_FLAGS_H */

