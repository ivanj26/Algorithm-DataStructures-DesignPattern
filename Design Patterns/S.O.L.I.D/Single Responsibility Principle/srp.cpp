// (S)ingle Responsibility Principle:
//
// A class has only one reason to change, it means the class has only one job/responsibility to do.

// Let say, I have a ConsoleLogger:
class ConsoleLogger
{
    public:
        void Print() {
            // This is a code here!
            // The code is only do print in terminal/console, nothing else to do.
        }
};

class EmailSender
{
    public:
        void Send() {
            // Only responsible to send an email to recipient.
        }
};

// Note:
// 1. This is not to say that the class should only have 1 method.
//    you can have >1 methods and many props/attributes,
//    as long as they are related to the single functionality.
// 
// 2. As the result of SRP, we can see the class become smaller and easier to read.
//    Making them to easier to maintain.