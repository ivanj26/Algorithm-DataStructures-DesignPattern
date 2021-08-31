#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#define MAX 100

int multiply(int x, int* res, int res_size)
{
    int carry = 0;  // Initialize carry
 
    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
 
        // Store last digit of 'prod' in res[] 
        res[i] = prod % 10;
 
        // Put rest in carry
        carry  = prod/10;   
    }
 
    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void fact(int n) {
    int res[MAX];
    int size = 1;

    res[0] = 1;

    for (int i = 2; i <= n; i++) {
        size = multiply(i, res, size);
    }
        

    for (int i = size - 1; i >= 0; i--) {
	    cout << res[i];
	}
	
	cout << endl;
}

// string convertDecToBin(int* binary, int size) {
//     string strInBin;
//     for (int j = 0; j < size; j++) {
//         int converted = binary[j] + 48;
//         char c = (char) converted;

//         strInBin.push_back(c);
//     }

//     return strInBin;
// } 
 
// int convertBinToDec(string bin) {
//     int sum = 0;
//     int len = (bin.length() - 1);
//     int digit = 1;

//     while (len > 0) {
//         digit = digit * 10;
//         len--;
//     }

//     for (int i = 0; i < bin.length(); i++) {
//         int temp = ((int) bin.at(i)) - 48;
//         temp = temp * digit;

//         sum = sum + temp;

//         digit /= 10;
//     }

//     // convert to dec
//     int t = sum;
//     int base = 1;
//     int decVal = 0;
//     while (t > 0) {
//         int last = t % 10;
//         t = t / 10;

//         decVal += last * base;
//         base = base * 2;
//     }

//     return decVal;
// } 

// int hitung(string bilangan) {
//     long num = stoi(bilangan);
//     int binary[32];
    
//     int i = 0;
//     while (num > 0) {
//         binary[i] = num % 2;
//         num = num / 2;
        
//         i++;
//     }
    
//     string strInBin = convertDecToBin(binary, i);

//     int oneSum = 0;
//     int zeroSum = 0;

//     for (int k = 0; k < strInBin.length(); k++) {
//         char c = strInBin.at(k);
//         if (c == '0') {
//             zeroSum++;
//         }

//         if (c == '1') {
//             oneSum++;
//         }
//     }

//     // result
//     string res;

//     while (oneSum > 0) {
//         res.push_back('1');
//         oneSum--;
//     }

//     while (zeroSum > 0) {
//         res.push_back('0');
//         zeroSum--;
//     }

//     return convertBinToDec(res);
// }

string convertDecToBin(int *binary, int size) {
    string strInBin;
    for (int j = 0; j < size; j++) {
        int converted = binary[j] + 48;
        char c = (char) converted;
        
        strInBin.push_back(c);
    }
    
    return strInBin;
} 
 
int convertBinToDec(string bin) {
    int sum = 0;
    int len = (bin.length() - 1);
    int digit = 1;
    
    while (len > 0) {
        digit = digit * 10;
        len--;
    }
    
    for (int i = 0; i< bin.length(); i++) {
        int temp = ((int) bin.at(i)) - 48;
        temp = temp * digit;
        
        sum = sum + temp;
        digit /= 10;
    }
    
    // convert to convertBinToDec
    int t = sum;
    int base = 1;
    int decVal = 0;
    while (t > 0) {
        int last = t % 10;
        t = t / 10;
        
        decVal += last * base;
        base = base * 2;
    }
    
    return decVal;
} 

int hitung(string bilangan) {
    long num = stoi(bilangan);
    int binary[32];
    
    int i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        
        i++;
    }
    
    string strInBin = convertDecToBin(binary, i);
    
    int oneSum = 0;
    int zeroSum = 0;
    for (int k = 0; k < strInBin.length(); k++) {
        char c = strInBin.at(k);
        if (c == '0') zeroSum++;
        if (c == '1') oneSum++;
    }
    
    // result
    string res;
    while (oneSum > 0) {
        res.push_back('1');
        oneSum--;
    }
    
    while (zeroSum > 0) {
        res.push_back('0');
        zeroSum--;
    }
    
    return convertBinToDec(res);
}

struct Hat {
    int height;
    int number;
};

int findTotalWays(int N, string S) {
    int total = N - 1;
    int totalWays = 0;
    
    int totalRoad = 0;
    char prev = '%';
    
    for (int i = 1; i <= total; i++) {
        if (prev == '%' || prev == '.') {
            totalRoad++;
        } else {
            if (totalRoad == 1) totalWays++;
            if (totalRoad == 2) totalWays += 2;
            if (totalRoad == 3) totalWays += 4;
            if (totalRoad > 3) {
                int t = totalRoad - 2;
                int u = t - 1;
                totalWays += (1 + 2 + (t * u));
            }

            totalRoad = 0;
        }
    }

    if (totalRoad > 0) {
        if (totalRoad == 1) totalWays++;
        if (totalRoad == 2) totalWays += 2;
        if (totalRoad == 3) totalWays += 4;
        if (totalRoad > 3) {
            int t = totalRoad - 2;
            int u = t - 1;
            totalWays += (1 + 2 + (t * u));
            totalRoad = 0;   
        }
    }

    return totalWays % 10000000;
}

int main(int argc, char const *argv[])
{
    // Hat h;
    // h.height = 10;
    // h.number = 10;
    cout << findTotalWays(10, "o._._._._.") << endl;

    // stack<Hat> s;
    // queue<Hat> q;
    // s.push(h);

    // q.push(h);
    // q.

    // cout << s.top().height;
    return 0;
}
