#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) { 
        *headRef = newNode;
        return;
    }
    Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void displayList(Node* head) {
    Node* temp = head;
    int index = 1;
    while (temp != NULL) {
        printf("nó %d: %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }
}

void deleteFirstNode(Node** headRef) {
    if (*headRef == NULL) {
        printf("A lista está vazia, nada a excluir.\n");
        return;
    }
    Node* temp = *headRef;
    *headRef = (*headRef)->next; 
    if (*headRef != NULL) {
        (*headRef)->prev = NULL; 
    }
    free(temp); 
}

// Função principal
int main() {
    Node* head = NULL;
    int numNodes, data;


    printf("Insira o número de nós (3 ou mais): ");
    scanf("%d", &numNodes);

    for (int i = 1; i <= numNodes; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data); 
    }

 
    printf("Os dados inseridos na lista são:\n");
    displayList(head);


    deleteFirstNode(&head);

    printf("Após a exclusão, a nova lista é:\n");
    displayList(head);


    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
