#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista vinculada
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

// Função para inserir um nó no final da lista
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Função para imprimir a lista vinculada
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Função para reordenar a lista colocando os nós ímpares à frente dos pares
struct Node* reorderList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* oddHead = NULL, *oddTail = NULL;
    struct Node* evenHead = NULL, *evenTail = NULL;
    struct Node* current = head;

    // Distribuir os nós entre as listas ímpares e pares
    while (current != NULL) {
        if (current->data % 2 != 0) {
            // Nó ímpar
            if (oddHead == NULL) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        } else {
            // Nó par
            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        current = current->next;
    }

    // Terminar a lista de nós pares
    if (evenTail != NULL) {
        evenTail->next = NULL;
    }

    // Conectar a lista de ímpares à lista de pares
    if (oddTail != NULL) {
        oddTail->next = evenHead;
    }

    // Retornar a nova lista reordenada
    return oddHead != NULL ? oddHead : evenHead;
}

// Função principal
int main() {
    struct Node* head = NULL;

    // Criar a lista: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    // Imprimir a lista original
    printf("Lista original individual:\n");
    printList(head);

    // Reordenar a lista colocando os nós ímpares à frente dos pares
    head = reorderList(head);

    // Imprimir a lista reordenada
    printf("Reordene a referida lista vinculada colocando todos os nós ímpares à frente de todos os nós pares:\n");
    printList(head);

    return 0;
}
