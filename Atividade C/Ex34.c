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


struct Node* mergeAlternate(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* tail = NULL;

    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL) {
            if (mergedList == NULL) {
                mergedList = list1;
                tail = list1;
            } else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
        
        if (list2 != NULL) {
            if (mergedList == NULL) {
                mergedList = list2;
                tail = list2;
            } else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }
    return mergedList;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

   
    append(&list1, 9);
    append(&list1, 7);
    append(&list1, 5);
    append(&list1, 3);
    append(&list1, 1);

   
    append(&list2, 10);
    append(&list2, 8);
    append(&list2, 6);
    append(&list2, 4);
    append(&list2, 2);

    printf("Primeira lista vinculada: ");
    printList(list1);

    printf("Segunda lista vinculada: ");
    printList(list2);

    
    struct Node* mergedList = mergeAlternate(list1, list2);

    printf("Lista vinculada mesclada: ");
    printList(mergedList);

    return 0;
}
