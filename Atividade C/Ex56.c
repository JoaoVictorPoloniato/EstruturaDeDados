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
    int numNodes, data;

    printf("Insira o número de nós: ");
    scanf("%d", &numNodes);

    for (int i = 1; i <= numNodes; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Os dados inseridos na lista são:\n");
    displayList(head);

    printf("Insira os dados a serem inseridos: ");
    scanf("%d", &data);
    append(&head, data);

    printf("Após a inserção a nova lista é:\n");
    displayList(head);

    return 0;
}
