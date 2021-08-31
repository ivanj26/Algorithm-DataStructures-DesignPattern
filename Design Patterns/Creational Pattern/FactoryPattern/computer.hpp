#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <string>

class Computer
{
	public:
		virtual ~Computer() {}
		virtual void run() = 0;
		virtual void shutdown() = 0;
		std::string getName() const
		{
			return this->name;
		}

		void setName(std::string name)
		{
			this->name = name;
		}

	private:
		std::string name;
};

#endif