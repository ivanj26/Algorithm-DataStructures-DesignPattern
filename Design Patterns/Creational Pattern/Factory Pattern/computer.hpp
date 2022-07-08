#include <string>

#ifndef COMPUTER_HPP
#define COMPUTER_HPP

class Computer
{
    public:
        std::string getName() const
        {
            return this->name;
        }
        virtual ~Computer(){};
        virtual void run() = 0;
        virtual void shutdown() = 0;
        virtual bool isShutdown() = 0;

    protected:
        void setName(std::string name)
        {
            this->name = name;
        }

    private:
        std::string name;
};

#endif