#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, int data) {
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

int* convertToArray(Node* head, int* size) {
    if (head == NULL) {
        *size = 0;
        return NULL;
    }
    
    Node* temp = head;
    int count = 0;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    *size = count;
    int* array = (int*)malloc(count * sizeof(int));
    
    temp = head;
    for (int i = 0; i < count; i++) {
        array[i] = temp->data;
        temp = temp->next;
    }
    
    return array;
}

void displayArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

    printf("Lista duplamente vinculada:\n");
    displayList(head);

    int size;
    int* array = convertToArray(head, &size);

    printf("Lista duplamente vinculada em formato de array:\n");
    displayArray(array, size);

    free(array);
    return 0;
}
