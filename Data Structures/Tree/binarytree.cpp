#include <queue>
#include <iostream>
using namespace std;

template <class T>
class Tree {
    private:
        Tree<T> *left, *right;
        T value;

        void printInOrderUtil(Tree<T>* tree) {
            if (!tree) return;

            cout << "(";
            printInOrderUtil(tree->left);
            cout << ") ";

            cout << tree->getValue() << " ";

            cout << "(";
            printInOrderUtil(tree->right);
            cout << ")";
        }
    public:
        Tree(T value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }

        Tree<T>* getLeft() const {
            return this->left;
        }

        Tree<T>* getRight() const {
            return this->right;
        }

        void setRight(Tree<T>* tree) {
            this->right = tree;
        }

        void setLeft(Tree<T>* tree) {
            this->left = tree;
        }

        T getValue() {
            return this->value;
        }

        void insert(T newVal) {
            queue<Tree<T>*> q;
            q.push(this);

            while (!q.empty()) {
                Tree<T>* t = q.front();
                q.pop();

                if (t->getValue() < newVal) {
                    Tree<T>* right = t->getRight();
                    
                    if (right) {
                        q.push(right);
                    } else {
                        t->setRight(new Tree(newVal));
                        break;
                    }
                } else {
                    Tree<T>* left = t->getLeft();

                    if (left) {
                        q.push(left);
                    } else {
                        t->setLeft(new Tree(newVal));
                        break;
                    }
                }
            }
        }

        void printInOrder() {
            printInOrderUtil(this);
            cout << endl;
        }

        void search(T value) {
            //Do search algo
        }
};

int main(int argc, const char** argv) {
    Tree<int> tree(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);

    tree.printInOrder();
    return 0;
}