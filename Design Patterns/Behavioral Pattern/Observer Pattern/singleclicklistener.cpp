#include "eventlistener.hpp"
#include <iostream>

class SingleClickListener : public EventListener
{
	public:
		SingleClickListener()
		{
			type = SINGLE_CLICK;
		}

		void onClick(std::function<void()> funcLogic)
		{
			this->funcLogic = funcLogic;
		}
};