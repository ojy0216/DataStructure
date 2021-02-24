#include <stdio.h>
#include "BinarySearchTree.h"

int main(){
    BTreeNode* bstRoot;
    BTreeNode* searchNode;

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    searchNode = BSTSearch(bstRoot, 1);
    if(searchNode == NULL)
        printf("Search failed\n");
    else
        printf("%d\n", BSTGetNodeData(searchNode));

    searchNode = BSTSearch(bstRoot, 4);
    if(searchNode == NULL)
        printf("Search failed\n");
    else
        printf("%d\n", BSTGetNodeData(searchNode));
    
    searchNode = BSTSearch(bstRoot, 6);
    if(searchNode == NULL)
        printf("Search failed\n");
    else
        printf("%d\n", BSTGetNodeData(searchNode));

    searchNode = BSTSearch(bstRoot, 7);
    if(searchNode == NULL)
        printf("Search failed\n");
    else
        printf("%d\n", BSTGetNodeData(searchNode));

    return 0;
}