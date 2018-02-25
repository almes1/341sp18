//
// Created by almess1 on 9/10/17.
//

#ifndef UMBC_LINKED_LISTS_H
#define UMBC_LINKED_LISTS_H

class node {
    friend class LinkedLists;
    int data;
    node *next;

    explicit node(int data){
        this->data = data;
    };

    ~node(){
        if(next != NULL)
            delete next;
        next = NULL;
    }
};

class LinkedLists {
    node* head;
    unsigned int size;

public:
    // Create
    LinkedLists(): head(NULL), size(0){};

    // Delete
    ~LinkedLists();

    // Copy
    LinkedLists(const LinkedLists &other);

    const node* Find(int needle);

    void Remove(int needle);

    void Insert(int x, unsigned int position);

    bool IsEmpty() { return size == 0; }

    bool IsFull() { return false; } // our implementation is never full

    void MakeEmpty() { size = 0; }

    // TODO: in class
    int FindKth(unsigned int k);

    void Append(int append_me);

    // TODO: in class
    void Print();
};

#endif //UMBC_LINKED_LISTS_H
