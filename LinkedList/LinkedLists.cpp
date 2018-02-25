//
// Created by almess1 on 9/10/17.
//

#include <iostream>
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
            if(previous == NULL){
                head = current->next;
            }else {
                previous->next = current->next;
            }
            current->next = NULL;
            delete current;
            size --;
            return;
        }
        previous = current;
    }
}

void LinkedLists::Insert(int x, unsigned int position) {
    if (position > size){
        throw "Out of bounds";
    }

    node* current = head;
    node* node_x = new node(x);
    if(position == 0){
        head = node_x;
        node_x->next = current;
        size++;
        return;
    }

    for(int i = 0; i < position - 1; ++i){
        if(current->next) {
            current = current->next;
        }else{
            throw "Bad pointer";
        }
    }
    if(current) {
        node_x->next = current->next;
        current->next = node_x;
        size ++;
        return;
    }
    throw "Another pointer error";

}

void LinkedLists::Append(int append_me) {
    Insert(append_me, size);
}

int LinkedLists::FindKth(unsigned int k) {
    if(k >= size){
        throw "Out of bounds";
    }

    node* current = head;
    for(int i = 0; i < k; ++i){
        if(current->next) {
            current = current->next;
        }else{
            throw "Bad pointer";
        }
    }
    if(current) {
        return current->data;
    }

    throw "Another pointer error";
}

void LinkedLists::Print() {
    node* current = head;
    while(current != NULL) {
        std::cout << current->data << "-> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;

}
