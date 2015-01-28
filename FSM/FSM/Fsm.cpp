/*
 * Fsm.cpp
 *
 * Created: 1/25/2015 5:58:54 PM
 *  Author: keith
 */ 
#include "fsm.h"

CFsm::CFsm():
State(0),
TargetState(0)
{
}

//Start the state machine, there HAS to be an initial state
void CFsm::Init(FsmStateFunc_t initialstate)
{
	//C_ASSERT(initialstate != NULL);
	
	State = initialstate;
	(*this.*CFsm::State)(EventEntry);
	
}

//set the next state
void CFsm::SetNextState(FsmStateFunc_t f)
{
	TargetState = f;
}

//Called to send an event to the current state
bool CFsm::Dispatch(FsmEvents e)
{
	//call the current state with the event
	bool const result = (*this.*CFsm::State)(e);

	// did the state function call cause a state change?
	if (TargetState != 0)
	{
		// exit old state
		(*this.*CFsm::State)(EventExit);

		// enter new state
		(*this.*CFsm::TargetState)(EventEntry);

		// update state
		State = TargetState;
		
		TargetState = 0;
	}

	return result;
}

