// (D)ependency Inversion Principle
// suggests that the high-level module should not depend on low-level module, instead we can use the abstraction.

#include <iostream>
#include <string.h>

// Bad Example:
//
class EmailSender {
    public:
        void sendMessage(std::string message) {
            std::cout << "Sending an email.. msg: " << message << std::endl;
        }
};

class NotificationService {
    private:
        EmailSender *sender;
    public:
        NotificationService(EmailSender *_sender) {
            this->sender = _sender;
        }

        void sendNotification(std::string message) {
            this->sender->sendMessage(message);
        }
};

int main(int argc, char const *argv[])
{
    NotificationService *service = new NotificationService(new EmailSender());
    service->sendNotification("example message");

    delete service;
    return 0;
}
