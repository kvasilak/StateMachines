/*
 * OneFSM.cpp
 *
 * Created: 1/27/2015 10:21:09 PM
 *  Author: keith
 */ 
#include "COneFsm.h"

#include <avr/io.h>


int main(void)
{
	COneFsm fsm;
	
	fsm.Init();
	
    while(1)
    {
        fsm.Run();
    }
}