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


int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}


Node* findIntersection(Node* head1, Node* head2) {
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    
    while (length1 > length2) {
        head1 = head1->next;
        length1--;
    }
    while (length2 > length1) {
        head2 = head2->next;
        length2--;
    }

 
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}


int main() {
   
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* intersectNode = NULL;

    
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    intersectNode = createNode(7); 
    appendNode(&list1, 7);

 
    appendNode(&list2, 3);
    appendNode(&list2, 4);
    appendNode(&list2, 5);
  
    Node* temp = list2;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = intersectNode;

    
    Node* intersection = findIntersection(list1, list2);
    if (intersection != NULL) {
        printf("Interseção encontrada no nó com dados: %d\n", intersection->data);
    } else {
        printf("Nenhum cruzamento encontrado.\n");
    }

   
    list1 = NULL;
    list2 = NULL;

   
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    appendNode(&list1, 5);

    appendNode(&list2, 3);
    appendNode(&list2, 4);
    appendNode(&list2, 5);
    appendNode(&list2, 7);

    
    intersection = findIntersection(list1, list2);
    if (intersection != NULL) {
        printf("Interseção encontrada no nó com dados: %d\n", intersection->data);
    } else {
        printf("Nenhum cruzamento encontrado.\n");
    }

    return 0;
}
