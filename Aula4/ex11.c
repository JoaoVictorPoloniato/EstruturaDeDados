#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
}

void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNthElement(struct Queue* q, int n) {
    if (q->size == 0) {
        printf("Erro: a fila está vazia\n");
        return;
    }

    if (n <= 0 || n > q->size) {
        printf("Erro: posição inválida\n");
        return;
    }

    if (n == 1) {
        dequeue(q);
        return;
    }

    struct Node* temp = q->front;
    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    if (nodeToDelete == q->rear) {
        q->rear = temp;
    }

    free(nodeToDelete);
    q->size--;
}

int main() {
    struct Queue q;
    q.front = q.rear = NULL;
    q.size = 0;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Os elementos da fila são:\n");
    displayQueue(&q);

    printf("Exclua o 7º elemento da referida fila:\n");
    deleteNthElement(&q, 7);

    printf("Exclua o terceiro elemento da referida fila:\n");
    deleteNthElement(&q, 3);

    printf("Os elementos da fila são:\n");
    displayQueue(&q);

    return 0;
}
