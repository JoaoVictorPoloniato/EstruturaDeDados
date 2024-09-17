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


void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}


void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


struct Node* reverseInBlocks(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;

   
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

   
    if (next != NULL) {
        head->next = reverseInBlocks(next, k);
    }

    
    return prev;
}

int main() {
    struct Node* head = NULL;

   
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);
    append(&head, 7);
    append(&head, 8);

    printf("Dada lista vinculada:\n");
    printList(head);

 
    head = reverseInBlocks(head, 3);
    printf("Inverta os 3 primeiros nós da referida lista vinculada:\n");
    printList(head);

   
    head = reverseInBlocks(head, 5);
    printf("Inverta os primeiros 5 nós da referida lista vinculada:\n");
    printList(head);

    return 0;
}