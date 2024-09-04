#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura do nó da lista vinculada
struct Node {
    char data;
    struct Node* next;
};

// Função para criar uma lista vinculada
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    char data;
    int i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Erro de alocação de memória\n");
            exit(1);
        }

        printf("Dados de entrada para o nó %d: ", i);
        scanf(" %c", &data);  // Usar " %c" para consumir o caractere de nova linha
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

// Função para verificar se a lista vinculada é um palíndromo
int isPalindrome(struct Node* head) {
    struct Node *slow = head, *fast = head;
    struct Node *prev = NULL, *next = NULL, *secondHalf = NULL;

    if (head == NULL) return 1;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (fast != NULL) {
        secondHalf = slow->next;
    } else {
        secondHalf = slow;
    }

    prev->next = NULL;

    struct Node* firstHalf = head;
    struct Node* secondHalfStart = reverseList(secondHalf);

    while (firstHalf != NULL && secondHalfStart != NULL) {
        if (firstHalf->data != secondHalfStart->data) {
            return 0;
        }
        firstHalf = firstHalf->next;
        secondHalfStart = secondHalfStart->next;
    }

    return 1;
}

// Função para reverter uma lista vinculada
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Função para exibir os dados da lista vinculada
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    printf("Insira os dados para a lista (somente caracteres):\n");
    head = createList(n);

    printf("Lista original individual:\n");
    displayList(head);

    if (isPalindrome(head)) {
        printf("A lista vinculada é um palíndromo.\n");
    } else {
        printf("A lista vinculada não é um palíndromo.\n");
    }

    // Liberação da memória alocada
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
