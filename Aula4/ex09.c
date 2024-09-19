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

int findMax(struct Queue* q) {
    if (q->front == NULL) {
        printf("A fila está vazia\n");
        return -1;
    }

    int max = q->front->data;
    struct Node* temp = q->front->next;

    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
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

    printf("O valor máximo na fila é: %d\n", findMax(&q));

    printf("Remova 2 elementos da referida fila:\n");
    dequeue(&q);
    dequeue(&q);

    printf("Os elementos da fila são:\n");
    displayQueue(&q);

    printf("O valor máximo na fila é: %d\n", findMax(&q));

    enqueue(&q, 600);
    enqueue(&q, 427);
    enqueue(&q, 519);

    printf("Os elementos da fila são:\n");
    displayQueue(&q);

    printf("O valor máximo na fila é: %d\n", findMax(&q));

    return 0;
}
