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

void deleteAtPosition(Node** headRef, int position) {
    if (*headRef == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* temp = *headRef;
    Node* prev = NULL;

    if (position == 1) {
        // Find the last node
        Node* last = *headRef;
        while (last->next != *headRef) {
            last = last->next;
        }
        // Update the head to the next node
        *headRef = (*headRef)->next;
        last->next = *headRef;

        printf("O nó excluído é: %d\n", temp->data);
        free(temp);
        return;
    }

    // Traverse to the node before the one to be deleted
    for (int i = 1; i < position && temp->next != *headRef; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *headRef || temp->next == *headRef) {
        printf("Posição inválida.\n");
        return;
    }

    prev->next = temp->next;
    printf("O nó excluído é: %d\n", temp->data);
    free(temp);
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

    printf("Insira a posição para excluir o nó: ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("Após a exclusão, a nova lista é:\n");
    displayList(head);

    return 0;
}
