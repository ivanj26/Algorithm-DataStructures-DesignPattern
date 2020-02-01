#include "eventlistener.hpp"
#include <iostream>

class LongClickListener : public EventListener {
    public:
        LongClickListener() {
            type = LONG_CLICK;
        }

        void onLongClick(std::function<void()> funcLogic) {
            this->funcLogic = funcLogic;
        }
};