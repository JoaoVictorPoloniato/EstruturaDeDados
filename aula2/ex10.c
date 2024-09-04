#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    for(i = 1; i <= n; i++) {
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

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Os dados inseridos na lista são:\n");
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

void searchElement(struct Node* head, int element) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == element) {
            printf("Elemento encontrado no nó %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Elemento não encontrado na lista\n");
}

int main() {
    int n, element;
    struct Node* head = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    head = createList(n);

    displayList(head);

    printf("\nInsira o elemento a ser pesquisado: ");
    scanf("%d", &element);

    searchElement(head, element);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
