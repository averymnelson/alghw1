#pragma once

#include <iostream>

struct BSTNode {
    int key;
    int height;
    int meta;
    BSTNode *left;
    BSTNode *right;

    BSTNode();
    BSTNode(int key, int height = 0, int meta = 0, BSTNode *left = NULL, BSTNode *right = NULL);  
    ~BSTNode();
};

//Allowed to insert duplicate values
//rule: node -> left -> key <= node -> key < right -> key
class BST {
    protected:
        BSTNode *root;
    public:
        BST();
        ~BST();
        // Helper methods
        void releaseHelper(BSTNode *node);
        BSTNode* removeHelper(int key, BSTNode* node);
        BSTNode *findHelper(int key, BSTNode *node);
        BSTNode *insertHelper(int key, int meta, BSTNode *node);
        BSTNode *popMaximumHelper(BSTNode *currNode, BSTNode *&maxNode);
        BSTNode *popMinimumHelper(BSTNode *currNode, BSTNode *&minNode);

        //clear method
        BSTNode* find(int key);
        BSTNode *popMaximum();
        BSTNode *popMinimum();
        BSTNode* insert(int key, int meta = 0);
        BSTNode* remove(int key);
        BSTNode* minChild(BSTNode* node);
};
