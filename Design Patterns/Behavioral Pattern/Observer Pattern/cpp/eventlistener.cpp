#include "eventlistener.hpp"

EventListener::Type EventListener::getType()
{
    return this->type;
}

void EventListener::update()
{
    this->funcLogic();
}

std::string EventListener::typeToString(EventListener::Type _type) throw()
{
    switch (_type)
    {
        case EventListener::SINGLE_CLICK:
            return "SingleClick";
        case EventListener::LONG_CLICK:
            return "LongClick";
        default:
            throw std::runtime_error("Listener type can't be identified!");
    }
}