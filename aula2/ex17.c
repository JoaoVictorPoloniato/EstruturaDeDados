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

// Função para exibir os dados da lista vinculada
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para dividir a lista em duas metades
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* slow;
    struct Node* fast;
    
    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        slow = source;
        fast = source->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

// Função para mesclar duas listas ordenadas
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

// Função para classificar a lista usando merge sort
struct Node* mergeSort(struct Node* head) {
    struct Node* head1;
    struct Node* head2;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    splitList(head, &head1, &head2);

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    return mergeLists(head1, head2);
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Classifique a referida lista vinculada individualmente usando classificação por mesclagem:\n");
    displayList(head);

    head = mergeSort(head);

    printf("Depois de classificar a referida lista:\n");
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
