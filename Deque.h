#pragma once
#include<iostream>
template<class T> struct Node {

    T* Data;
    Node<T>* Next;
    Node<T>* Prev;
    Node(T* data) {
        this->Data = data;
        Next = NULL;
        Prev = NULL;
    }
};

template<class T>
class Deque {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
protected:
    int size;
public:
    //Constructor without params
    Deque() {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    T* pop_back() {// Erases the element at the end of the deque
        if (head) {
            Node<T>* tail = new Node<T>(NULL);
            for (Node<T>* i = head; i != NULL; i = i->Next) {
                if (i->Next == NULL)
                    tail = i;
            }
            T* temp = tail->Data;
            Node<T>* p = tail;
            tail = p->Prev;
            tail->Next = NULL;
            size--;
            return temp;
        } else
            return NULL;
    }
    T* pop_front(){ // Erases the element at the start of the deque
        if (head) {
            int* temp = head->Data;
            Node<T>* p = head;
            head = p->Next;
            delete[] p;
            size--;
            return temp;
        } else
            return NULL;

    }
    void push_front(T* data) {// Adds an element to the start of the deque
        size++;
        if (head != NULL) {
            Node<T> *temp = new Node<T>(data);
            temp->Next = head;
            head->Prev = temp;
            head = temp;
        } else {
            head = new Node<T>(data);
        }
    }
    void push_back(T* data){ // Adds an element to the end of the deque
        size++;
        if (head != NULL) {
            Node<T>* tail = new Node<T>(NULL);
            for (Node<T>* i = head; i != NULL; i = i->Next) {
                if (i->Next == NULL)
                    tail = i;
            }
            Node<T>* temp = new Node<T>(data);
            tail->Next = temp;
            temp->Prev = tail;
            tail = temp;
        } else {
            head = new Node<T>(data);
        }
    }

    int size_deque() {// Returns the number of elements in the deque
        return size;
    }

    const T peek() {
        if (head)
            return *head->Data;
        else
            return 0;
    }

    const bool isEmpty() {
        return size == 0;
    }
    T& operator= (const Deque& obj) {
        if (this == &obj)
            return *this;
        if (!obj.head)
            return *this;
        head = new Node<T>(obj.head->Data);
        Node<T>* temp = obj.head->Next;
        Node<T>* pnew = 0;
        Node<T>* pold = head;
        while (temp) {
            pnew = new Node<T>(temp->Data);
            pnew->Prev = pold;
            pold->Next = pnew;
            pold = pnew;
            temp = temp->Next;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Deque<T>& obj) {
        for (Node<T>* i = obj.head; i != NULL; i = i->Next)
            os << *i->Data  << " ";
        return os;
    }
    void operator !(){
        for (Node<T>* i = this->head; i != NULL; i = i->Next) {
            std::cout << (*i->Data - 2 * (*i->Data))<< " ";
        }
        return;
    }

};