#include <bst.hpp>

BSTNode::BSTNode() {
    this->left = this->right = NULL;
    this->height = 0;
}

BSTNode::BSTNode(int key, int height, int meta, BSTNode *left, BSTNode *right) {
    this->key = key;
    this->height = height;
    this->meta = meta;
    this->left = left;
    this->right = right;
}


BSTNode::~BSTNode() {
    this->left = this->right = NULL;
}

/*
    The constructor of BST initializes the empty BST, the implementation of the constructor is provided.
*/
BST::BST() {
    // YOU DO NOT NEED TO IMPLEMENT THIS ONE
    this->root = NULL;
}

/*
    The deconstructor of BST will deallocate memory of all nodes in the BST.
    You have to implement the deconstructor to release memory of all nodes.
*/
BST::~BST() {
    // YOUR CODE HERE
}

/*
    The find method will find the node that contains the key. 
    You have to implement the find method to return the node containing the given key.
*/
BSTNode* BST::find(int key) {
    // YOUR CODE HERE
}

/*
    The pop maximum method will return the node that contains the maximum value 
    and remove that node out BST but DO NOT release the memory of this maximum node. 
    You have to implement the pop maximum method to return the node containing the maximum value and remove it out of the BST.
*/
BSTNode* BST::popMaximum() {
    // YOUR CODE HERE
}

/* 
    The pop minimum method will return the node that contains the minimum value 
    and remove that node out BST but DO NOT release the memory of this minimum node. 
    You have to implement the pop minium method to return the node containing the minum value and remove it out of the BST.
*/
BSTNode* BST::popMinimum() {
    // YOUR CODE HERE
}

/*
    The insert method will insert a new node containing the key and meta data. 
    You have to implement the insert method to insert a new node with a given key and meta data into BST and return the new root of BST. 
*/
BSTNode* BST::insert(int key, int meta) {
    // YOUR CODE HERE
}

/*
    The remove method will remove a new node containing the key and meta data. 
    You have to implement the remove method to remove a node containing the given key out of BST and return the new root of BST.
*/
BSTNode* BST::remove(int key) {
    // YOUR CODE HERE
}
