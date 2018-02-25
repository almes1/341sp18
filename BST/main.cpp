#include <iostream>
#include "BST.h"

int main() {
    try {
        int node_count = 0;
        BST *bst = new BST();

        std::cout << "Print empty tree" << std::endl;
        bst->print();

        // Test empty tree
        if (bst->find(5) || !bst->isEmpty()) {
            throw "Tree should be empty";
        }

        bst->add(11);
        bst->add(1);
        bst->add(6);
        bst->add(-1);
        bst->add(-10);
        bst->add(100);
        bst->add(5);

        std::cout << "Print empty tree" << std::endl;
        bst->print();

        node_count += 7;

        // Find 5 now
        if (!bst->find(5) || bst->isEmpty()) {
            throw "Tree should have a 5";
        }

        bst->remove(5);
        node_count--;

        // Test removed 5
        if (bst->find(5) || bst->isEmpty() || bst->get_size() != node_count) {
            throw "Tree should not contain 5, or is now the wrong size";
        }

    }catch(const char * err){
        std::cout << err << std::endl;
        return -1;
    }

    return 0;
}