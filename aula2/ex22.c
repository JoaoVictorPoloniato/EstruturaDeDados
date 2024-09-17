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

// Função para inserir um nó no início da lista
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Função para imprimir a lista vinculada
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Função para somar duas listas vinculadas
struct Node* addTwoLists(struct Node* first, struct Node* second) {
    struct Node* result = NULL;  // Lista vinculada resultante
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;

    // Percorrer ambas as listas
    while (first != NULL || second != NULL) {
        // Somar os dígitos atuais das duas listas e o carry
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

        // Atualizar o carry para a próxima soma
        carry = (sum >= 10) ? 1 : 0;

        // Atualizar a soma se for maior que 10
        sum = sum % 10;

        // Criar um novo nó com o valor da soma e adicioná-lo ao resultado
        temp = createNode(sum);

        // Se for o primeiro nó, definir como o head da lista resultante
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }

        // Atualizar o nó anterior
        prev = temp;

        // Avançar os ponteiros das duas listas
        if (first) {
            first = first->next;
        }
        if (second) {
            second = second->next;
        }
    }

    // Se ainda houver carry, adicionar um nó extra
    if (carry > 0) {
        temp->next = createNode(carry);
    }

    return result;
}

// Função principal
int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* result = NULL;

    // Lista 1: 8 -> 7 -> 9 -> 2 (representando o número 8792)
    push(&first, 2);
    push(&first, 9);
    push(&first, 7);
    push(&first, 8);

    // Lista 2: 2 -> 1 -> 2 -> 3 (representando o número 2123)
    push(&second, 3);
    push(&second, 2);
    push(&second, 1);
    push(&second, 2);

    // Imprimir as listas
    printf("Lista-1: ");
    printList(first);
    printf("Lista-2: ");
    printList(second);

    // Somar as duas listas
    result = addTwoLists(first, second);

    // Imprimir o resultado
    printf("Adicionando as duas listas: ");
    printList(result);

    return 0;
}
