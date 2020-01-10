/**
 * File   : singlylinkedlist2.cpp
 * Author : Ivan Jonathan
 **/

#include "./Node/singlynode.cpp"
#include <cassert>
#include <vector>
#include <set>

using namespace std;

/**
 * SinglyLinkedList2 with tail pointer
 **/
template <class T>
class SinglyLinkedList2 {
  private:
    SinglyNode<T>* head;
    SinglyNode<T>* tail;
  public:
    SinglyLinkedList2(SinglyNode<T>* _head) : head(_head), tail(_head) {}
    SinglyLinkedList2() {
      head = nullptr;
      tail = nullptr;
    }
    ~SinglyLinkedList2() {
      SinglyNode<T>* temp = head;

      while (temp != nullptr) {
        SinglyNode<T>* next = temp->getNext();
        delete temp;

        temp = next;
      }
    }

    /* linkedlist operation */
    void push_back(SinglyNode<T>* node) {
      if (head != nullptr) {
        SinglyNode<T>* last = tail;
        last->setNext(node);

        tail = node;
      } else {
        head = node;
        tail = node;
      }
    }

    void push_back(T t) {
      if (head != nullptr) {
        SinglyNode<T>* last = tail;
        SinglyNode<T>* node = new SinglyNode<T>(t);
        last->setNext(node);

        tail = node;
      } else {
        SinglyNode<T>* node = new SinglyNode<T>(t);
        head = node;
        tail = node;
      }
    }

    T front() {
      if (head == nullptr) {
        throw "An empty list";
      }
      return head->getData();
    }

    void pop() {
      if (head == nullptr) return;

      SinglyNode<T>* temp = head;
      SinglyNode<T>* next = temp->getNext();
      delete temp;

      head = next;
    }

    friend ostream& operator<<(ostream& os, SinglyLinkedList2<T>& l) {
      SinglyNode<T>* temp = l.getHead();

      while (temp != nullptr) {
        os << temp->getData() << endl;
        temp = temp->getNext();
      }

      return os;
    }

    SinglyNode<T>* getHead() {
      return head;
    }
};

int main(int argc, char const *argv[])
{
  SinglyLinkedList2<int> list;
  
  try {
    list.push_back(2);
    list.push_back(5);
    list.pop();

    cout << list;
  } catch (const char* msg) {
    cout << msg;
  }

  return 0;
}
