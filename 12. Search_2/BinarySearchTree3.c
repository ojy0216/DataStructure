#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode** pRoot){
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst){
    return GetData(bst);
}

BTreeNode* BSTInsert(BTreeNode** pRoot, BSTData data){
    if(*pRoot == NULL){
        *pRoot = MakeBTreeNode();
        SetData(*pRoot, data);
    }
    else if(data < GetData(*pRoot)){
        BSTInsert(&((*pRoot)->left), data);
        *pRoot = Rebalance(pRoot);
    }
    else if(data > GetData(*pRoot)){
        BSTInsert(&((*pRoot)->right), data);
        *pRoot = Rebalance(pRoot);
    }
    else
        return NULL;

    return *pRoot;
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

    *pRoot = Rebalance(pRoot);

    return delNode;
}

void ShowIntData(int data){
    printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst){
    InorderTraverse(bst, ShowIntData);
    printf("\n");
}