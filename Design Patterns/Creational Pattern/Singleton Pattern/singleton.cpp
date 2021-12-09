#include <iostream>
using namespace std;

class Singleton
{
	private:
		static Singleton *instance;
		int value;
		Singleton(int value = 0)
		{
			this->value = value;
		}

	public:
		static Singleton *getInstance()
		{
			if (instance == nullptr)
			{
				cout << "Instance created!" << endl;
				instance = new Singleton();
			}

			return instance;
		}

		int getValue()
		{
			return this->value;
		}

		void setValue(int value)
		{
			this->value = value;
		}
};

Singleton *Singleton::instance = 0;