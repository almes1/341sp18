//
// Created by almess1 on 9/10/17.
//
#ifndef UMBC_LINKED_LISTS_CPP
#define UMBC_LINKED_LISTS_CPP

#include <iostream>
#include "LinkedLists.h"

template <class T>
LinkedLists<T>::~LinkedLists() {
    if (head != NULL){
        delete head;
        head = NULL;
    }
}

template <class T>
LinkedLists<T>::LinkedLists(const LinkedLists<T> &other) {
    //size = other.size;
    size = 0;

    if (other.head == NULL){
        head = NULL;
        return;
    }

    node<T>* tmp = other.head;
    head = new node<T>(tmp->data);
    while (tmp->next != NULL){
        tmp = tmp->next;
        head->next = new node<T>(tmp->data);
    }
}

template <class T>
const node<T>* LinkedLists<T>::Find(T needle) {
    node<T>* tmp = head;
    int i = 0;
    while(tmp != NULL){
        if (tmp->data == needle){
            return tmp;
        }
        ++i;
    }
    return NULL;
}

template <class T>
void LinkedLists<T>::Remove(T needle) {
    node<T>* current = head;
    node<T>* previous = NULL;

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

template <class T>
void LinkedLists<T>::Insert(T x, unsigned int position) {
    if (position > size){
        throw "Out of bounds";
    }

    node<T>* current = head;
    node<T>* node_x = new node<T>(x);
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

template <class T>
void LinkedLists<T>::Append(T append_me) {
    Insert(append_me, size);
}

template <class T>
T LinkedLists<T>::FindKth(unsigned int k) {
    if(k >= size){
        throw "Out of bounds";
    }

    node<T>* current = head;
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

template <class T>
void LinkedLists<T>::Print() {
    node<T>* current = head;
    while(current != NULL) {
        std::cout << current->data << "-> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;

}

#endif