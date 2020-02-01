#include "button.cpp"
#include "singleclicklistener.cpp"
#include "longclicklistener.cpp"

using namespace std;

void printSomething() {
    cout << "Clicked!" << endl;
}

void printSomething2() {
    cout << "LongClick triggered!" << endl;
}

int main(int argc, const char** argv) {
    Button button;
    SingleClickListener singleClickListener;
    LongClickListener longClickListener;

    singleClickListener.onClick(printSomething);
    longClickListener.onLongClick(printSomething2);
    
    //Add listener to EventManager
    button.events.addListener(singleClickListener);
    button.events.addListener(longClickListener);

    button.performClick(); //performing click

    button.events.removeListener(singleClickListener);

    button.performClick();
    button.performLongClick();
    
    return 0;
}