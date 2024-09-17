#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    *headRef = newNode;
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
        newNode->prev = temp;
    }
}


void displayList(Node* head) {
    Node* temp = head;
    int index = 1;
    while (temp != NULL) {
        printf("nó %d: %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }
}


int main() {
    Node* head = NULL;
    int numNodes, data;

 
    printf("Insira o número de nós: ");
    scanf("%d", &numNodes);

 
    for (int i = 1; i <= numNodes; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        appendNode(&head, data);
    }


    printf("Os dados inseridos na lista são:\n");
    displayList(head);

    printf("Dados de entrada para o primeiro nó: ");
    scanf("%d", &data);
    insertAtBeginning(&head, data);

  
    printf("Após a inserção a nova lista é:\n");
    displayList(head);

   
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
