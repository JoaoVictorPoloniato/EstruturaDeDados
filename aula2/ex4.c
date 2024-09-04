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

// Função para inserir um novo nó no início da lista vinculada
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = head; // O novo nó aponta para o antigo cabeçalho
    head = newNode; // O novo nó se torna o cabeçalho

    return head;
}

int main() {
    int n, newData;
    struct Node* head = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    head = createList(n);

    displayList(head);

    printf("\nDados de entrada para inserir no início da lista: ");
    scanf("%d", &newData);

    head = insertAtBeginning(head, newData);

    printf("\nOs dados depois de inseridos na lista são:\n");
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
