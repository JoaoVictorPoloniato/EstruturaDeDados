#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Estrutura da pilha
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
        return '\0';  // Retorna nulo se a pilha estiver vazia
    } else {
        return stack[top--];
    }
}

// Função para verificar se os parênteses estão balanceados
int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);  // Empurra o caractere de abertura na pilha
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char poppedChar = pop();

            // Verifica se o caractere de fechamento corresponde ao de abertura
            if ((exp[i] == ')' && poppedChar != '(') ||
                (exp[i] == '}' && poppedChar != '{') ||
                (exp[i] == ']' && poppedChar != '[')) {
                return 0;  // Não está balanceado
            }
        }
    }

    // Se a pilha não estiver vazia, significa que há parênteses não fechados
    if (top == -1) {
        return 1;  // Está balanceado
    } else {
        return 0;  // Não está balanceado
    }
}

int main() {
    char expression[MAX];

    // Entrada da expressão
    printf("Insira uma expressão entre parênteses: ");
    gets(expression);  // Nota: gets() é inseguro, prefira fgets() em código real

    // Verificar se a expressão está balanceada
    if (isBalanced(expression)) {
        printf("A expressão é equilibrada.\n");
    } else {
        printf("A expressão não é equilibrada.\n");
    }

    return 0;
}
