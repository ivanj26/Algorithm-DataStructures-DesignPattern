#include <unordered_map>
#include <iostream>
#include <sstream>
#include "eventlistener.hpp"

namespace std {
  template <> struct hash<EventListener::Type> {
    size_t operator() (const EventListener::Type &t) const { return size_t(t); }
  };
}

class EventManager
{
	private:
		std::unordered_map<EventListener::Type, EventListener> listeners;

	public:
		void addListener(EventListener listener)
		{
			listeners.insert({
				listener.getType(),
				listener
			});
		}

		void removeListener(EventListener::Type type)
		{
			listeners.erase(type);
		}

		void notify(EventListener::Type type)
		{
			try
			{
				std::unordered_map<EventListener::Type, EventListener>::iterator it = listeners.find(type);
				if (it == listeners.end()) {
					// if the listener is not found in hashmap
					// throw an error
					std::stringstream ss;
					std::string typeStr = EventListener::typeToString(type);
					ss << typeStr << " Listener is not implemented yet!" << std::endl;
				
					throw ss.str();
				}

				EventListener listener = listeners.at(type);
				listener.update();
			}
			catch (const std::string msg)
			{
				std::cout << msg;
			}
		}
};