#include "computer.hpp"
#include "laptop.cpp"
#include "desktop.cpp"
#include "computerconstant.cpp"

class ComputerFactory
{
	public:
		static Computer *create(ComputerConstant type)
		{
			switch (type)
			{
			case LAPTOP:
				return new Laptop();

			case DESKTOP:
				return new Desktop();
			}

			return nullptr;
		}
};