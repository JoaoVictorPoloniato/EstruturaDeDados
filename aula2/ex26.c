#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista vinculada
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

// Função para inserir um nó no final da lista
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Função para imprimir a lista vinculada
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Função para remover elementos com índices pares
void removeEvenIndices(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }

    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    int index = 0;

    // Se o primeiro elemento (índice 0) deve ser removido, atualizar o head
    if (index == 0) {
        *head_ref = current->next;
        free(current);
        current = *head_ref;
        index++;
    }

    // Remover elementos com índices pares
    while (current != NULL && current->next != NULL) {
        // Avançar para o próximo nó e removê-lo
        prev = current;
        current = current->next;
        prev->next = current->next;
        free(current);
        current = prev->next;
        index += 2;  // Incrementa em 2 porque pulamos o próximo nó também
    }
}

// Função principal
int main() {
    struct Node* head = NULL;

    // Criar a lista: 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
    append(&head, 7);
    append(&head, 6);
    append(&head, 5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 2);
    append(&head, 1);

    // Imprimir a lista original
    printf("Lista vinculada original: ");
    printList(head);

    // Remover elementos com índices pares
    removeEvenIndices(&head);

    // Imprimir a lista após a remoção
    printf("Lista vinculada após remoção de índices pares: ");
    printList(head);

    return 0;
}
