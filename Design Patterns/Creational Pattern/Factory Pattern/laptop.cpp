#include "computer.hpp"

class Laptop : public Computer
{
    private:
        bool mHibernate;

    public:
        Laptop()
        {
            this->setName("Laptop");
        }

        virtual ~Laptop()
        {
            // destructor
            // clean memory here!
        }

        void run() override
        {
            this->mHibernate = true;
        }

        void shutdown() override
        {
            this->mHibernate = false;
        }

        bool isShutdown() override
        {
            return this->mHibernate == false;
        }
};