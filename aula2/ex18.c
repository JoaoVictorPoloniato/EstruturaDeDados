
#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista vinculada com ponteiros aleatórios
struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

// Função para criar uma lista vinculada com ponteiros aleatórios
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *prev = NULL;
    int data;

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        temp = createNode(data);

        if (head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    return head;
}

// Função para exibir a lista com ponteiros aleatórios
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Data: %d, Aleatório: %d\n", temp->data, (temp->random ? temp->random->data : -1));
        temp = temp->next;
    }
}

// Função para definir ponteiros aleatórios para a lista
void setRandomPointers(struct Node* head) {
    struct Node* temp = head;
    struct Node* nodes[100];
    int i = 0;

    while (temp != NULL) {
        nodes[i++] = temp;
        temp = temp->next;
    }

    int numNodes = i;
    temp = head;
    while (temp != NULL) {
        int randomIndex = rand() % numNodes; // Aleatório
        temp->random = nodes[randomIndex];
        temp = temp->next;
    }
}

// Função para criar uma cópia da lista com ponteiros aleatórios
struct Node* copyList(struct Node* head) {
    struct Node *orig = head, *copy = NULL, *lastCopied = NULL;
    struct Node* map[100] = {0}; // Mapeia os nós originais para seus cópias

    while (orig != NULL) {
        struct Node* newNode = createNode(orig->data);
        map[orig->data] = newNode;
        if (copy == NULL) {
            copy = newNode;
        } else {
            lastCopied->next = newNode;
        }
        lastCopied = newNode;
        orig = orig->next;
    }

    orig = head;
    struct Node* copied = copy;
    while (orig != NULL) {
        copied->random = map[orig->random ? orig->random->data : -1];
        orig = orig->next;
        copied = copied->next;
    }

    return copy;
}

int main() {
    int n;
    struct Node* head = NULL;
    struct Node* copiedHead = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    head = createList(n);
    setRandomPointers(head);

    printf("Lista única original:\n");
    displayList(head);

    copiedHead = copyList(head);

    printf("\nDepois de definir os ponteiros aleatórios:\n");
    displayList(copiedHead);

    // Liberação da memória alocada
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    while (copiedHead != NULL) {
        temp = copiedHead;
        copiedHead = copiedHead->next;
        free(temp);
    }

    return 0;
}
