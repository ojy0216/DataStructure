#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node* next;
} Node;

int main(){
    Node* tail = NULL;
    Node* head = NULL;
    Node* cur = NULL;

    Node* newNode = NULL;
    int readData;

    while(1){
        printf("Enter n: ");
        scanf("%d", &readData);
        if(readData < 1)
            break;

        newNode = malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else 
            tail->next = newNode;

        tail = newNode;
    }

    printf("\nPrinting data\n\n");
    if(head == NULL)
        printf("No data\n");
    else{
        cur = head;
        printf("%d ", cur->data);

        while(cur->next != NULL){
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n");

    if(head == NULL)
        return 0;
    else{
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
    }

    return 0;
}