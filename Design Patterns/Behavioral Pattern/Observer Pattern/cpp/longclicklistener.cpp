#include "eventlistener.hpp"
#include <iostream>

class LongClickListener: public EventListener
{
    public:
        LongClickListener()
        {
            this->type = EventListener::LONG_CLICK;
        }

        void onLongClick(std::function<void()> funcLogic)
        {
            this->funcLogic = funcLogic;
        }
};