#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node* next;
} Node;

int main(){
    Node* tail = NULL;
    Node* head = NULL;
    Node* Dummy = NULL;
    Node* cur = NULL;

    Node* newNode = NULL;
    int readData;

    Dummy = malloc(sizeof(Node));
    Dummy->data = -1;
    Dummy->next = NULL;

    head = Dummy;
    tail = Dummy;

    while(1){
        printf("Enter n: ");
        scanf("%d", &readData);
        if(readData < 1)
            break;

        newNode = malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
    }

    printf("\nPrinting data\n\n");
    cur = head;
    while(cur->next != NULL){
        cur = cur->next;
        if(cur->data != -1)
            printf("%d ", cur->data);
    }
    printf("\n");

    Node* delNode = head;
    Node* delNextNode = head->next;

    printf("Deleting %d\n", head->data);
    free(delNode);

    while(delNextNode != NULL){
        delNode = delNextNode;
        delNextNode = delNextNode->next;

        printf("Deleting %d\n", delNode->data);
        free(delNode);
    }

    return 0;
}