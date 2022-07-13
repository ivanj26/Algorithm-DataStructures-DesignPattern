#include <string>
#include <functional>

#ifndef EVENT_LISTENER
#define EVENT_LISTENER

class EventListener
{
    public:
        enum Type
        {
            SINGLE_CLICK,
            LONG_CLICK,
        };

        EventListener::Type getType();
        void update();
        static std::string typeToString(EventListener::Type) throw();

    protected:
        std::function<void()> funcLogic;
        EventListener::Type type;
};

#endif // !EVENT_LISTENER