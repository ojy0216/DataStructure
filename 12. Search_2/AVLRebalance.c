#include <stdio.h>
#include "AVLRebalance.h"

BTreeNode* RotateLL(BTreeNode* bst){
    BTreeNode* parentNode;
    BTreeNode* childNode;

    parentNode = bst;
    childNode = GetLeftSubTree(parentNode);

    ChangeLeftSubTree(parentNode, GetRightSubTree(childNode));
    ChangeRightSubTree(childNode, parentNode);

    return childNode;
}

BTreeNode* RotateRR(BTreeNode* bst){
    BTreeNode* parentNode;
    BTreeNode* childNode;

    parentNode = bst;
    childNode = GetRightSubTree(parentNode);

    ChangeRightSubTree(parentNode, GetLeftSubTree(childNode));
    ChangeLeftSubTree(childNode, parentNode);

    return childNode;
}

BTreeNode* RotateLR(BTreeNode* bst){
    BTreeNode* parentNode;
    BTreeNode* childNode;

    parentNode = bst;
    childNode = GetLeftSubTree(parentNode);

    ChangeLeftSubTree(parentNode, RotateRR(childNode));

    return RotateLL(parentNode);
}

BTreeNode* RotateRL(BTreeNode* bst){
    BTreeNode* parentNode;
    BTreeNode* childNode;

    parentNode = bst;
    childNode = GetRightSubTree(parentNode);

    ChangeRightSubTree(parentNode, RotateLL(childNode));

    return RotateRR(parentNode);
}

int GetHeight(BTreeNode* bst){
    int leftHeight, rightHeight;

    if(bst == NULL)
        return 0;

    leftHeight = GetHeight(GetLeftSubTree(bst));
    rightHeight = GetHeight(GetRightSubTree(bst));

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int GetHeightDiff(BTreeNode* bst){
    int lsh, rsh;

    if(bst == NULL) 
        return 0;

    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));

    return lsh - rsh;
}

BTreeNode* Rebalance(BTreeNode** pRoot){
    int hDiff = GetHeightDiff(*pRoot);

    if(hDiff > 1){
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }

    if(hDiff < -1){
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }

    return *pRoot;
}