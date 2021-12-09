#include <iostream>
#include <assert.h>
#include "singleton.cpp"

int main(int argc, const char **argv)
{
	Singleton *instance = Singleton::getInstance();

	// making sure when getting the instance
	// we will not print "Instance created!" twice
	Singleton *sameInstance = Singleton::getInstance();

	// making sure if instance variable is same instance with sameInstance variable
	assert(instance == sameInstance);

	// only delete 1 instance
	delete instance;

	return 0;
}