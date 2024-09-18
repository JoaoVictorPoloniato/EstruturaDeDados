#include <stdio.h>
#include <string.h>
#define MAX 100  // Define o tamanho máximo da pilha

char stack[MAX];
int top = -1;

// Função para empurrar (push) um caractere na pilha
void push(char c) {
    if (top == MAX - 1) {
        printf("A pilha está cheia!\n");
    } else {
        stack[++top] = c;
    }
}

// Função para remover (pop) um caractere da pilha
char pop() {
    if (top == -1) {
        printf("Pilha vazia!\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

// Função para inverter a string usando uma pilha
void reverseString(char str[]) {
    int n = strlen(str);

    // Empurrar todos os caracteres da string na pilha
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    // Remover os caracteres da pilha para formar a string invertida
    for (int i = 0; i < n; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    // Entrada de string
    printf("Entrada para string: ");
    gets(str);  // Nota: gets() é inseguro, use fgets() em um código real para maior segurança

    // Inverter a string usando uma pilha
    reverseString(str);

    // Exibir a string invertida
    printf("A string invertida usando uma pilha é: %s\n", str);

    return 0;
}
