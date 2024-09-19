#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Definindo o tamanho máximo da fila

typedef struct Queue {
    int items[SIZE];
    int front;
    int rear;
} Queue;

// Função para inicializar a fila
void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return (q->front == -1);
}

// Função para verificar se a fila está cheia
int isFull(Queue* q) {
    return (q->rear == SIZE - 1);
}

// Função para inserir um elemento na fila
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("A fila está cheia. Não é possível inserir novos elementos.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;  // Se for a primeira inserção, inicializa o índice front
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Elemento %d inserido na fila.\n", value);
}

// Função para remover um elemento da fila
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia. Nenhum elemento para remover.\n");
    } else {
        printf("Elemento %d removido da fila.\n", q->items[q->front]);
        q->front++;
        if (q->front > q->rear) {
            // Se todos os elementos forem removidos, redefine a fila
            q->front = q->rear = -1;
        }
    }
}

// Função para exibir os elementos da fila
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Os elementos da fila são: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Função para calcular a soma dos elementos da fila
int sumElements(Queue* q) {
    int sum = 0;
    if (!isEmpty(q)) {
        for (int i = q->front; i <= q->rear; i++) {
            sum += q->items[i];
        }
    }
    return sum;
}

// Função principal
int main() {
    Queue q;
    initialize(&q);

    // Inserir elementos na fila
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    // Exibir os elementos da fila e calcular a soma
    printf("Os elementos da fila são: ");
    display(&q);
    printf("A soma dos elementos da fila é: %d\n", sumElements(&q));

    // Remover 2 elementos da fila
    dequeue(&q);
    dequeue(&q);

    // Exibir os elementos da fila e calcular a soma
    printf("Os elementos da fila são: ");
    display(&q);
    printf("A soma dos elementos na fila é: %d\n", sumElements(&q));

    // Inserir mais 3 elementos
    enqueue(&q, 300);
    enqueue(&q, 400);
    enqueue(&q, 500);

    // Exibir os elementos da fila e calcular a soma
    printf("Os elementos da fila são: ");
    display(&q);
    printf("A soma dos elementos da fila é: %d\n", sumElements(&q));

    return 0;
}