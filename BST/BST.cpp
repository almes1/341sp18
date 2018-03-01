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

bool Node::find(int needle) const{
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

int Node::findMinValue(){
  Node* min = findMin();
  return min->value;
}

int Node::findMaxValue(){
  Node* max = findMax();
  return max->value;
}

Node* Node::findMin(){
  if(left != NULL){
    return left->findMin();
  }
  return this;
}

Node* Node::findMax(){
  if(right != NULL){
    return right->findMax();
  }
  return this;
}

void Node::print() const{
  std::cout << " " << value << " " << std::endl;
    if(left != NULL) {
        left->print();
    }
    if(right != NULL) {
        right->print();
    }
}

int Node::getHeight() const{
    throw "Not implemented";
}

bool Node::remove(int needle, Node** parentRelation) {
  if(value > needle){
    // Potentially in left subtree
    if (left != NULL){
      return left->remove(needle, &left);
    }
  }else if(value < needle){
    // Potentially in right subtree
    if (right != NULL){
      return right->remove(needle, &right);
    }
  }else{
    // Found needle!
    if (left == NULL && right == NULL){
      // I have no children, nothing to pass to parent
      *parentRelation = NULL;
    }else if (left != NULL){
      if(right != NULL){
       // swap current value with replacement (max of left subtree or min of right subtree)
       Node* replacement = left->findMax();
       value = replacement->value;
       replacement->value = needle;
       // delete the child, not this node
       return left->remove(needle, &left);
      }else{
        // only a left child
        *parentRelation = left;
      }
    }else{
      // only a right child
      *parentRelation = right;
    }

    // prevent filicide (killing of children)
    left = NULL;
    right = NULL;

    // cleanup memory
    delete this;
    return true;
  }
  // There was no left/right child, therefor needle is not in haystack
  return false;

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

int BST::height(Node *p) {
  if (!p) return 0;
  int leftHeight = height(p->left);
  int rightHeight = height(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;

}

bool BST::remove(int value) {
    if (root != NULL){
        if(root->remove(value, &root)){
          size--;
          return true;
        }
    }
  return false;
}

/*
        11
       /   \
       1   100
     /   \
    -1   6
    /   /
  -10   5
*/
// create a pretty vertical tree
void BST::printTree()
{
  int h = height(root) + 1;
  for (int i = 0 ; i < h; i ++) {
     printRow(root, h, i);
  }
}

void BST::printRow(const Node *p, const int h, int depth)
{
        vector<int> vec;
        int placeholder = 0;
        getLine(p, depth, vec);
        cout << setw((h - depth)*2); // scale setw with depth
        bool toggle = true; // start with left
        if (vec.size() > 1) {
                for (int i = 0 ; i < vec.size() ; i++ ) {
                        if (vec[i] != placeholder) {
                                if (toggle)
                                        cout << "/" << "   ";
                                else
                                        cout << "\\" << "   ";
                        }
                        toggle = !toggle;
                }
                cout << endl;
                cout << setw((h - depth)*2);
        }
        for (int i = 0 ; i < vec.size() ; i++ ) {
                if (vec[i] != placeholder)
                        cout << vec[i] << "   ";
        }
        cout << endl;
}

void BST::getLine(const Node *root, int depth, vector<int>& vals)
{
  int placeholder = 0;
        if (depth <= 0 && root != NULL) {
                vals.push_back(root->value);
                return;
        }
        if (root->left != NULL)
                getLine(root->left, depth-1, vals);
        else if (depth-1 <= 0)
                vals.push_back(placeholder);
        if (root->right != NULL)
                getLine(root->right, depth-1, vals);
        else if (depth-1 <= 0)
                vals.push_back(placeholder);
}
