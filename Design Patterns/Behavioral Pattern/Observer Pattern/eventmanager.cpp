#include <unordered_map>
#include <iostream>
#include <sstream>
#include "eventlistener.hpp"

class EventManager
{
	private:
		std::unordered_map<EventListener::Type, EventListener> listeners;

	public:
		void addListener(EventListener listener)
		{
			listeners.insert({
				listener.getType(),
				listener,
			});
		}

		void removeListener(EventListener listener)
		{
			listeners.erase(listener.getType());
		}

		void notify(EventListener::Type type)
		{
			try
			{
				std::unordered_map<EventListener::Type, EventListener>::iterator it = listeners.find(type);

				if (it == listeners.end())
				{
					const std::string typeStr = EventListener::typeToString(type);
					std::stringstream ss;

					ss << typeStr << "Listener is not implemented yet";
					throw ss.str();
				}

				EventListener listener = listeners.at(type);
				listener.update();
			}
			catch (const std::string msg)
			{
				std::cout << msg << std::endl;
			}
		}
};