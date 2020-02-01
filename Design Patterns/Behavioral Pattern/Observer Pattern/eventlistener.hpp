#include <string>
#include <functional>

#ifndef EVENT_LISTENER
#define EVENT_LISTENER

class EventListener {
    public:
        enum Type {
            SINGLE_CLICK,
            LONG_CLICK,
        };

        Type getType() const {
            return type;
        }

        void update() {
            funcLogic();
        }

        static std::string typeToString(Type type) {
            switch (type)
            {
                case SINGLE_CLICK:
                    return "SingleClick";
                case LONG_CLICK:
                    return "LongClick";
            }

            return "";
        }
    protected:
        Type type;
        std::function<void ()> funcLogic;
};

#endif // !EVENT_LISTENER