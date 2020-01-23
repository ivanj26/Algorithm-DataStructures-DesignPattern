#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Tree {
    private:
        Tree<T> *left, *right;
        T value;

        //Left - Root - Right
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

        //Root - Left - Right
        void printPreOrderUtil(Tree<T>* tree) {
            if (!tree) return;

            cout << tree->getValue() << " ";

            cout << "(";
            printPreOrderUtil(tree->getLeft());
            cout << ")";

            cout << " (";
            printPreOrderUtil(tree->getRight());
            cout << ")";
        }

        //Left - Right - Root
        void printPostOrderUtil(Tree<T>* tree) {
            if (!tree) return;

            cout << "(";
            printPostOrderUtil(tree->getLeft());
            cout << ") ";

            cout << "(";
            printPostOrderUtil(tree->getRight());
            cout << ") ";

            cout << tree->getValue();
        }

        int heightUtil(Tree<T>* root){
            if (!root) return -1;

            int left = 1 + heightUtil(root->left);
            int right = 1 + heightUtil(root->right);

            return left > right ? left : right;
        }

        bool isSymmetricUtil(Tree<T>* left, Tree<T>* right) {
            //if left has no children and right ones too
            if (left && right) {
                if (!left->left && !left->right && !right->left && !right->right) {
                    if (left->value == right->value) return true;
                    else return false;
                }   
            }
            else if (!left || !right) return false;
            else return true;
            
            return isSymmetricUtil(left->right, right->left) && isSymmetricUtil(left->left, right->right);
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

        void printPreOrder() {
            printPreOrderUtil(this);
            cout << endl;
        }

        void printPostOrder() {
            printPostOrderUtil(this);
            cout << endl;
        }

        vector<T> largestValuesInTreeRows(Tree<T> * t) {
            vector<T> vec;
            queue<Tree<T>*> q;
            
            if (!t) return vec;
            q.push(t);
            
            while (!q.empty()) {
                Tree<T>* tr = q.front();
                Tree<T>* tr2 = nullptr;
                q.pop();
                
                Tree<T>* left = tr->left;
                Tree<T>* right = tr->right;
                
                if (q.empty()) {
                    vec.push_back(tr->value);
                    
                    if (left) q.push(left);
                    if (right) q.push(right);
                } else {
                    //vector to save subtree in same depth
                    vector<Tree<T>*> vec2;
                    
                    //push tree with same depth
                    while (!q.empty()) {
                        vec2.push_back(q.front());
                        q.pop();
                    }
                    
                    if (left) q.push(left);
                    if (right) q.push(right);
                    
                    //get maximum in same depth
                    int max = tr->value;
                    for (auto i : vec2) {
                        Tree<T>* temp = i;
                        left = temp->left;
                        right = temp->right;
                        
                        int val = temp->value;
                        if (max < val) max = val;
                        
                        if (left) q.push(left);
                        if (right) q.push(right);
                    }
                    
                    vec.push_back(max);
                }
            }
            
            return vec;
        }

        //Print by using BFS Algorithm style
        void levelOrder() {
            queue<Tree<T>*> q;
            q.push(this);

            while (!q.empty()) {
                Tree<T>* t = q.front();
                q.pop();

                cout << t->getValue() << " ";

                if (t->left) {
                    q.push(t->left);
                }

                if (t->right) {
                    q.push(t->right);
                }
            }
        }

        int height() {
            return heightUtil(this);
        }

        bool isSymmetric() {
            if (this->getLeft && this->getRight) {
                bool isSymmetric = isSymmetricUtil(this->getLeft, this->getRight);
                
                return isSymmetric;
            } else if (!this->getLeft || !this->getRight)
                return false;
            else
                return true;
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

    // tree.printPreOrder();
    // tree.printPostOrder();
    tree.levelOrder();

    // cout << tree.height();
    return 0;
}