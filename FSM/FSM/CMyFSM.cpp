/* 
* CMyFSM.cpp
*
* Created: 1/27/2015 10:01:17 PM
* Author: keith
*/


#include "CMyFSM.h"

// default constructor
CMyFSM::CMyFSM()
{
} //CMyFSM


void CMyFSM::StateA(FsmEvents e)
{
	switch (e)
	{
	case EventEntry:
		break;
	case EventExit:
		break;
	case UpEvent:
		break;
	case DownEvent:
	SetNextState(StateB);
		break;
	}
}

void CMyFSM::StateB(FsmEvents e)
{
	switch (e)
	{
		case EventEntry:
			break;
		case EventExit:
			break;
		case UpEvent:
			//SetNextState(StateA);
			break;
		case DownEvent:
			break;
	}
}
