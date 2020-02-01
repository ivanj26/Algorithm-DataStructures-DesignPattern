#include "button.cpp"
#include "singleclicklistener.cpp"

using namespace std;

void printSomething() {
    cout << "Clicked!" << endl;
}

int main(int argc, const char** argv) {
    Button button;
    SingleClickListener listener;
    listener.onClick(printSomething);
    
    button.events.addListener(listener);

    button.performClick(); //performing click
    button.performLongClick();
    
    return 0;
}