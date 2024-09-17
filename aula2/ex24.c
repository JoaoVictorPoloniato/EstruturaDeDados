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

// Função para contar o número de nós na lista
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Função para girar a lista vinculada para a direita em k casas
void rotateRight(struct Node** head_ref, int k) {
    if (*head_ref == NULL || k == 0) {
        return;
    }

    struct Node* current = *head_ref;

    // Contar o número de nós na lista
    int count = countNodes(current);

    // k pode ser maior que o número de nós, então ajustamos k
    k = k % count;
    if (k == 0) {
        return;
    }

    // Encontrar o último nó e conectar com o primeiro, tornando a lista circular
    struct Node* last = current;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = *head_ref; // Torna a lista circular

    // Mover o ponteiro current para o novo ponto de rotação
    int stepsToNewHead = count - k;
    for (int i = 0; i < stepsToNewHead - 1; i++) {
        current = current->next;
    }

    // A nova cabeça é o próximo nó, e quebramos a lista circular
    *head_ref = current->next;
    current->next = NULL;
}

// Função principal
int main() {
    struct Node* head = NULL;

    // Criar a lista: 1 -> 3 -> 4 -> 7 -> 9
    append(&head, 1);
    append(&head, 3);
    append(&head, 4);
    append(&head, 7);
    append(&head, 9);

    // Imprimir lista original
    printf("Lista Original: ");
    printList(head);

    // Rotacionar a lista em 1 posição para a direita
    rotateRight(&head, 1);
    printf("Gire a lista para a direita em 1 casa: ");
    printList(head);

    // Rotacionar a lista em 2 posições para a direita
    rotateRight(&head, 2);
    printf("Gire a lista para a direita em 2 lugares: ");
    printList(head);

    // Rotacionar a lista em 4 posições para a direita
    rotateRight(&head, 4);
    printf("Gire a lista para a direita em 4 lugares: ");
    printList(head);

    return 0;
}
