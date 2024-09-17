#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void reverseInPairs(struct Node** head) {
    struct Node* current = *head;

    
    while (current != NULL && current->next != NULL) {
        
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        
        current = current->next->next;
    }
}

int main() {
    struct Node* head = NULL;

  
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);

    printf("Lista Original:\n");
    printList(head);

    reverseInPairs(&head);

    printf("Lista invertida em pares:\n");
    printList(head);


    struct Node* head2 = NULL;
    insertNode(&head2, 1);
    insertNode(&head2, 2);
    insertNode(&head2, 3);
    insertNode(&head2, 4);
    insertNode(&head2, 5);

    printf("Lista Original (ímpar):\n");
    printList(head2);

    reverseInPairs(&head2);

    printf("Lista invertida em pares (ímpar):\n");
    printList(head2);

    return 0;
}
