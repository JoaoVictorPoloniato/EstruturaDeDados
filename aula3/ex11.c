#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];          // Array para armazenar a pilha principal
int minStack[MAX];       // Array para armazenar os elementos mínimos
int top = -1;            // Topo da pilha principal
int minTop = -1;         // Topo da pilha auxiliar (mínimos)

// Função para empurrar (push) um valor na pilha principal
void push(int value) {
    if (top == MAX - 1) {
        printf("A pilha está cheia!\n");
    } else {
        stack[++top] = value;

        // Atualiza a pilha auxiliar de mínimos
        if (minTop == -1 || value <= minStack[minTop]) {
            minStack[++minTop] = value;
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

        // Atualiza a pilha auxiliar de mínimos
        if (value == minStack[minTop]) {
            minTop--;
        }

        return value;
    }
}

// Função para obter o elemento mínimo da pilha
int getMin() {
    if (minTop == -1) {
        printf("A pilha está vazia!\n");
        return -1;
    } else {
        return minStack[minTop];
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
    push(9);
    push(2);
    push(4);
    push(2);
    push(4);

    // Exibir elementos atuais da pilha e o elemento mínimo
    printf("Elementos atuais da pilha:\n");
    printStack();
    printf("Elemento mínimo: %d\n", getMin());

    // Remover dois elementos
    pop();
    pop();

    // Exibir elementos atuais da pilha e o elemento mínimo
    printf("Depois de remover dois elementos:\n");
    printStack();
    printf("Elemento mínimo: %d\n", getMin());

    // Adicionar um novo elemento
    push(1);

    // Exibir elementos atuais da pilha e o elemento mínimo
    printf("Depois de adicionar um elemento:\n");
    printStack();
    printf("Elemento mínimo: %d\n", getMin());

    return 0;
}
