#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista vinculada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para inicializar a fila
void initialize(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Função para inserir um elemento na fila
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        // Se a fila está vazia, tanto o front quanto o rear apontam para o novo nó
        q->front = newNode;
        q->rear = newNode;
    } else {
        // Adiciona o novo nó ao final da fila e move o rear
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Elemento %d inserido na fila.\n", value);
}

// Função para exibir os elementos da fila
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
    } else {
        Node* temp = q->front;
        printf("Os elementos da fila são: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Função principal
int main() {
    Queue q;
    initialize(&q);

    printf("Inicialize uma fila!\n");

    // Verificar se a fila está vazia
    printf("Verifique se a fila está vazia ou não? %s\n", isEmpty(&q) ? "Sim" : "Não");

    // Inserir elementos na fila
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    // Exibir os elementos da fila
    display(&q);

    // Inserir outro elemento na fila
    enqueue(&q, 4);

    // Exibir os elementos da fila novamente
    display(&q);

    // Verificar se a fila está vazia
    printf("Verifique se a fila está vazia ou não? %s\n", isEmpty(&q) ? "Sim" : "Não");

    return 0;
}
