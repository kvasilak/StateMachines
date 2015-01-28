/* 
* CMyFSM.h
*
* Created: 1/27/2015 10:01:17 PM
* Author: keith
*/


#ifndef __CMYFSM_H__
#define __CMYFSM_H__

#include "fsm.h"

class CMyFSM :public CFsm
{

public:
	CMyFSM();
	~CMyFSM();
	
	void StateA(FsmEvents e);
	void StateB(FsmEvents e);
protected:
private:


}; //CMyFSM

#endif //__CMYFSM_H__
