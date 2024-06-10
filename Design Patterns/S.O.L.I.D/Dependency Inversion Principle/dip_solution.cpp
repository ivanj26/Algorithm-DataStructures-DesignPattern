// (D)ependency Inversion Principle
// suggests that the high-level module should not depend on low-level module, instead we can use the abstraction.

#include <iostream>
#include <string.h>

// Good Example:
//
class IMessageSender {
    public:
        virtual void sendMessage(std::string message) = 0;
};

class EmailSender: public IMessageSender {
    public:
        void sendMessage(std::string message) {
            std::cout << "Sending an email.. msg: " << message << std::endl;
        }
};

class NotificationService {
    private:
        IMessageSender *sender;
    public:
        NotificationService(IMessageSender *_sender) {
            this->sender = _sender;
        }

        void sendNotification(std::string message) {
            this->sender->sendMessage(message);
        }
};

int main(int argc, char const *argv[])
{
    IMessageSender *sender = new EmailSender();
    NotificationService *service = new NotificationService(sender);
    service->sendNotification("example message");

    delete service;
    delete sender;

    return 0;
}
