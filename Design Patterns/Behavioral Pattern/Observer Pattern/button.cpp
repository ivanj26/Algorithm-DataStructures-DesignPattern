#include "eventmanager.cpp"

class Button {
    public:
        EventManager events;
        void performClick() {
            events.notify(EventListener::SINGLE_CLICK);
        }

        void performLongClick() {
            events.notify(EventListener::LONG_CLICK);
        }
};