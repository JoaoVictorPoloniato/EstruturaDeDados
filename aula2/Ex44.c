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

void appendNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayListReverse(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
  
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    
    int index = 1;
    while (temp != NULL) {
        printf("Dados no nó %d: %d\n", index, temp->data);
        temp = temp->prev;
        index++;
    }
}


int main() {
    Node* head = NULL;
    int numNodes, data;

 
    printf("Insira o número de nós: ");
    scanf("%d", &numNodes);


    for (int i = 1; i <= numNodes; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        appendNode(&head, data);
    }

  
    printf("As datas na ordem inversa são:\n");
    displayListReverse(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
