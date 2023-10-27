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

class BST {
    protected:
        BSTNode *root;
    public:
        BST();
        ~BST();
        BSTNode* find(int key);
        BSTNode* popMaximum();
        BSTNode* popMinimum();
        BSTNode* insert(int key, int meta = 0);
        BSTNode* remove(int key);
};

