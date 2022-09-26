/******************************************************/
/* Title       : EXTERNAL INTERRUPT configration file */
/* Author      : Joseph Tharwat                    	  */
/* Release     : 1.0                                  */
/* Last Update : 6-9-2022                             */
/******************************************************/

#ifndef EXTERNAL_INTERRUPT_CONFIGRATION_H_
#define EXTERNAL_INTERRUPT_CONFIGRATION_H_
#include "EXTERNAL_INTERRUPT_priv.h"

/*Choose MODE :
 *INT0_LowLevel
 *INT0_ON_CHANGING
 *INT0_RISING_EDGE
 *INT0_FALLING_EDGE
 */
#define INT0_MODE 	INT0_ON_CHANGING

/*Choose MODE :
 *INT1_LowLevel
 *INT1_ON_CHANGING
 *INT1_RISING_EDGE
 *INT1_FALLING_EDGE
 */
#define INT1_MODE 	INT1_ON_CHANGING

/*Choose MODE :
 *INT2_RISING_EDGE
 *INT2_FALLING_EDGE
 */
#define INT2_MODE 	INT0_ON_CHANGING



#endif
