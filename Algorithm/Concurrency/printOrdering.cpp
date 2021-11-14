#include <semaphore.h>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
    private:
        sem_t firstDone;
        sem_t secondDone;

    public:
        Solution()
        {
            sem_init(&firstDone, 0, 0);
            sem_init(&secondDone, 0, 0);
        }

        void first(function<void()> printFirst)
        {
            printFirst();

            sem_post(&firstDone);
        }

        void second(function<void()> printSecond)
        {
            sem_wait(&firstDone);

            printSecond();

            sem_post(&secondDone);
        }

        void third(function<void()> printThird)
        {
            sem_wait(&secondDone);

            printThird();
        }
};

void printFirst()
{
    cout << "this is first!" << endl;
}

void printSecond()
{
    cout << "this is second!" << endl;
}

void printThird()
{
    cout << "this is third!" << endl;
}

int main(int argc, char const *argv[]) {
    Solution s;
    s.first(printFirst);
    s.second(printSecond);
    s.third(printThird);

    return 0;
}
