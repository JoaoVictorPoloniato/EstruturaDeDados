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


void insertAtPosition(Node** headRef, int data, int position) {
    Node* newNode = createNode(data);
    if (position <= 1) {
        newNode->next = *headRef;
        if (*headRef != NULL) {
            (*headRef)->prev = newNode;
        }
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        int currentPosition = 1;
        while (temp != NULL && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }
        if (temp == NULL) {
            printf("A posição fornecida está além do comprimento da lista.\n");
            free(newNode);
            return;
        } else { 
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }
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


int main() {
    Node* head = NULL;
    int numNodes, data, position;

   
    printf("Insira o número de nós (3 ou mais): ");
    scanf("%d", &numNodes);

    for (int i = 1; i <= numNodes; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        insertAtPosition(&head, data, i); 
    }

    printf("Os dados inseridos na lista são:\n");
    displayList(head);

  
    printf("Insira a posição (2 a %d) para inserir um novo nó: ", numNodes + 1);
    scanf("%d", &position);
    if (position < 2 || position > numNodes + 1) {
        printf("A posição fornecida é inválida. Deve estar entre 2 e %d.\n", numNodes + 1);
        return 1;
    }
    printf("Dados de entrada para a posição %d: ", position);
    scanf("%d", &data);

  
    insertAtPosition(&head, data, position);

    
    printf("Após a inserção a nova lista é:\n");
    displayList(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
