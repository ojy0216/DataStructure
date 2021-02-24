#include <stdio.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"

int main(){
    BTreeNode* avlRoot;
    BTreeNode* currentLeftNode;
    BTreeNode* currentRightNode;

    BTreeNode* currentLeftNode2;
    BTreeNode* currentRightNode2;

    BTreeNode* currentLeftNode3;
    BTreeNode* currentRightNode3;


    BSTMakeAndInit(&avlRoot);

    for(int i = 0; i < 9; i++)
        BSTInsert(&avlRoot, i + 1);

    printf("Root node: %d\n", GetData(avlRoot));

    currentLeftNode = GetLeftSubTree(avlRoot);
    currentRightNode = GetRightSubTree(avlRoot);
    printf("L1: %d, R1: %d\n", GetData(currentLeftNode), GetData(currentRightNode));

    currentLeftNode2 = GetLeftSubTree(currentLeftNode);
    currentRightNode2 = GetRightSubTree(currentLeftNode);
    printf("L2: %d, R2: %d\n", GetData(currentLeftNode2), GetData(currentRightNode2));

    currentLeftNode2 = GetLeftSubTree(currentRightNode);
    currentRightNode2 = GetRightSubTree(currentRightNode);
    printf("L3: %d, R3: %d\n", GetData(currentLeftNode2), GetData(currentRightNode2));

    currentLeftNode3 = GetLeftSubTree(currentRightNode2);
    currentRightNode3 = GetRightSubTree(currentRightNode2);
    printf("L4: %d, R4: %d\n", GetData(currentLeftNode3), GetData(currentRightNode3));

    return 0;
}