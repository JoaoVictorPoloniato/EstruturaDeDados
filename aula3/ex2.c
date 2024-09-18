#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct Node {
    int data;
    struct Node* next;
};

// Função para verificar se a pilha está vazia
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Função para inserir um elemento na pilha (push)
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Enviar dados %d\n", value);
}

// Função para remover um elemento da pilha (pop)
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Pilha está vazia!\n");
        return -1;
    } else {
        struct Node* temp = *top;
        *top = (*top)->next;
        int popped = temp->data;
        free(temp);
        return popped;
    }
}

// Função para verificar se a pilha está vazia e exibir uma mensagem
void checkEmpty(struct Node* top) {
    if (isEmpty(top)) {
        printf("A pilha está vazia!\n");
    } else {
        printf("A pilha não está vazia!\n");
    }
}

int main() {
    struct Node* top = NULL;

    // Inserindo elementos na pilha
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);

    // Removendo elementos da pilha
    printf("Data pop: %d\n", pop(&top));
    printf("Data pop: %d\n", pop(&top));
    printf("Data pop: %d\n", pop(&top));
    printf("Data pop: %d\n", pop(&top));

    // Verificando se a pilha está vazia
    checkEmpty(top);

    return 0;
}
