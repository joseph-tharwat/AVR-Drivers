/************************************************/
/* Title       : GIE programe file              */
/* Author      : Joseph Tharwat                 */
/* Release     : 1.0                            */
/* Last Update : 6-9-2022                       */
/************************************************/

#include "GIE_priv.h"
#include "BIT_MATH.h"

void GIE_vid_GIE()
{
	SET_BIT(SREG,GIE_BIT);
}
