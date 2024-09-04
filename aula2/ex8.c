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

struct Node* deleteNodeAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = head->next;
        printf("Os dados do nó %d que está sendo excluído são: %d\n", position, temp->data);
        free(temp);
        return head;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("A posição fornecida é inválida\n");
        return head;
    }

    prev->next = temp->next;
    printf("Os dados do nó %d que está sendo excluído são: %d\n", position, temp->data);
    free(temp);

    return head;
}

int main() {
    int n, position;
    struct Node* head = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    head = createList(n);

    displayList(head);

    printf("\nInsira a posição do nó a ser excluído: ");
    scanf("%d", &position);

    head = deleteNodeAtPosition(head, position);

    printf("\nExclusão concluída com sucesso.\nA nova lista é:\n");
    displayList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
