#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];        // Array para armazenar a pilha principal
int top = -1;          // Topo da pilha principal
int middleStack[MAX]; // Array auxiliar para armazenar o elemento do meio
int midTop = -1;       // Topo da pilha auxiliar

// Função para empurrar (push) um valor na pilha
void push(int value) {
    if (top == MAX - 1) {
        printf("A pilha está cheia!\n");
    } else {
        stack[++top] = value;

        // Atualiza a pilha auxiliar de elementos do meio
        if (top % 2 == 0) {
            middleStack[++midTop] = value;
        }
    }
}

// Função para remover (pop) um valor da pilha
int pop() {
    if (top == -1) {
        printf("A pilha está vazia!\n");
        return -1;
    } else {
        int value = stack[top--];

        // Atualiza a pilha auxiliar de elementos do meio
        if (top % 2 == 0) {
            midTop--;
        }

        return value;
    }
}

// Função para obter o elemento intermediário da pilha
int getMiddle() {
    if (midTop == -1) {
        printf("A pilha está vazia!\n");
        return -1;
    } else {
        return middleStack[midTop];
    }
}

// Função para excluir o elemento intermediário da pilha
void deleteMiddle() {
    if (midTop == -1) {
        printf("A pilha está vazia!\n");
        return;
    }

    int middleIndex = (top + 1) / 2;
    int tempStack[MAX];
    int tempTop = -1;

    // Transferir os elementos acima do meio para uma pilha temporária
    while (top != middleIndex - 1) {
        tempStack[++tempTop] = pop();
    }

    // Remover o elemento do meio
    pop();

    // Restaurar os elementos da pilha temporária
    while (tempTop != -1) {
        push(tempStack[tempTop--]);
    }
}

// Função para exibir os elementos da pilha
void printStack() {
    if (top == -1) {
        printf("A pilha está vazia!\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Adicionando elementos na pilha
    push(88);
    push(15);
    push(26);
    push(32);
    push(23);

    // Exibir elementos da pilha e o elemento intermediário
    printf("Elementos de pilha: ");
    printStack();
    printf("Elemento intermediário: %d\n", getMiddle());

    // Excluir o elemento do meio da pilha
    deleteMiddle();

    // Exibir elementos da pilha e o elemento intermediário
    printf("Elementos de pilha: ");
    printStack();
    printf("Elemento intermediário: %d\n", getMiddle());

    // Excluir o elemento do meio da pilha
    deleteMiddle();

    // Exibir elementos da pilha e o elemento intermediário
    printf("Elementos de pilha: ");
    printStack();
    printf("Elemento intermediário: %d\n", getMiddle());

    return 0;
}
