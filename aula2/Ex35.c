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


void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode = NULL;

   
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            nextNode = current->next->next;
            free(current->next); 
            current->next = nextNode; 
        } else {
            current = current->next; 
        }
    }
}

int main() {
    struct Node* head = NULL;

   
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 3);
    append(&head, 5);
    append(&head, 6);
    append(&head, 6);

    printf("Lista vinculada única classificada original:\n");
    printList(head);

    
    removeDuplicates(head);

    printf("Depois de remover duplicatas da referida lista vinculada classificada:\n");
    printList(head);

    return 0;
}
