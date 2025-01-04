#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

struct Trie {
    bool isWordComplete;
    Trie* children[26];
    Trie() {
        isWordComplete = false;
        memset(children, 0, sizeof(children)); // set to nullptr for all elements in array
    }
};

class WordDictionary {
    private:
        Trie* root;
    public:
        WordDictionary() {
            root = new Trie();
        }

        void addWord(string word) {
            Trie* curr = root;

            for (char ch : word) {
                int idx = ch - 'a';
                if (curr->children[idx] == nullptr) {
                    curr->children[idx] = new Trie();
                }

                curr = curr->children[idx];
            }

            curr->isWordComplete = true;
        }

        bool search(string word, Trie* _curr = nullptr) {
            Trie* curr = root;
            if (_curr != nullptr) {
                curr = _curr;
            }

            if (curr == nullptr && word.length() > 0) {
                return false;
            }

            for (int i = 0; i < word.length(); i++) {
                char ch = word[i];
                int idx = ch - 'a';

                if (ch == '.') {
                    for (int j = 0; j < 26; j++) {
                        if (curr->children[j] != nullptr && search(word.substr(i + 1), curr->children[j])) {
                            return true;
                        }
                    }

                    return false;
                } else {
                    if (curr->children[idx] == nullptr) {
                        return false;
                    }
                }

                curr = curr->children[idx];
            }

            return curr ? curr->isWordComplete : false;
        }
};

int main() {
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("rat");
    dict.addWord("wat");

    printf("Is rat exists? %d\n", dict.search("rat"));
    printf("Is .at exists? %d", dict.search(".aat"));

    return 0;
}