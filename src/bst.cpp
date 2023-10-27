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
    this->root = NULL;
}

/*
    The deconstructor of BST will deallocate memory of all nodes in the BST.
    You have to implement the deconstructor to release memory of all nodes.
*/
BST::~BST() {
    releaseHelper(root);
}

void BST::releaseHelper(BSTNode *node){
    //null pointer
    if (node == nullptr)
    {
        return;
    }
    //clear left
    releaseHelper(node->left);
    //clear right
    releaseHelper(node->right);
    //release memory of node
    delete node;
}

/*
    The find method will find the node that contains the key. 
    You have to implement the find method to return the node containing the given key.
*/
BSTNode* BST::find(int key) {
    return findHelper(key, this->root);
}

BSTNode* BST::findHelper(int key, BSTNode *node){
    //if null pointer
    if(node == nullptr){
        return nullptr;
    }
    //if node contains key
    else if(node->key == key){
        return node;
    }
    //if key is less than
    else if(key < node->key){
        return findHelper(key, node->left);
    }
    //if key if greater than
    else{
        return findHelper(key, node->right);
    }
    return nullptr;
}
/*
    The pop maximum method will return the node that contains the maximum value 
    and remove that node out BST but DO NOT release the memory of this maximum node. 
    You have to implement the pop maximum method to return the node containing the maximum value and remove it out of the BST.
*/

BSTNode* BST::popMaximumHelper(BSTNode* currNode, BSTNode*& maxNode){
    if(currNode == nullptr){
        return nullptr;
    }

    if(currNode->right){
        currNode->right = popMaximumHelper(currNode->right, maxNode);
    }

    else{
        maxNode = currNode;
        currNode = currNode->left;
    }
    return currNode;
}

BSTNode* BST::popMaximum() {
    //std::cout<<"call to pop max";
    BSTNode* max = nullptr;
    root = popMaximumHelper(root, max);
    return max;
}
    // q = root->right;
    // p = q->right;
    // //if p is root
    // if(p == this->root){
    //     std::cout<<"p is root";
    //     this->root = p->right;
    // }
    // else{
    //     q->right = p->right;
    //     p = q->right;
    // }
    // //end if
    // p->left = p->right = nullptr;
    // //return node with max value
    // return p;
//}

/* 
    The pop minimum method will return the node that contains the minimum value 
    and remove that node out BST but DO NOT release the memory of this minimum node. 
    You have to implement the pop minium method to return the node containing the minum value and remove it out of the BST.
*/
BSTNode* BST::popMinimumHelper(BSTNode* currNode, BSTNode*& minNode){
    if(currNode == nullptr){
        return nullptr;
    }

    if(currNode->left){
        currNode->left = popMinimumHelper(currNode->left, minNode);
    }

    else{
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
    // q = this->root->left;
    // q->left = p;
    // //if p is the root
    // if(p == this->root){
    //     root = p->right;
    // }
    // else{
    //     q->left = p->right;
    // }
    // p->left = p->right = nullptr;
    // //return node with min value
    // return p;
//}

/*
    The insert method will insert a new node containing the key and meta data. 
    You have to implement the insert method to insert a new node with a given key and meta data into BST and return the new root of BST. 
*/
BSTNode* BST::insert(int key, int meta) {
    return this->root = insertHelper(key, meta, this->root);
}

BSTNode* BST::insertHelper(int key, int meta, BSTNode *node){
    //if node is null
    if(node == NULL){
        //Allocate a new node with data
        node = new BSTNode();
        node->key = key;
        node->meta = meta;
        return node;
    }
    //if key is LESS or EQUAL than node key
    if(key <= node->key){
        //Go to left
        node->left = insertHelper(key, meta, node->left);
    }

    //if key is GREATER than node key
    else{
        //Go to right
        node->right = insertHelper(key, meta, node->right);
    }
    //return the node
    return node;
}

/*
    The remove method will remove a new node containing the key and meta data. 
    You have to implement the remove method to remove a node containing the given key out of BST and return the new root of BST.
*/
BSTNode* BST::remove(int key) {
    return this->root = removeHelper(key, this->root);
}

BSTNode* BST::removeHelper(int key, BSTNode* node){
    if(node == nullptr){
        return node;
    }
    //If node contains the given key, then perform the deletion
    if(node->key == key){
       if(node->left == nullptr && node->right ==nullptr){
        delete node;
        return nullptr;
       }
       //if the node has only left child
        else if(node->right == nullptr){
        BSTNode* temp = node->left;
        delete node;
        return temp;
       }
       //if the node has only right child
       else if(node->left == nullptr){
        BSTNode* temp = node->right;
        delete node;
        return temp;
       }
       //Has both children, must find the max between children nodes to replace removed node
       else{
        BSTNode* temp = minChild(node->right);
        node->key = temp->key;
        node->right = removeHelper(temp->key, node->right);
       }
    }
    else if(key < node->key){
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
