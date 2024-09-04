#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista vinculada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para criar uma lista vinculada com dados fornecidos pelo usuário
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *prev = NULL;
    int data;

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        temp = createNode(data);

        if (head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    return head;
}

// Função para exibir os dados da lista vinculada
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para particionar a lista em torno de um valor específico
struct Node* partitionList(struct Node* head, int x) {
    struct Node *lessHead = NULL, *lessTail = NULL;
    struct Node *greaterHead = NULL, *greaterTail = NULL;

    while (head != NULL) {
        struct Node* nextNode = head->next; // Armazena o próximo nó
        if (head->data < x) {
            if (lessHead == NULL) {
                lessHead = head;
                lessTail = lessHead;
            } else {
                lessTail->next = head;
                lessTail = head;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = head;
                greaterTail = greaterHead;
            } else {
                greaterTail->next = head;
                greaterTail = head;
            }
        }
        head->next = NULL; // Desconecta o nó da lista original
        head = nextNode;
    }

    if (lessTail != NULL) {
        lessTail->next = greaterHead;
    }

    return lessHead ? lessHead : greaterHead;
}

int main() {
    int n, partitionValue;
    struct Node* head = NULL;

    printf("Insira o número de nós na lista: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Lista original:\n");
    displayList(head);

    printf("Insira o valor para partição: ");
    scanf("%d", &partitionValue);

    head = partitionList(head, partitionValue);

    printf("Lista vinculada após partição em torno de %d:\n", partitionValue);
    displayList(head);

    // Liberação da memória alocada
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
