#include <stdio.h>
#define MAX 3  // Define o tamanho máximo da pilha

int stack[MAX];
int top = -1;

// Função para verificar se a pilha está cheia
int isFull() {
    return top == MAX - 1;
}

// Função para verificar se a pilha está vazia
int isEmpty() {
    return top == -1;
}

// Função para empurrar (push) um elemento na pilha
void push(int value) {
    if (isFull()) {
        printf("A pilha está cheia!\n");
    } else {
        stack[++top] = value;
        printf("Empurrado: %d\n", value);
    }
}

// Função para remover (pop) um elemento da pilha
int pop() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Função para exibir os elementos da pilha
void display() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
    } else {
        printf("Pilha Original: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Função para exibir o tamanho da pilha
void stackSize() {
    printf("Tamanho da pilha: %d\n", top + 1);
}

int main() {
    // Empurrar elementos na pilha
    push(1);
    push(2);
    push(3);

    // Exibir o estado da pilha
    stackSize();
    display();

    // Tentar empurrar outro valor
    printf("Empurre outro valor e verifique se a pilha está cheia ou não!\n");
    push(4);

    // Exibir o tamanho da pilha
    stackSize();

    // Remover dois elementos da pilha
    pop();
    pop();

    // Empurrar novos valores
    push(10);
    push(20);

    // Exibir o estado da pilha
    stackSize();
    display();

    // Verificar se a pilha está cheia novamente
    if (isFull()) {
        printf("A pilha está cheia!\n");
    } else {
        printf("A pilha não está cheia!\n");
    }

    return 0;
}
