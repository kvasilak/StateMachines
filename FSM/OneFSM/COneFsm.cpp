/* 
* COneFsm.cpp
*
* Created: 1/27/2015 10:21:41 PM
* Author: keith
*/


#include "COneFsm.h"


// default constructor
COneFsm::COneFsm()
{
} //COneFsm



bool COneFsm::StateA(FsmEvents e)
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
		//SetNextState(StateB);
			break;
	}
}

bool COneFsm::StateB(FsmEvents e)
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


////State machine code ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//Start the state machine, there HAS to be an initial state
void COneFsm::Init()
{
	State = StateA;
	State(EventEntry);
	
}

//set the next state
void COneFsm::SetNextState(FsmStateFunc_t f)
{
	TargetState = f;
}

//Called to send an event to the current state
bool COneFsm::Dispatch(FsmEvents e)
{
	//call the current state with the event
	bool const result = State(e);

	// did the state function call cause a state change?
	if (TargetState != 0)
	{
		// exit old state
		State(EventExit);

		// enter new state
		TargetState(EventEntry);

		// update state
		State = TargetState;
		
		TargetState = 0;
	}

	return result;
}

