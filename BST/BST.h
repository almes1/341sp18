#include <iostream>
#include <cmath>

struct Node{
    int value;
    Node *left;
    Node *right;

    explicit Node(int val);
    Node(int val, Node* left, Node* right);
    Node(const Node& other);
    ~Node();
    bool find(int needle) const;
    int getHeight() const;
    
    int findMinValue();
    int findMaxValue();
    
    bool remove(int needle, Node** parentRelation);
    void insert(int newValue);

    void print() const;
private:
  Node * findMin();
  Node * findMax();

};

class BST {
    Node *root;
    int size;

public:
    BST();
    ~BST();

    BST(const BST& other);

    void add(int val);

    bool find(int val);

    bool isEmpty(){
        return size == 0;
    };

    int get_size(){
        return size;
    };

    void print();

    int height();

    bool remove(int value);
};
