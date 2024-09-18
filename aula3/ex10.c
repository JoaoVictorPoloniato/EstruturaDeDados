#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];  // Array para armazenar a pilha
int top = -1;  // Inicializa o topo da pilha

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

// Função para verificar se a pilha está vazia
int isEmpty() {
    return top == -1;
}

// Função auxiliar para inserir um elemento no fundo da pilha
void insertAtBottom(int value) {
    if (isEmpty()) {
        push(value);
    } else {
        int temp = pop();
        insertAtBottom(value);  // Insere o valor no fundo da pilha
        push(temp);  // Coloca de volta os elementos acima do valor inserido
    }
}

// Função para inverter a pilha
void reverseStack() {
    if (!isEmpty()) {
        int temp = pop();
        reverseStack();  // Chamada recursiva para inverter o restante da pilha
        insertAtBottom(temp);  // Insere o valor removido no fundo da pilha
    }
}

// Função para exibir a pilha
void printStack() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    // Empurrando valores para a pilha
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // Exibir a pilha original
    printf("Pilha Original: ");
    printStack();

    // Inverter a pilha
    reverseStack();

    // Exibir a pilha invertida
    printf("Pilha invertida: ");
    printStack();

    return 0;
}
