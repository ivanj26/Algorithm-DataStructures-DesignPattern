#include <iostream>

#include "computerfactory.cpp"

int main(int argc, const char **argv)
{
	ComputerFactory factory;
	Computer *comp = factory.create(LAPTOP);

	std::cout << comp->getName() << std::endl;

	delete comp;
	return 0;
}