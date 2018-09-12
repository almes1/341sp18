#include <iostream>
#include "Arrays.h"

bool tests();

int main() {
    return tests() ? 0 : 255;
}


// Much more precise tests
bool tests() {
    try {
        int global_counter = 0;

        Arrays someBuff = Arrays(15);

        // Expect to see []
        someBuff.Print();

        while (!someBuff.IsFull())
            someBuff.Insert(global_counter, global_counter++);

        std::cout << "List is full." << std::endl;
        someBuff.Print();

        try {
            std::cout << "Attempt to overfill list (error expected)." << std::endl;
            someBuff.Insert(global_counter, global_counter);
            // should have generated error, buffer was full
            return false;
        } catch (const char *) {
            std::cout << "Overfill caught." << std::endl;
        }

        // Delete from front
        int i = someBuff.FindKth(0);
        someBuff.Remove(i);
        someBuff.Print();

        // Delete from back
        someBuff.Append(-1);
        someBuff.Remove(-1);
        someBuff.Print();

        someBuff.Append(-2);
        // List was full, we removed 2 then added 2, should be full again
        if (!someBuff.IsFull())
            return false;

        someBuff.MakeEmpty();

        // should be empty now
        if (!someBuff.IsEmpty())
            return false;

        // Expect to see []
        someBuff.Print();
    } catch (const char *message) {
        std::cout << "Unknown critical error occurred during test:\n" << message << std::endl;
        return false;
    }
    std::cout << "All tests succeeded" << std::endl;
    return true;
}