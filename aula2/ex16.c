#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista vinculada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar uma lista vinculada
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Erro de alocação de memória\n");
            exit(1);
        }

        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    return head;
}

// Função para remover duplicatas da lista vinculada
void removeDuplicates(struct Node* head) {
    struct Node *current = head;
    struct Node *prev, *runner;

    while (current != NULL && current->next != NULL) {
        prev = current;
        runner = current->next;

        while (runner != NULL) {
            if (current->data == runner->data) {
                prev->next = runner->next;
                free(runner);
            } else {
                prev = runner;
            }
            runner = prev->next;
        }
        current = current->next;
    }
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

int main() {
    int n;
    struct Node* head = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Lista original individual:\n");
    displayList(head);

    removeDuplicates(head);

    printf("Depois de remover elementos duplicados da referida lista única:\n");
    displayList(head);

    // Liberação da memória alocada
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
