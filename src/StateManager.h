
// StateManager.h

#ifndef __STATE_MANAGER_H__
#define __STATE_MANAGER_H__

class StateManager
{
	typedef void (*VoidFunctionPointer0Args)();
	
	typedef struct State_Type
	{
		VoidFunctionPointer0Args function_;
		
		State* next_;
	} State;
	
protected:
	State* head_;
	
public:
	StateManager();
	
	~StateManager();
	
	void Push(VoidFunctionPointer0Args function);
	
	bool Pop();
	
	bool Execute();
};

#endif

