#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];        // Array para armazenar a pilha principal
int minStack[MAX];     // Array para armazenar os valores mínimos
int top = -1;          // Topo da pilha principal
int minTop = -1;       // Topo da pilha auxiliar de mínimos

// Função para empurrar (push) um valor na pilha
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

// Função para remover (pop) um valor da pilha
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

// Função para remover o valor mínimo da pilha
void removeMin() {
    if (top == -1) {
        printf("A pilha está vazia!\n");
        return;
    }

    int minValue = getMin();
    int tempStack[MAX];
    int tempTop = -1;

    // Transferir os elementos acima do mínimo para uma pilha temporária
    while (top != -1 && stack[top] != minValue) {
        tempStack[++tempTop] = pop();
    }

    // Remover o elemento mínimo
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
    push(7);
    push(4);
    push(5);
    push(2);
    push(3);
    push(1);

    // Exibir elementos da pilha e o valor mínimo
    printf("Elementos da pilha:\n");
    printStack();
    printf("Valor mínimo da referida pilha: %d\n", getMin());

    // Remover o valor mínimo
    removeMin();

    // Exibir elementos da pilha e o valor mínimo após remoção
    printf("Elementos da pilha após a remoção do referido valor mínimo:\n");
    printStack();
    printf("Valor mínimo da referida pilha: %d\n", getMin());

    // Remover o valor mínimo
    removeMin();

    // Exibir elementos da pilha e o valor mínimo após remoção
    printf("Elementos da pilha após a remoção do referido valor mínimo:\n");
    printStack();
    printf("Valor mínimo da referida pilha: %d\n", getMin());

    // Remover o valor mínimo
    removeMin();

    // Exibir elementos da pilha após remoção
    printf("Elementos da pilha após a remoção do referido valor mínimo:\n");
    printStack();

    return 0;
}
