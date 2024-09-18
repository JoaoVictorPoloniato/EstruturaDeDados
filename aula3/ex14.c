#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];        // Array para armazenar a pilha
int top = -1;          // Topo da pilha
int sum = 0;           // Soma dos elementos da pilha
int count = 0;         // Contador de elementos da pilha

// Função para empurrar (push) um valor na pilha
void push(int value) {
    if (top == MAX - 1) {
        printf("A pilha está cheia!\n");
    } else {
        stack[++top] = value;
        sum += value;
        count++;
    }
}

// Função para remover (pop) um valor da pilha
int pop() {
    if (top == -1) {
        printf("A pilha está vazia!\n");
        return -1;
    } else {
        int value = stack[top--];
        sum -= value;
        count--;
        return value;
    }
}

// Função para calcular a média dos elementos da pilha
float getAverage() {
    if (count == 0) {
        printf("A pilha está vazia!\n");
        return 0.0;
    } else {
        return (float)sum / count;
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
    push(6);
    push(4);
    push(2);
    push(5);
    push(3);
    push(1);

    // Exibir elementos da pilha e a média
    printf("Elementos da pilha:\n");
    printStack();
    printf("Média dos referidos valores da pilha: %.2f\n", getAverage());

    // Remover um elemento da pilha
    int removedValue = pop();
    printf("Valor estourado: %d\n", removedValue);

    // Exibir elementos da pilha e a média após a remoção
    printf("Elementos da pilha:\n");
    printStack();
    printf("Média dos referidos valores da pilha: %.2f\n", getAverage());

    return 0;
}
