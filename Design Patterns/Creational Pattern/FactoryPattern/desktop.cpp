#include "computer.hpp"

class Desktop : public Computer {
    public:
        Desktop() {
            this->setName("Desktop");
        } 

        void run() override {
            mOn = true;
        }

        void shutdown() override {
            mOn = false;
        }

        virtual ~Desktop() {}
    private:
        bool mOn;
};