/* 
 * File:   system_core.h
 * Author: hshod
 *
 * Created on February 1, 2024, 2:34 PM
 */

#include "project_flags.h"

#ifndef SYSTEM_CORE_H
#define	SYSTEM_CORE_H

ProjectFlags mainFlags;


void Arm_System(void);


void Disarm_System(void);


void Transmit_MotionData(void);


void Recieve_ArmData(void);

#endif	/* SYSTEM_CORE_H */

