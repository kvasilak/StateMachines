/* 
* COneFsm.h
*
* Created: 1/27/2015 10:21:41 PM
* Author: keith
*/


#ifndef __CONEFSM_H__
#define __CONEFSM_H__

typedef enum
{
	EventEntry,
	EventExit,
	UpEvent,
	DownEvent

}FsmEvents;

//forward ref for function pointer
class COneFsm;

//signature for state functions
typedef bool (COneFsm::*FsmStateFunc_t)(FsmEvents e);

class COneFsm
{

public:
	COneFsm();
	~COneFsm();
	


	private:
	
	//states
	bool StateA(FsmEvents e);
	bool StateB(FsmEvents e);

	
protected:
private:
	COneFsm( const COneFsm &c );
	COneFsm& operator=( const COneFsm &c );
	
	
	void Run();
	void Init();
	bool Dispatch(FsmEvents e);
	void SetNextState(FsmStateFunc_t f);
		
	FsmStateFunc_t State;       /**< the current state              */
	FsmStateFunc_t TargetState; /**< target state during transition */

}; //COneFsm

#endif //__CONEFSM_H__
