#include <iostream>
#include <cmath>

struct Node{
    int value;
    Node *left;
    Node *right;
    Node* parent;

    explicit Node(int val);
    Node(int val, Node* left, Node* right);
    Node(const Node& other);
    bool find(int needle);

    int height();
    bool remove(int needle);
    void insert(int newValue);

    void print();

    ~Node();

};

class BST {

private:
    Node *root;
    int size;

    void addHelper(Node *root, int val){throw "Not implemented";}

    void printHelper(Node *root){throw "Not implemented";}

    int nodesCountHelper(Node *root){throw "Not implemented";}

    int heightHelper(Node *root){throw "Not implemented";}

    void printMaxPathHelper(Node *root){throw "Not implemented";}

    bool deleteValueHelper(Node *parent, Node *current, int value){throw "Not implemented";}

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
