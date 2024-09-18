#include <stdio.h>

#define MAX 100

// Estrutura para empurrar elementos na pilha
int stack[MAX];
int top = -1;

// Função para empurrar (push) um elemento na pilha
void push(int value) {
    stack[++top] = value;
}

// Função para remover (pop) um elemento da pilha
int pop() {
    return stack[top--];
}

// Função para verificar se a pilha está vazia
int isEmpty() {
    return top == -1;
}

// Função para encontrar o próximo elemento maior para cada elemento da matriz
void findNextGreater(int arr[], int n) {
    int result[MAX];  // Array para armazenar os resultados

    for (int i = 0; i < n; i++) {
        result[i] = -1;  // Inicializar o resultado com -1
    }

    // Percorrer os elementos da matriz
    for (int i = 0; i < n; i++) {
        // Enquanto a pilha não estiver vazia e o elemento atual for maior que o topo da pilha
        while (!isEmpty() && arr[i] > arr[stack[top]]) {
            result[stack[top]] = arr[i];  // Atualiza o próximo maior elemento
            pop();  // Remove o elemento do topo da pilha
        }
        // Empurrar o índice do elemento atual na pilha
        push(i);
    }

    // Exibir o resultado
    printf("Os próximos elementos maiores são:\n");
    for (int i = 0; i < n; i++) {
        if (result[i] == -1)
            printf("%d --> -1\n", arr[i]);
        else
            printf("%d -> %d\n", arr[i], result[i]);
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Os elementos da matriz são: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    findNextGreater(arr1, n1);
    printf("-----------------------------------------\n");

    int arr2[] = {6, 5, 4, 3, 2, 1, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Os elementos da matriz são: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    findNextGreater(arr2, n2);
    printf("-----------------------------------------\n");

    int arr3[] = {3, 7, 5, 9, 3, 2, 4, 1, 4};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Os elementos da matriz são: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    findNextGreater(arr3, n3);
    printf("-----------------------------------------\n");

    return 0;
}
