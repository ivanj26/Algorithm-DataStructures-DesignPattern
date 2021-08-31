#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long num;
	cin >> num;

	int oneSum = 0;
	int zeroSum = 0;
	
	while (num > 0) {
	    int temp = num % 10;
	    if (temp == 1) {
	        oneSum++;
	    }
	    
	    if (temp == 0) {
	        zeroSum++;
	    }
	    
	    num = num / 10;
	}

    while (oneSum > 0) {
        cout << 1;
        oneSum--;
    }

    while (zeroSum > 0) {
        cout << 0;
        zeroSum--;
    }

    cout << endl;

    return 0;
}
