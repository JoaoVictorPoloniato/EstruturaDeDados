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

void splitList(struct Node* head, struct Node** first_half, struct Node** second_half) {
    struct Node* slow = head;
    struct Node* fast = head;
    
    if (head == NULL || head->next == NULL) {
        *first_half = head;
        *second_half = NULL;
        return;
    }

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL && fast->next != NULL) {
            slow = slow->next;
        }
    }

    *first_half = head;
    *second_half = slow->next;
    slow->next = NULL; 
}

int main() {
    struct Node* head = NULL;
    struct Node* first_half = NULL;
    struct Node* second_half = NULL;

 
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Lista Original: ");
    printList(head);

  
    splitList(head, &first_half, &second_half);

    printf("Primeira metade: ");
    printList(first_half);

    printf("Segunda metade: ");
    printList(second_half);

    
    head = NULL;
    first_half = NULL;
    second_half = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printf("\nLista Original: ");
    printList(head);

    
    splitList(head, &first_half, &second_half);

    printf("Primeira metade: ");
    printList(first_half);

    printf("Segunda metade: ");
    printList(second_half);

    return 0;
}
