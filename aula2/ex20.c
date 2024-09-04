#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista vinculada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para criar uma lista vinculada com dados fornecidos pelo usuário
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

// Função para exibir os dados da lista vinculada
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para obter os últimos n nós de uma lista vinculada
void printLastNNodes(struct Node* head, int n) {
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;

    int count = 0;

    // Move ref_ptr para a frente n nós
    while (count < n) {
        if (ref_ptr == NULL) {
            printf("Número de nós solicitado é maior do que o tamanho da lista.\n");
            return;
        }
        ref_ptr = ref_ptr->next;
        count++;
    }

    // Move ambos os ponteiros até o final da lista
    while (ref_ptr != NULL) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    // Exibe os últimos n nós
    printf("Últimos %d nós do final da referida lista única:\n", n);
    while (main_ptr != NULL) {
        printf("%d ", main_ptr->data);
        main_ptr = main_ptr->next;
    }
    printf("\n");
}

int main() {
    int n, numNodes;
    struct Node* head = NULL;

    printf("Insira o número de nós na lista: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Lista original:\n");
    displayList(head);

    printf("Últimos n nós do final da referida lista única:\n");
    printf("Últimos 2 nós do final da referida lista única:\n");
    printLastNNodes(head, 2);

    printf("Últimos 3 nós do final da referida lista única:\n");
    printLastNNodes(head, 3);

    printf("Últimos 4 nós do final da referida lista única:\n");
    printLastNNodes(head, 4);

    printf("Último 1 nó do final da referida lista única:\n");
    printLastNNodes(head, 1);

    printf("Últimos 5 nós do final da referida lista única:\n");
    printLastNNodes(head, 5);

    // Liberação da memória alocada
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
