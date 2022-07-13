#include "button.cpp"
#include "eventlistener.cpp"
#include "singleclicklistener.cpp"
#include "longclicklistener.cpp"

using namespace std;

void printSomething()
{
	cout << "SingleClick Clicked!" << endl;
}

void printSomething2()
{
	cout << "LongClick triggered!" << endl;
}

int main(int argc, const char **argv)
{
	Button button;
	SingleClickListener singleClickListener;
	LongClickListener longClickListener;

	singleClickListener.onClick(printSomething);
	longClickListener.onLongClick(printSomething2);

	// Set the listeners
	button.setListener(singleClickListener);
	button.setListener(longClickListener);

	// Remove longclick listener
	button.removeListener(EventListener::LONG_CLICK);

	// Invoke listener
	button.performClick();
	button.performLongClick();

	return 0;
}