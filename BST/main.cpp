#include <iostream>
#include "BST.h"

int main() {
    try {
        int node_count = 0;
        BST *bst = new BST();

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

        node_count += 7;

        // Find 5 now
        if (!bst->find(5) || bst->isEmpty()) {
            throw "Tree should have a 5";
        }
        // remove node with no child
        if(!bst->remove(5)){
            throw "5 could not be removed...";
        }
        node_count--;

        // attempt to remove 5 again (fail)
        if(bst->remove(5)){
            throw "Deleted 5 successfully twice...";
        }
        // Remove node with 1 child, try again
        if(!bst->remove(-1) || bst->remove(-1)){
            throw "Did not successfully remove/unlink node with 1 child";
        }
        node_count--;
        // remove node with 2 children, try again
        if(!bst->remove(1) || bst->remove(1)){
            throw "Did not successfully remove/unlink node with 2 children";
        }
        node_count--;
        // remove root
        if(!bst->remove(11) || bst->remove(11)){
            throw "Did not successfully remove/unlink root node";
        }
        node_count--;
        // Test removed 5
        if (bst->isEmpty() || bst->get_size() != node_count) {
            throw "Tree is now the wrong size";
        }

    }catch(const char * err){
        std::cerr << "TESTING ERROR" << std::endl;
        std::cout << err << std::endl;
        return -1;
    }
    std::cout << "All tests completed successfully" << std::endl;
    return 0;
}
