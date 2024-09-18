#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];          // Array para armazenar a pilha principal
int maxStack[MAX];       // Array para armazenar os elementos máximos
int top = -1;            // Topo da pilha principal
int maxTop = -1;         // Topo da pilha auxiliar (máximos)

// Função para empurrar (push) um valor na pilha principal
void push(int value) {
    if (top == MAX - 1) {
        printf("A pilha está cheia!\n");
    } else {
        stack[++top] = value;

        // Atualiza a pilha auxiliar de máximos
        if (maxTop == -1 || value >= maxStack[maxTop]) {
            maxStack[++maxTop] = value;
        }
    }
}

// Função para remover (pop) um valor da pilha principal
int pop() {
    if (top == -1) {
        printf("A pilha está vazia!\n");
        return -1;
    } else {
        int value = stack[top--];

        // Atualiza a pilha auxiliar de máximos
        if (value == maxStack[maxTop]) {
            maxTop--;
        }

        return value;
    }
}

// Função para obter o elemento máximo da pilha
int getMax() {
    if (maxTop == -1) {
        printf("A pilha está vazia!\n");
        return -1;
    } else {
        return maxStack[maxTop];
    }
}

// Função para exibir os elementos da pilha principal
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
    push(5);
    push(2);
    push(1);
    push(6);
    push(8);

    // Exibir elementos atuais da pilha e o elemento máximo
    printf("Elementos atuais da pilha:\n");
    printStack();
    printf("Elementos máximos: %d\n", getMax());

    // Remover dois elementos
    pop();
    pop();

    // Exibir elementos atuais da pilha e o elemento máximo
    printf("Depois de remover dois elementos:\n");
    printStack();
    printf("Elementos máximos: %d\n", getMax());

    // Adicionar um novo elemento
    push(10);

    // Exibir elementos atuais da pilha e o elemento máximo
    printf("Depois de adicionar um elemento:\n");
    printStack();
    printf("Elementos máximos: %d\n", getMax());

    return 0;
}
