#include "computer.hpp"

class Desktop : public Computer
{
    private:
        bool mOn;

    public:
        Desktop()
        {
            this->setName("Desktop");
        }

        virtual ~Desktop()
        {
            // destructor
            // clean memory here!
        }

        void run() override
        {
            this->mOn = true;
        }

        void shutdown() override
        {
            this->mOn = false;
        }

        bool isShutdown() override
        {
            return this->mOn == false;
        }
};