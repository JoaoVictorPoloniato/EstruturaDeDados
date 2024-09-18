#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];  // Array para armazenar as duas pilhas
int top1 = -1;  // Topo da pilha 1
int top2 = MAX;  // Topo da pilha 2

// Função para empurrar (push) um valor na pilha 1
void push1(int value) {
    if (top1 < top2 - 1) {
        arr[++top1] = value;
    } else {
        printf("A pilha 1 está cheia!\n");
    }
}

// Função para empurrar (push) um valor na pilha 2
void push2(int value) {
    if (top1 < top2 - 1) {
        arr[--top2] = value;
    } else {
        printf("A pilha 2 está cheia!\n");
    }
}

// Função para remover (pop) um valor da pilha 1
int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        printf("A pilha 1 está vazia!\n");
        return -1;
    }
}

// Função para remover (pop) um valor da pilha 2
int pop2() {
    if (top2 < MAX) {
        return arr[top2++];
    } else {
        printf("A pilha 2 está vazia!\n");
        return -1;
    }
}

int main() {
    // Empurrando valores para a pilha 1
    push1(1);
    push1(2);
    push1(3);

    // Empurrando valores para a pilha 2
    push2(10);
    push2(20);
    push2(30);

    // Removendo e exibindo valores da pilha 1
    printf("%d saiu da pilha 1\n", pop1());
    printf("%d saiu da pilha 1\n", pop1());
    printf("%d saiu da pilha 1\n", pop1());

    // Removendo e exibindo valores da pilha 2
    printf("%d saiu da pilha 2\n", pop2());
    printf("%d saiu da pilha 2\n", pop2());
    printf("%d saiu da pilha 2\n", pop2());

    return 0;
}
