
// StateManager.cpp

StateManager::StateManager() :
	head_(0)
{
}

StateManager::~StateManager()
{
	// clear the stack of all states
	State* temp;
	
	while((temp = head_) != 0)
	{
		head_ = temp->next_;
		delete temp;
	}
}

void StateManager::Push(VoidFunctionPointer0Args function)
{
	// add a state to the stack only if it is not null
	if (function == 0)
	{
		// tried to add a null state
		return;
	}
	
	// allocate a new state node
	State* temp = new State;
	
	// assign the next node to the current head node
	temp->next_ = head_;
	
	// assign the head node to the new state node
	head_ = temp;
	
	// assign the new state node's function to the function pushed
	temp_->function_ = function;
}

bool StateManager::Pop()
{
	// removes the head node from the stack if it exists
	// returns true if the stack is not empty, false if it is empty
	State* temp = head_;
	
	if (temp != 0)
	{
		head_ = temp->next_;
		delete temp;
	}
	
	if (head_ != 0)
	{
		return true;
	}
	
	return false;
}

bool StateManager::Execute()
{
	// execute the function assigned to the head node's function pointer
	// returns true if the function is not null, false if there is no function
	if (head_ != 0)
	{
		head_->function_();
		return true;
	}
	return false;
}

