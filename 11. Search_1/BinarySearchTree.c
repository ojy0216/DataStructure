#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode** pRoot){
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst){
    return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data){
    BTreeNode* parentNode = NULL;
    BTreeNode* childNode = *pRoot;
    BTreeNode* newNode = NULL;

    while(childNode != NULL){
        if(data == GetData(childNode))
            return;
        
        parentNode = childNode;

        if(GetData(childNode) > data)
            childNode = GetLeftSubTree(childNode);
        else
            childNode = GetRightSubTree(childNode);
    }

    newNode = MakeBTreeNode();
    SetData(newNode, data);

    if(parentNode != NULL){
        if(data < GetData(parentNode))
            MakeLeftSubTree(parentNode, newNode);
        else
            MakeRightSubTree(parentNode, newNode);
    }
    else
        *pRoot = newNode;
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target){
    BTreeNode* currentNode = bst;
    BSTData currentData;

    while(currentNode != NULL){
        currentData = GetData(currentNode);

        if(target == currentData)
            return currentNode;
        else if(target < currentData)
            currentNode = GetLeftSubTree(currentNode);
        else
            currentNode = GetRightSubTree(currentNode);
    }

    return NULL;
}