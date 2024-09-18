#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

// Função para inserir um elemento na pilha (push)
void push(int value) {
    if (top == MAX - 1) {
        printf("Pilha cheia!\n");
    } else {
        stack[++top] = value;
    }
}

// Função para remover um elemento da pilha (pop)
int pop() {
    if (top == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Função para exibir os elementos da pilha
void display() {
    if (top == -1) {
        printf("Pilha vazia!\n");
    } else {
        printf("Os elementos da pilha são: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Inserindo elementos na pilha
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(3);

    // Exibindo os elementos da pilha
    display();

    return 0;
}
