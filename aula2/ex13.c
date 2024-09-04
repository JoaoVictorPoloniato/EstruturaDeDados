#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

int main() {
    int n1, n2;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    printf("Insira o número de nós para a primeira lista: ");
    scanf("%d", &n1);
    printf("Insira os dados para a primeira lista:\n");
    list1 = createList(n1);

    printf("Insira o número de nós para a segunda lista: ");
    scanf("%d", &n2);
    printf("Insira os dados para a segunda lista:\n");
    list2 = createList(n2);

    printf("Primeira lista:\n");
    displayList(list1);

    printf("Segunda lista:\n");
    displayList(list2);

    mergedList = mergeLists(list1, list2);

    printf("Depois de mesclar as duas listas classificadas:\n");
    displayList(mergedList);

    struct Node* temp;
    while (mergedList != NULL) {
        temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
