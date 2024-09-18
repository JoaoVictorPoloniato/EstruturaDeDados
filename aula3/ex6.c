#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

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

// Função para exibir a pilha
void display() {
    if (top == -1) {
        printf("A pilha está vazia!\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Função para ordenar a pilha usando outra pilha
void sortStack() {
    int tempStack[MAX];
    int tempTop = -1;

    while (top != -1) {
        int temp = pop();  // Retira o topo da pilha original

        // Transfere os elementos maiores da pilha temporária de volta para a original
        while (tempTop != -1 && tempStack[tempTop] > temp) {
            push(tempStack[tempTop--]);
        }

        // Empurra o elemento atual na pilha temporária
        tempStack[++tempTop] = temp;
    }

    // Transferir os elementos da pilha temporária de volta para a original
    while (tempTop != -1) {
        push(tempStack[tempTop--]);
    }
}

int main() {
    // Inserir elementos na pilha
    push(1);
    push(5);
    push(5);
    push(2);
    push(3);
    push(8);

    // Exibir pilha original
    printf("Pilha original: ");
    display();

    // Ordenar a pilha
    sortStack();

    // Exibir pilha ordenada
    printf("Pilha ordenada: ");
    display();

    return 0;
}
