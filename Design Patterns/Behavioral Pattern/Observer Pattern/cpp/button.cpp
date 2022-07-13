#include "eventmanager.cpp"

class Button
{
	private:
        EventManager eventManager;
    public:
        void setListener(EventListener listener)
        {
            eventManager.addListener(listener);
        }

        void removeListener(EventListener::Type type)
        {
            eventManager.removeListener(type);
        }

        void performClick()
        {
            eventManager.notify(EventListener::SINGLE_CLICK);
        }

        void performLongClick()
        {
            eventManager.notify(EventListener::LONG_CLICK);
        }
};