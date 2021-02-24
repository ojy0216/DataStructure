#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

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

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target){
    BTreeNode* pVirtualRoot = MakeBTreeNode();
    BTreeNode* parentNode = pVirtualRoot;
    BTreeNode* childNode = *pRoot;
    BTreeNode* delNode;

    ChangeRightSubTree(pVirtualRoot, *pRoot);

    while(childNode != NULL && GetData(childNode) != target){
        parentNode = childNode;

        if(target < GetData(childNode))
            childNode = GetLeftSubTree(childNode);
        else
            childNode = GetRightSubTree(childNode);
    } 

    if(childNode == NULL)
        return NULL;

    delNode = childNode;

    if(GetLeftSubTree(delNode) == NULL && GetRightSubTree(delNode) == NULL){
        if(GetLeftSubTree(parentNode) == delNode)
            RemoveLeftSubTree(parentNode);
        else
            RemoveRightSubTree(parentNode);
    }
    else if(GetLeftSubTree(delNode) == NULL || GetRightSubTree(delNode) == NULL){
        BTreeNode* delChildNode;

        if(GetLeftSubTree(delNode) != NULL)
            delChildNode = GetLeftSubTree(delNode);
        else
            delChildNode = GetRightSubTree(delNode);

        if(GetLeftSubTree(parentNode) == delNode)
            ChangeLeftSubTree(parentNode, delChildNode);
        else
            ChangeRightSubTree(parentNode, delChildNode);
    }
    else{
        BTreeNode* mNode = GetRightSubTree(delNode);
        BTreeNode* mParentNode = delNode;
        int delData;

        while(GetLeftSubTree(mNode) != NULL){
            mParentNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        delData = GetData(delNode);
        SetData(delNode, GetData(mNode));

        if(GetLeftSubTree(mParentNode) == mNode)
            ChangeLeftSubTree(mParentNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mParentNode, GetRightSubTree(mNode));

        delNode = mNode;
        SetData(delNode, delData);
    }

    if(GetRightSubTree(pVirtualRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVirtualRoot);
    
    free(pVirtualRoot);

    return delNode;
}

void ShowIntData(int data){
    printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst){
    InorderTraverse(bst, ShowIntData);
    printf("\n");
}