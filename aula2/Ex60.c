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

void deleteLast(Node** headRef) {
    if (*headRef == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* temp = *headRef;
    Node* prev = NULL;

    // Caso a lista tenha apenas um nó
    if (temp->next == *headRef) {
        printf("O nó excluído é: %d\n", temp->data);
        free(temp);
        *headRef = NULL;
        return;
    }

    // Traverse até o último nó
    while (temp->next != *headRef) {
        prev = temp;
        temp = temp->next;
    }

    // Atualizar o nó anterior ao último nó
    prev->next = *headRef;
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

    deleteLast(&head);

    printf("Após a exclusão, a nova lista é:\n");
    displayList(head);

    return 0;
}
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

int searchElement(Node* head, int key) {
    if (head == NULL) return -1;
    Node* temp = head;
    int index = 1;
    do {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    } while (temp != head);
    return -1;
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
    int numNodes, data, searchKey, result;

    printf("Insira o número de nós: ");
    scanf("%d", &numNodes);

    for (int i = 1; i <= numNodes; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Os dados inseridos na lista são:\n");
    displayList(head);

    printf("Insira o elemento que deseja encontrar: ");
    scanf("%d", &searchKey);

    result = searchElement(head, searchKey);

    if (result != -1) {
        printf("Elemento encontrado no nó %d\n", result);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }

    return 0;
}
