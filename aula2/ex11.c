#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* listToString(struct Node* head) {
    struct Node* temp = head;
    char* str = (char*)malloc(1024); // Alocando espaço para a string
    if (str == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    str[0] = '\0'; // Inicializa a string

    while (temp != NULL) {
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%d ", temp->data);
        strcat(str, buffer);
        temp = temp->next;
    }

    return str;
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    head = createList(n);

    char* listString = listToString(head);

    printf("Retorna os dados inseridos na lista como uma string:\n");
    printf("A lista vinculada: %s\n", listString);

    free(listString);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
