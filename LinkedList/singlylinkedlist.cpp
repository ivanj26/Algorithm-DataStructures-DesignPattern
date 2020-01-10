/**
 * File   : singlylinkedlist.cpp
 * Author : Ivan Jonathan
 **/

#include "./Node/singlynode.cpp"
#include <cassert>
#include <vector>
#include <set>

using namespace std;

template <class T>
class SinglyLinkedList {
  private:
    SinglyNode<T>* head;
  public:
    SinglyLinkedList() {
      head = nullptr;
    }
    SinglyLinkedList(SinglyNode<T>* _head): head(_head) {}
    ~SinglyLinkedList() {
      SinglyNode<T>* curr = head;

      while (curr != nullptr) {
        SinglyNode<T> *next = curr->getNext();

        delete curr;
        curr = next;
      }
    }

    friend ostream& operator<<(ostream& os, SinglyLinkedList& l){
      SinglyNode<T>* temp = l.front();

      while (temp != nullptr) {
        os << temp->getData() << endl;
        temp = temp->getNext();
      }

      return os; 
    }

    /**
     * LinkedList operation
     * */     
    SinglyNode<T>* front() { return head; }

    void push(T t) {
      SinglyNode<T>* temp = head;

      if (temp == nullptr) {
        head = new SinglyNode<T>(t);
      } else {
        while (temp->getNext() != nullptr) {
          temp = temp->getNext();
        }

        temp->setNext(t);
      }
    }

    void push(SinglyNode<T>* node) {
      SinglyNode<T>* temp = head;

      if (temp == nullptr) {
        head = node;
      } else {
        while (temp->getNext() != nullptr) {
          temp = temp->getNext();
        }

        temp->setNext(node);
      }
    }

    void deleteAt(long idx) {
      assert(idx >= 0);
      if (head == nullptr) return;

      SinglyNode<T> *prev = nullptr;
      SinglyNode<T> *curr = head;
      SinglyNode<T> *next = curr->getNext();
      
      if (idx > 0) {
        long i = 0;
        while (i < idx && curr) {
          prev = curr;
          curr = next;

          if (next == nullptr) {
            cout << "Index out of bound!" << endl;
            return;
          } else {
            next = next->getNext();
          }

          i++;
        }
    
        if (prev != nullptr) {
          prev->setNext(next);
          }

        delete curr;
      } else {
        head = next;
      }
    }

    long count() {
      if (head == nullptr) {
        return 0;
      }

      SinglyNode<T>* temp = head;
      long c = 0;
      while (temp) {
        temp = temp->getNext();
        c++;
      }

      return c;
    }

    //Search for first occurrence
    long search(T value) {
      SinglyNode<T>* temp = head;

      long idx = 0;
      while (temp != nullptr) {
        if (temp->getData() == value) {
          return idx;
        }

        temp = temp->getNext();
        idx++;
      }

      return -1;
    }

    //Search for occurrences
    vector<int> searchOccurrences(T value) {
      vector<int> vec;
      SinglyNode<T>* temp = head;
      long i = 0;

      while (temp != nullptr) {
        if (temp->getData() == value) {
          vec.push_back(i);
        }

        i++;
        temp = temp->getNext();
      }

      return vec;
    }

    T at(long idx) {
      assert(idx >= 0);
      SinglyNode<T>* temp = head;

      long i = 0;
      while (temp != nullptr) {
        if (idx == i) return temp->getData();
        temp = temp->getNext();
        i++;
      }

      return -1;
    }

    void printNthToLast(long idx) {
      assert(idx >= 0);

      long i = 0;
      SinglyNode<T>* temp = head;

      while (temp != nullptr && i < idx) {
        temp = temp->getNext();
        i++;
      }

      while (temp != nullptr) {
        cout << temp->getData() << endl;
        temp = temp->getNext();
      }
    }

    SinglyLinkedList<T> sub(long from, long to) {
      assert(from <= to && from >= 0 && to >= 0);

      long i = 0;
      SinglyNode<T>* temp = head;
      while (i < from && temp != nullptr) {
        temp = temp->getNext();
        i++;
      }

      SinglyLinkedList<T> list;
      for (long j = from; j <= to; j++)
      {
        if (temp != nullptr) {
          list.push(temp->getData());
          temp = temp->getNext();
        }
        else return list;
      }

      return list;
    }

    bool isCyclic() {
      set<SinglyNode<T>*> s;

      SinglyNode<T>* temp = head;
      while (temp != nullptr) {
        if (s.find(temp) != s.end()) return true;
        s.insert(temp);

        temp = temp->getNext();
      }

      return false;
    }
};

int main(int argc, char const *argv[])
{
  SinglyLinkedList<float> list;

  list.push(new SinglyNode<float>(1.0));
  list.push(new SinglyNode<float>(2.0));
  list.push(new SinglyNode<float>(3.0));

  //Insert data to linkedlist
  // for (int i = 0; i < 20; i++)
  // {
  //   list.push(i);
  // }

  //Print list
  // cout << list;
  // cout << "Count: " << list.count() << endl;

  //Search occurences
  // vector<int> indices = list.searchOccurrences(0);
  // for (int i = 0; i < indices.size(); i++)
  // {
  //   cout << indices.at(i) << endl;
  // }

  //Delete element from linkedlist
  // list.deleteAt(3);
  // cout << list;

  //Get nth node in list
  // cout << list.at(3);

  //Print from nth to last
  // list.printNthToLast(15);

  //Sublist
  // SinglyLinkedList<float> sublist = list.sub(5, 10);
  // cout << sublist;

  return 0;
}
