#include <stdio.h>
#define MAX 10  // Tamanho máximo do array

int stack[MAX];
int top1 = -1;         // Topo da primeira pilha
int top2 = MAX;        // Topo da segunda pilha (começa do final do array)

// Função para empurrar (push) na primeira pilha
void push1(int value) {
    if (top1 < top2 - 1) {
        stack[++top1] = value;
    } else {
        printf("A pilha-1 está cheia!\n");
    }
}

// Função para empurrar (push) na segunda pilha
void push2(int value) {
    if (top1 < top2 - 1) {
        stack[--top2] = value;
    } else {
        printf("A pilha-2 está cheia!\n");
    }
}

// Função para remover (pop) da primeira pilha
int pop1() {
    if (top1 >= 0) {
        return stack[top1--];
    } else {
        printf("A pilha-1 está vazia!\n");
        return -1;
    }
}

// Função para remover (pop) da segunda pilha
int pop2() {
    if (top2 < MAX) {
        return stack[top2++];
    } else {
        printf("A pilha-2 está vazia!\n");
        return -1;
    }
}

// Função para exibir os elementos da primeira pilha
void displayStack1() {
    if (top1 >= 0) {
        printf("Os elementos na Stack-1 são: ");
        for (int i = 0; i <= top1; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("A pilha-1 está vazia!\n");
    }
}

// Função para exibir os elementos da segunda pilha
void displayStack2() {
    if (top2 < MAX) {
        printf("Os elementos na Stack-2 são: ");
        for (int i = MAX - 1; i >= top2; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("A pilha-2 está vazia!\n");
    }
}

int main() {
    // Inserindo elementos na Stack-1
    push1(10);
    push1(30);
    push1(40);
    push1(50);

    // Inserindo elementos na Stack-2
    push2(20);
    push2(40);
    push2(50);
    push2(60);
    push2(70);

    // Exibindo as duas pilhas
    displayStack1();
    displayStack2();

    return 0;
}
