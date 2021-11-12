/**
 * @file doublylinkedlist.cpp
 * @author Ivan Jonathan
 * @brief
 * @version 0.1
 * @date 2021-11-13
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "./Node/doublynode.cpp"

template <class T>
class DoublyLinkedList {
    private:
        DoublyNode<T> *head;

    public:
        /**
         * @brief Construct a new Doubly Linked List object
         *
         */
        DoublyLinkedList()
        {
            head = nullptr;
        }

        /**
         * @brief Copy construct a Doubly Linked List object
         * 
         * @param list 
         */
        DoublyLinkedList(const DoublyLinkedList<T> &list)
        {
            head = list.head;
        }

        /**
         * @brief Get head of DoublyLinkedList.
         * 
         * @return DoublyNode<T>* 
         */
        DoublyNode<T> *front()
        {
            return head;
        }        

        /**
         * @brief Reverse the DobulyLinkedList by changing its pointer.
         * 
         * @param node 
         */
        void reverse()
        {
            DoublyNode<T> *curr = this->front();
            DoublyNode<T> *next = nullptr;
            DoublyNode<T> *prev = nullptr;

            while (curr) {
                next = curr->getNext();
                prev = curr->getPrev();

                if (prev) {
                    curr->setNext(prev);
                }

                if (next) {
                    curr->setPrev(next);
                } else {
                    head = curr;
                }

                curr = next;
            }
        }
};
