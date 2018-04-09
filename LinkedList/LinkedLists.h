//
// Created by almess1 on 9/10/17.
//

#ifndef UMBC_LINKED_LISTS_H
#define UMBC_LINKED_LISTS_H

template <class T>
struct node {
    T data;
    node *next;

    explicit node(T data){
        this->data = data;
    };

    ~node(){
        if(next != NULL)
            delete next;
        next = NULL;
    }
};

template <class T>
class LinkedLists {
    node<T>* head;
    unsigned int size;

public:
    // Create
    LinkedLists(): head(NULL), size(0){};

    // Delete
    ~LinkedLists();

    // Copy
    LinkedLists(const LinkedLists &other);

    const node<T>* Find(T needle);

    void Remove(T needle);

    void Insert(T x, unsigned int position);

    bool IsEmpty() { return size == 0; }

    bool IsFull() { return false; } // our implementation is never full

    void MakeEmpty() { size = 0; }

    // TODO: in class
    T FindKth(unsigned int k);

    void Append(T append_me);

    // TODO: in class
    void Print();
};

#include "LinkedLists.cpp"
#endif //UMBC_LINKED_LISTS_H
