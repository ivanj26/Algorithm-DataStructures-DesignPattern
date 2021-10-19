#include <vector>
#include <iostream>
using namespace std;

class ProductOfNumbers {
    private:
        vector<int> v;
    public:
        ProductOfNumbers()
        {
            v.push_back(1);
        }

        void add(int num)
        {
            if (num) {
                v.push_back(v.back() * num);
            } else {
                v.clear();
                v.push_back(1);
            }
        }

        int getProduct(int k)
        {
            return k < v.size() ? (v.back() / (v[v.size() - 1 - k])) : 0;
        }
};

int main(int argc, char const *argv[])
{
    ProductOfNumbers p;
    p.add(3);
    p.add(0);
    p.add(2);
    p.add(5);
    p.add(4);

    cout << p.getProduct(2) << endl;

    return 0;
}
