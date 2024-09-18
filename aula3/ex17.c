#include <stdio.h>
#include <stdlib.h>

#define MAX 32 // Assume um tamanho máximo para a pilha

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

// Função para converter um número decimal para binário usando uma pilha
void decimalToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    while (num > 0) {
        push(num % 2);
        num /= 2;
    }

    printf("O equivalente binário é: ");
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int number;

    // Entrada e conversão de números
    printf("Insira um número decimal: ");
    scanf("%d", &number);
    decimalToBinary(number);

    printf("Insira um número decimal: ");
    scanf("%d", &number);
    decimalToBinary(number);

    printf("Entrada para número decimal: ");
    scanf("%d", &number);
    decimalToBinary(number);

    return 0;
}
