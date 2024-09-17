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

// Função para remover o enésimo nó do final da lista vinculada
void removeNthFromEnd(struct Node** head_ref, int n) {
    struct Node* first = *head_ref;
    struct Node* second = *head_ref;
    struct Node* prev = NULL;
    
    // Mover o ponteiro 'first' n passos à frente
    for (int i = 0; i < n; i++) {
        if (first == NULL) {
            printf("N é maior que o tamanho da lista.\n");
            return;
        }
        first = first->next;
    }

    // Se o ponteiro 'first' for NULL, o nó a ser removido é o head
    if (first == NULL) {
        struct Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }

    // Mover os ponteiros 'first' e 'second' simultaneamente até o 'first' chegar ao final
    while (first != NULL) {
        prev = second;
        second = second->next;
        first = first->next;
    }

    // Remover o nó apontado por 'second'
    prev->next = second->next;
    free(second);
}

// Função principal
int main() {
    struct Node* head = NULL;

    // Criar a lista: 1 -> 2 -> 3 -> 4 -> 5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // Imprimir a lista original
    printf("Lista original individual: ");
    printList(head);

    // Remover o 1º nó do final
    removeNthFromEnd(&head, 1);
    printf("Remova o primeiro nó do final de uma única lista vinculada: ");
    printList(head);

    // Remover o 3º nó do final
    removeNthFromEnd(&head, 3);
    printf("Remova o terceiro nó do final de uma única lista vinculada: ");
    printList(head);

    return 0;
}
