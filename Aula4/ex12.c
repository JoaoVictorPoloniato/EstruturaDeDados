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

void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortQueue(struct Queue* q) {
    int size = q->size;
    int* arr = (int*)malloc(size * sizeof(int));
    struct Node* temp = q->front;
    for (int i = 0; i < size; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    temp = q->front;
    for (int i = 0; i < size; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    free(arr);
}

int main() {
    struct Queue q;
    q.front = q.rear = NULL;
    q.size = 0;

    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 7);
    enqueue(&q, 5);
    enqueue(&q, 1);

    printf("Elementos da fila:\n");
    displayQueue(&q);

    sortQueue(&q);

    printf("Elementos da fila classificada em ordem crescente:\n");
    displayQueue(&q);

    enqueue(&q, -1);
    enqueue(&q, 3);

    printf("Elementos da fila:\n");
    displayQueue(&q);

    sortQueue(&q);

    printf("Elementos da fila classificada em ordem crescente:\n");
    displayQueue(&q);

    return 0;
}
