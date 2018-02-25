//
// Created by almess1 on 9/10/17.
//
#include <iostream>
#include "Arrays.h"

// Create
Arrays::Arrays() {
    num_items = 0;
    array_size = 0;
    array = NULL;
}

Arrays::Arrays(unsigned int initial_size) {
    num_items = 0;
    array_size = initial_size;
    array = new int[array_size];
}

// Delete
Arrays::~Arrays() {
    if (array != NULL) {
        delete[] array;
        array = NULL;
    }
    num_items = 0;
    array_size = 0;
}

// Copy
Arrays::Arrays(const Arrays &other) {
    num_items = other.num_items;
    array_size = other.array_size;
    array = new int[array_size];
    for (int i = 0; i < num_items; ++i) {
        array[i] = other.array[i];
    }
}

int Arrays::Find(int needle) {
    for (int i = 0; i < num_items; ++i) {
        if (array[i] == needle) {
            return i;
        }
    }
    return -1;
}

// only removes first
void Arrays::Remove(int needle) {
    int remove_location = Find(needle);
    if (remove_location == -1) {
        return;
    }
    --num_items;
    for (int ri = remove_location; ri < num_items; ri++) {
        array[ri] = array[ri + 1];
    }
    Remove(needle);
}

void Arrays::Insert(int x, unsigned int position) {
    if (position >= array_size) {
        throw "Out of bounds error";
    }
    if (num_items + 1 > array_size) {
        throw "Overflow error";
    }
    if (position > num_items || position < 0) {
        throw "Out of bounds error";
    }
    num_items++;
    for (int ii = num_items; ii > position; --ii) {
        array[ii] = array[ii - 1];
    }
    array[position] = x;
}

int Arrays::FindKth(unsigned int k) {
    if (k >= num_items) {
        throw "Index out of bounds";
    }
    return array[k];
}

void Arrays::Print() {
    std::cout << "[ ";
    for (int i = 0; i < num_items; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void Arrays::Append(int next) {
    Insert(next, num_items);
}
