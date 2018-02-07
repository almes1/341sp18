//
// Created by almess1 on 9/10/17.
//

#ifndef UMBC_ARRAYS_H
#define UMBC_ARRAYS_H

#include <zconf.h>

class Arrays {
private:
    int* array;
    uint num_items;
    uint array_size;
public:
    // Create
    Arrays();

    explicit Arrays(uint initial_size = 50);

    // Delete
    ~Arrays();

    // Copy
    Arrays(const Arrays &other);

    int Find(int needle);

    void Remove(int needle);
    void Insert(int x, uint position);
    bool IsEmpty(){ return num_items <= 0;}
    bool IsFull(){ return num_items >= array_size;}
    void MakeEmpty(){ num_items = 0;}
    int FindKth(uint k);

    void Append(int next);

    void Print();
};


#endif //UMBC_ARRAYS_H
