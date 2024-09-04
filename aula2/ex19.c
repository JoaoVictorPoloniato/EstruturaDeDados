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

// Função para encontrar a interseção entre duas listas vinculadas
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    while (temp1 != NULL) {
        struct Node* temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                return temp1; // Retorna o primeiro nó onde há interseção
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return NULL; // Sem interseção
}

int main() {
    int n1, n2;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersection = NULL;

    printf("Insira o número de nós para a primeira lista: ");
    scanf("%d", &n1);
    head1 = createList(n1);

    printf("Insira o número de nós para a segunda lista: ");
    scanf("%d", &n2);
    head2 = createList(n2);

    printf("Listas originais:\n");
    printf("Lista 1: ");
    displayList(head1);
    printf("Lista 2: ");
    displayList(head2);

    intersection = findIntersection(head1, head2);

    if (intersection != NULL) {
        printf("Interseção encontrada em %d.\n", intersection->data);
    } else {
        printf("Interseção não encontrada.\n");
    }

    // Liberação da memória alocada
    struct Node* temp;
    while (head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL) {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}
