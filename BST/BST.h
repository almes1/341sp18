#include <iostream>
#include <cmath>

#include <cstdlib>
#include <queue>
#include <iomanip>

using namespace std;

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

    int height(Node *p);

    bool remove(int value);

    void print() ;

    void printRow(const Node *p, const int height, int depth) ;

    void getLine(const Node *root, int depth, vector<int>& vals) ;

};
