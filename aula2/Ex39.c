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


Node* intercalateLists(Node* list1, Node* list2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        tail->next = list1;
        list1 = list1->next;
        tail = tail->next;
        tail->next = list2;
        list2 = list2->next;
        tail = tail->next;
    }

    
    if (list1 != NULL) {
        tail->next = list1;
    }

    
    if (list2 != NULL) {
        tail->next = list2;
    }

    return dummy.next;
}


int main() {
   
    Node* list1 = NULL;
    Node* list2 = NULL;

   
    appendNode(&list1, 1);
    appendNode(&list1, 3);
    appendNode(&list1, 5);
    appendNode(&list1, 7);

    
    appendNode(&list2, 2);
    appendNode(&list2, 4);
    appendNode(&list2, 6);
    appendNode(&list2, 8);

    
    Node* intercalatedList = intercalateLists(list1, list2);

    
    printf("Lista intercalada: ");
    printList(intercalatedList);

    return 0;
}
