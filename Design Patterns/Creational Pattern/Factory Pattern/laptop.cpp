#include "computer.hpp"

class Laptop : public Computer
{
	public:
		Laptop()
		{
			this->setName("Laptop");
		}

		void run() override
		{
			mHibernate = false;
		}

		void shutdown() override
		{
			mHibernate = true;
		}

		virtual ~Laptop() {}

	private:
		bool mHibernate;
};