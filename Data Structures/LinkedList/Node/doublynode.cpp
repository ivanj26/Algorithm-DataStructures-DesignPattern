/**
 * @file doublynode.cpp
 * @author Ivan Jonathan
 * @brief 
 * @version 0.1
 * @date 2021-11-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

template <class T>
class DoublyNode {
    private:
        T data;
        DoublyNode<T>* next;
        DoublyNode<T>* prev;
    public:
        DoublyNode(T _data): data(_data), next(nullptr), prev(nullptr) {}
        ~DoublyNode() {
            delete next;
            delete prev;
        }

        T getData() {
            return data;
        }

        void setData(T _data) {
            this->data = _data;
        }

        void setNext(DoublyNode<T>* n) {
            this->next = n;
        }

        void setPrev(DoublyNode<T>* n) {
            this->prev = n;
        }

        DoublyNode<T>* getNext() const {
            return this->next;
        }

        DoublyNode<T>* getPrev() const {
            return this->prev;
        }
};