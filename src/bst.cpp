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

BST::BST() {
    this->root = NULL;
}

BST::~BST() {
    releaseHelper(root);
}

void BST::releaseHelper(BSTNode *node){
    if (node == nullptr){
        return;
    }
    releaseHelper(node->left);
    releaseHelper(node->right);
    delete node;
}

BSTNode* BST::find(int key) {
    return findHelper(key, this->root);
}

BSTNode* BST::findHelper(int key, BSTNode *node){
    if(node == nullptr){
        return nullptr;
    }else if(node->key == key){
        return node;
    }else if(key < node->key){
        return findHelper(key, node->left);
    }else{
        return findHelper(key, node->right);
    }
    return nullptr;
}

BSTNode* BST::popMaximumHelper(BSTNode* currNode, BSTNode*& maxNode){
    if(currNode == nullptr){
        return nullptr;
    }
    if(currNode->right){
        currNode->right = popMaximumHelper(currNode->right, maxNode);
    }else{
        maxNode = currNode;
        currNode = currNode->left;
    }
    return currNode;
}

BSTNode* BST::popMaximum() {
    BSTNode* max = nullptr;
    root = popMaximumHelper(root, max);
    return max;
}

BSTNode* BST::popMinimumHelper(BSTNode* currNode, BSTNode*& minNode){
    if(currNode == nullptr){
        return nullptr;
    }
    if(currNode->left){
        currNode->left = popMinimumHelper(currNode->left, minNode);
    }else{
        minNode = currNode;
        currNode = currNode->right;
    }
    return currNode;
}

BSTNode* BST::popMinimum() {
    BSTNode* min = nullptr;
    root = popMinimumHelper(root, min);
    return min;
}

BSTNode* BST::insert(int key, int meta) {
    return this->root = insertHelper(key, meta, this->root);
}

BSTNode* BST::insertHelper(int key, int meta, BSTNode *node){
    if(node == NULL){
        node = new BSTNode();
        node->key = key;
        node->meta = meta;
        return node;
    }

    if(key <= node->key){
        node->left = insertHelper(key, meta, node->left);
    }else{
        node->right = insertHelper(key, meta, node->right);
    }
    return node;
}

BSTNode* BST::remove(int key) {
    return this->root = removeHelper(key, this->root);
}

BSTNode* BST::removeHelper(int key, BSTNode* node){
    if(node == nullptr){
        return node;
    }
    if(node->key == key){
       if(node->left == nullptr && node->right ==nullptr){
        delete node;
        return nullptr;
       }else if(node->right == nullptr){
        BSTNode* temp = node->left;
        delete node;
        return temp;
       }else if(node->left == nullptr){
        BSTNode* temp = node->right;
        delete node;
        return temp;
       }else{
        BSTNode* temp = minChild(node->right);
        node->key = temp->key;
        node->right = removeHelper(temp->key, node->right);
       }
    }else if(key < node->key){
        node->left = removeHelper(key, node->left);
    }
    else{
        node->right = removeHelper(key, node->right);
    }
    return node;
}

BSTNode* BST::minChild(BSTNode* node){
    while(node->left){
        node = node->left;
    }
    return node;
}