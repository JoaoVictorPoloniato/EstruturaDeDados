#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX]; // Array para armazenar a pilha
int top = -1;   // Topo da pilha

// Função para empurrar (push) um valor na pilha
void push(int value) {
    if (top == MAX - 1) {
        printf("A pilha está cheia!\n");
    } else {
        stack[++top] = value;
    }
}

// Função para remover (pop) um valor da pilha
int pop() {
    if (top == -1) {
        printf("A pilha está vazia!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Função para obter o topo da pilha
int getTop() {
    if (top == -1) {
        printf("A pilha está vazia!\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Função para obter o k-ésimo elemento a partir do topo da pilha
int getKthElement(int k) {
    if (k < 1 || k > top + 1) {
        printf("Valor de k está fora do intervalo!\n");
        return -1;
    } else {
        return stack[top - k + 1];
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
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    // Exibir elementos da pilha e o topo e k-ésimo elemento
    printf("Elementos da pilha:\n");
    printStack();
    printf("Elementos principais: %d\n", getTop());
    printf("3º elemento de cima: %d\n", getKthElement(3));

    // Remover o topo da pilha
    pop();

    // Exibir elementos da pilha e o topo e k-ésimo elemento após a remoção
    printf("Elementos da pilha:\n");
    printStack();
    printf("Elementos principais: %d\n", getTop());
    printf("4º elemento de cima: %d\n", getKthElement(4));

    return 0;
}
