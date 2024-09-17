#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void appendNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


Node* swapPairs(Node* head) {
   
    Node dummy;
    dummy.next = head;
    Node* prev = &dummy;

    while (head != NULL && head->next != NULL) {
        Node* first = head;
        Node* second = head->next;

     
        prev->next = second;
        first->next = second->next;
        second->next = first;

        
        prev = first;
        head = first->next;
    }

    return dummy.next;
}


int main() {
   
    Node* head = NULL;

  
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

  
    printf("Lista Original: ");
    printList(head);

    
    head = swapPairs(head);

    
    printf("Lista atualizada após trocar a cada dois nós adjacentes: ");
    printList(head);

    return 0;
}
