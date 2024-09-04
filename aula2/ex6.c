#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista vinculada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar a lista vinculada
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    for(i = 1; i <= n; i++) {
        // Alocação de memória para o novo nó
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Erro de alocação de memória\n");
            exit(1);
        }

        // Inserir dados no nó
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        // Se for o primeiro nó, define como o cabeçalho
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode; // Conecta o nó anterior ao novo nó
        }

        temp = newNode; // Atualiza o ponteiro temporário
    }

    return head;
}

// Função para exibir os dados da lista vinculada
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Os dados inseridos na lista são:\n");
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

// Função para inserir um novo nó no meio da lista vinculada
struct Node* insertAtMiddle(struct Node* head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("A posição fornecida é inválida\n");
            free(newNode);
        }
    }

    return head;
}

int main() {
    int n, data, position;
    struct Node* head = NULL;

    printf("Insira o número de nós (3 ou mais): ");
    scanf("%d", &n);

    if (n < 3) {
        printf("O número de nós deve ser 3 ou mais.\n");
        return 1;
    }

    head = createList(n);

    displayList(head);

    printf("\nDados de entrada para inserir no meio da lista: ");
    scanf("%d", &data);

    printf("Insira a posição para inserir o novo nó: ");
    scanf("%d", &position);

    if (position < 1 || position > n) {
        printf("A posição fornecida é inválida\n");
        return 1;
    }

    head = insertAtMiddle(head, data, position);

    printf("\nInserção concluída com sucesso.\nA nova lista é:\n");
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
