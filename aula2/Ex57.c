
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

void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        newNode->next = *headRef;
    } else {
        Node* temp = *headRef;
        while (temp->next != *headRef)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *headRef;
    }
}

void insertAtPosition(Node** headRef, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 1) {
        Node* temp = *headRef;
        while (temp->next != *headRef)
            temp = temp->next;
        newNode->next = *headRef;
        temp->next = newNode;
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        for (int i = 1; i < position - 1 && temp->next != *headRef; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    int index = 1;
    do {
        printf("Dado %d = %d\n", index++, temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Node* head = NULL;
    int numNodes, data, position;

    printf("Insira o número de nós: ");
    scanf("%d", &numNodes);

    for (int i = 1; i <= numNodes; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Os dados inseridos na lista são:\n");
    displayList(head);

    printf("Insira a posição para inserir um novo nó: ");
    scanf("%d", &position);
    printf("Dados de entrada para a posição %d: ", position);
    scanf("%d", &data);

    insertAtPosition(&head, data, position);

    printf("Após a inserção a nova lista é:\n");
    displayList(head);

    return 0;
}
