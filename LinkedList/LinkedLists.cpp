//
// Created by almess1 on 9/10/17.
//

#include "LinkedLists.h"


LinkedLists::~LinkedLists() {
    if (head != NULL){
        delete head;
        head = NULL;
    }
}

LinkedLists::LinkedLists(const LinkedLists &other) {
    //size = other.size;
    size = 0;

    if (other.head == NULL){
        head = NULL;
        return;
    }

    node* tmp = other.head;
    head = new node(tmp->data);
    while (tmp->next != NULL){
        tmp = tmp->next;
        head->next = new node(tmp->data);
    }
}

const node* LinkedLists::Find(int needle) {
    node* tmp = head;
    int i = 0;
    while(tmp != NULL){
        if (tmp->data == needle){
            return tmp;
        }
        ++i;
    }
    return NULL;
}

void LinkedLists::Remove(int needle) {
    node* current = head;
    node* previous = NULL;

    while(current != NULL) {
        if (current->data == needle) {
            // TODO: in class
        }
        previous = current;
    }
}

void LinkedLists::Insert(int x, uint position) {
    if (position > size){
        throw "Out of bounds";
    }

    for(int i = 0; i < position; ++i){
        // TODO: in class
    }

}

void LinkedLists::Append(int append_me) {
    Insert(append_me, size);
}

/*
 * Meat of remove
 *   node* delete_me = current;
 *   current = current->next;
 *   if(previous != NULL){
 *       head = current;
 *   }
 *   delete delete_me;
 *   --size;
 *   return;
 */