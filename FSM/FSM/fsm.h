/*
 * fsm.h
 *
 * Created: 1/24/2015 10:49:58 PM
 *  Author: keith
 */ 


#ifndef FSM_H_
#define FSM_H_
#include <inttypes.h>

//Event base class
//derive your even class from this
//your events will have positive values

	typedef enum
	{
		EventEntry,
		EventExit,
		UpEvent,
		DownEvent

	}FsmEvents;


class CFsm;

//signature for state functions
typedef bool (CFsm::*FsmStateFunc_t)(FsmEvents e);

/* Event base class */
class CFsm
{
public:
	

	CFsm();
	virtual void Init(FsmStateFunc_t initialstate);
	virtual bool Dispatch(FsmEvents e);
	virtual void SetNextState(FsmStateFunc_t f);

private:

    FsmStateFunc_t State;       /**< the current state              */
    FsmStateFunc_t TargetState; /**< target state during transition */
};

#endif /* FSM_H_ */