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


Node* reverseKAlternating(Node* head, int k) {
    if (head == NULL || k <= 0) return head;

    Node dummy;
    dummy.next = head;
    Node* prevGroupEnd = &dummy;
    Node* groupStart = head;
    Node* current = head;
    int count;

    while (current != NULL) {
        Node* groupEnd = current;
        count = 0;

     
        while (current != NULL && count < k) {
            current = current->next;
            count++;
        }

     
        if (count < k) {
            prevGroupEnd->next = groupStart;
            return dummy.next;
        }

       
        Node* prev = NULL;
        Node* next;
        Node* groupEndNext = current;

        while (count > 0) {
            next = groupStart->next;
            groupStart->next = prev;
            prev = groupStart;
            groupStart = next;
            count--;
        }

        prevGroupEnd->next = prev;
        prevGroupEnd = groupEnd;


        count = 0;
        while (count < k && groupStart != NULL) {
            groupStart = groupStart->next;
            count++;
        }

        prevGroupEnd->next = groupStart;
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
    appendNode(&head, 6);
    appendNode(&head, 7);
    appendNode(&head, 8);

    printf("Lista Original: ");
    printList(head);

    
    int k = 2;
    Node* result = reverseKAlternating(head, k);
    printf("Nós alternativos reversos k (k = %d): ", k);
    printList(result);

   
    head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    appendNode(&head, 6);
    appendNode(&head, 7);
    appendNode(&head, 8);

   
    k = 3;
    result = reverseKAlternating(head, k);
    printf("Nós alternativos reversos k (k = %d): ", k);
    printList(result);

 
    head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    appendNode(&head, 6);
    appendNode(&head, 7);
    appendNode(&head, 8);

  
    k = 4;
    result = reverseKAlternating(head, k);
    printf("Nós alternativos reversos k (k = %d): ", k);
    printList(result);

    return 0;
}
