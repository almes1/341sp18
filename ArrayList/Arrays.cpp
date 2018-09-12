#include <iostream>
#include "Arrays.h"


Arrays::Arrays(unsigned int initial_size) {
    array = new int[initial_size];
    capacity = initial_size;
    num_items = 0;
}

// Delete
Arrays::~Arrays() {
    if (array != nullptr) {
        delete[] array;
        array = nullptr;
        num_items = 0;
        capacity = 0;
    }
}

// Copy
Arrays::Arrays(const Arrays &other) {
    capacity = other.capacity;
    num_items = other.num_items;
    array = new int[capacity];

    for (int i = 0; i < num_items; ++i) {
        array[i] = other.array[i];
    }
}

// Assignment operator
Arrays& Arrays::operator=(const Arrays& other)
{
    // Ignore self assignment
    if (this != &other) {
        // save time on allocating memory if already matching
        if (other.capacity != capacity) {
            capacity = other.capacity;
            delete[] array; // clean up old memory
            array = new int[capacity];
        }

        // now copy everything over
        num_items = other.num_items;
        for(int i = 0; i < num_items; ++i){
            array[i] = other.array[i];
        }
    }

    return *this;
}

int Arrays::Find(int needle) {
    for (int i = 0; i < num_items; ++i) {
        if (needle == array[i]) {
            return i;
        }
    }
    return -1;
}

void Arrays::Remove(int needle) {
    // Search for needle, if it doesn't exist exit
    int index = Find(needle);
    if (index < 0) {
        return;
    }

    // copy all items after first of occurrence of needle to the left
    for (int i = index; i < num_items - 1; ++i) {
        array[i] = array[i + 1];
    }

    --num_items;
}

void Arrays::Insert(int x, unsigned int position) {
    if (num_items == capacity) {
        throw "At capactity";
    }

    if (position > num_items || position >= capacity) {
        throw "Out of bounds";
    }

    int next_insert = x;
    num_items++;
    // copy items after insertion point to the right
    for (int i = position; i < num_items; ++i) {
        int tmp = array[i];
        array[i] = next_insert;
        next_insert = tmp;
    }
}


void Arrays::Append(int next) {
    Insert(next, num_items);
}

void Arrays::Print() {
    std::cout << "[ ";
    for (int i = 0; i < num_items; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int Arrays::FindKth(unsigned int k) {
        if (k < 0 || k > num_items) {
            throw "Out of bounds errors";
        }

    return array[k];
}

