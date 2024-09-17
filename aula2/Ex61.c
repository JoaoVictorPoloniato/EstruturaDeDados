#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, int data) {
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

char* convertToString(Node* head) {
    if (head == NULL) {
        return strdup("");
    }
    
    Node* temp = head;
    int length = 0;
    while (temp != NULL) {
        length += snprintf(NULL, 0, "%d ", temp->data);
        temp = temp->next;
    }
    
    char* str = (char*)malloc(length + 1);
    str[0] = '\0';
    
    temp = head;
    while (temp != NULL) {
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "%d ", temp->data);
        strcat(str, buffer);
        temp = temp->next;
    }
    
    // Remove trailing space
    if (length > 0) {
        str[length - 1] = '\0';
    }
    
    return str;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int numNodes, data;

    printf("Insira o número de nós: ");
    scanf("%d", &numNodes);

    for (int i = 1; i <= numNodes; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    printf("A lista duplamente vinculada em formato de string: ");
    char* str = convertToString(head);
    printf("%s\n", str);

    free(str);
    return 0;
}
