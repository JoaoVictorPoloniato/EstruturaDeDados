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


void findPairsWithSum(struct Node* head, int target_sum) {
    struct Node* outer = head;
    struct Node* inner = NULL;
    int found = 0;

    while (outer != NULL) {
        inner = outer->next;
        while (inner != NULL) {
            if (outer->data + inner->data == target_sum) {
                printf("(%d.%d) ", outer->data, inner->data);
                found = 1;
            }
            inner = inner->next;
        }
        outer = outer->next;
    }

    if (!found) {
        printf("Par não encontrado.");
    }
    printf("\n");
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

    printf("Lista vinculada única original:\n");
    printList(head);

    printf("Encontre um par cuja soma seja igual a 4:\n");
    findPairsWithSum(head, 4);

    printf("Encontre um par cuja soma seja igual a 11:\n");
    findPairsWithSum(head, 11);

    printf("Encontre um par cuja soma seja igual a 5:\n");
    findPairsWithSum(head, 5);

    printf("Encontre um par cuja soma seja igual a 14:\n");
    findPairsWithSum(head, 14);

    return 0;
}
