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

// Função para criar um loop na lista vinculada
void createLoop(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }

    if (loopNode != NULL) {
        temp->next = loopNode;
    }
}

// Função para detectar e remover um loop na lista vinculada
void detectAndRemoveLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    struct Node *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detectado
            printf("Loop detectado\n");
            break;
        }
    }

    if (slow != fast) {
        // Nenhum loop detectado
        printf("Nenhum loop detectado\n");
        return;
    }

    // Encontrar o início do loop
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Encontrar o nó final do loop
    while (fast->next != slow) {
        fast = fast->next;
    }
    fast->next = NULL;

    printf("Loop removido\n");
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
    int n, loopPos;
    struct Node* head = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Lista vinculada única original:\n");
    displayList(head);

    printf("Insira a posição para criar um loop (0 para nenhum loop): ");
    scanf("%d", &loopPos);

    if (loopPos > 0) {
        createLoop(head, loopPos);
    }

    printf("Criar o ciclo. Exibe a lista:\n");
    displayList(head);

    detectAndRemoveLoop(head);

    printf("Depois de remover o referido loop:\n");
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
