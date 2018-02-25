#include "BST.h"

Node::Node(int val) {
    value = val;
    left = NULL;
    right = NULL;
}

Node::Node(int val, Node *left, Node *right) {
    value = val;
    this->left = left;
    this->right = right;
}

Node::~Node() {
    if (left != NULL) {
        delete left;
        left = NULL;

    }
    if(right != NULL) {
        delete right;
        right = NULL;
    }
}

Node::Node(const Node &other) {
    value = other.value;
    if(other.left) {
        left = new Node(*(other.left));
    }else{
        left = NULL;
    }
    if (other.right) {
        right = new Node(*(other.right));
    }else{
        right = NULL;
    }
}

void Node::insert(int newValue) {
    if(newValue <= value){
        if(left != NULL){
            left->insert(newValue);
        }else{
            left = new Node(newValue);
        }
    }
    else{
        if(right != NULL){
            right->insert(newValue);
        }else{
            right = new Node(newValue);
        }
    }
}

bool Node::find(int needle) {
    if(needle == value){
        return true;
    }
    if(needle < value){
        if(left != NULL){
            return left->find(needle);
        }
    }
    else {
        if (right != NULL) {
            return right->find(needle);
        }
    }
    return false;
}

void Node::print() {
    if(left != NULL) {
        left->print();
    }
    std::cout << " " << value << " " << std::endl;
    if(right != NULL) {
        right->print();
    }
}

int Node::height() {
    throw "Not implemented";
}

bool Node::remove(int needle) {
    throw "Implemented";
}

BST::BST() {
    size = 0;
    root = NULL;
}

BST::BST(const BST &other) {
    size = other.size;
    root = new Node(*(other.root));
}

BST::~BST() {
    if(root != NULL) {
        delete root;
    }
    root = NULL;
    size = 0;
}

void BST::add(int val) {
    if(root != NULL){
        root->insert(val);
        size++;
    }else{
        root = new Node(val);
        size = 1;
    }
}

bool BST::find(int val) {
    if(root != NULL){
        return root->find(val);
    }
    return false;
}

void BST::print() {
    std::cout << "Tree output" << std::endl;
    if(root != NULL){
        root->print();
    }
    else{
        std::cout << "<TREE Empty >" << std::endl;
    }
}

int BST::height() {
    throw "Not implemented";
}

bool BST::remove(int value) {
    if (root != NULL){
        root = root->remove(value);
    }
}
