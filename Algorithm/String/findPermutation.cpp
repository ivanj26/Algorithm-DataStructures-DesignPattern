#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

using namespace std;

class PermutationIterator {
    private:
        vector<string> permutations;
        int ptr;

        string constructPermutations(string characters, int maxLength, string permutation = "")
        {
            if (permutation.length() == maxLength)
            {
                return permutation + " ";
            }

            string finalAnswers = "";
            for (int i = 0; i < characters.length(); i++)
            {
                char c = characters[i];
                string leftSubStr = characters.substr(0, i);
                string rightSubStr = characters.substr(i + 1);

                finalAnswers += constructPermutations(leftSubStr + rightSubStr, maxLength, permutation + c);
            }

            return finalAnswers;
        }

        vector<string> toVector(string perms, string delimiter = " ")
        {
            int start = 0;
            int end = perms.find(delimiter);
            vector<string> res;

            while (end != -1)
            {
                string perm = perms.substr(start, end - start);
                start = end + delimiter.size();
                end = perms.find(delimiter, start);

                res.push_back(perm);
            }

            return res;
        }
    public:
        PermutationIterator(string characters, int permutationLength): ptr(0)
        {
            permutations = toVector(constructPermutations(characters, permutationLength));
        }

        bool hasNext()
        {
            return ptr < permutations.size();
        }

        string next()
        {
            assert(hasNext());
            return permutations[ptr++];
        }
};

int main(int argc, char const *argv[])
{
    PermutationIterator it("ABCD", 2);

    // 4P2 = 4! / (4 - 2)! = 4 * 3 = 12 object
    
    while (it.hasNext()) {
        cout << it.next() << endl;
    }
    return 0;
}
