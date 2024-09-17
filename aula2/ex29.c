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

// Função para mesclar duas listas classificadas
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;

    if (l1->data < l2->data) {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }

    return result;
}

// Função para mesclar k listas vinculadas classificadas
struct Node* mergeKLists(struct Node* lists[], int k) {
    if (k == 0) return NULL;

    // Mesclar as listas duas a duas
    while (k > 1) {
        for (int i = 0; i < k / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[k - i - 1]);
        }
        k = (k + 1) / 2;  // Reduzir o número de listas a serem mescladas
    }

    return lists[0];
}

// Função principal
int main() {
    // Criar três listas classificadas
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* list3 = NULL;

    // Lista-1: 10 -> 20 -> 50
    append(&list1, 10);
    append(&list1, 20);
    append(&list1, 50);

    // Lista-2: 30 -> 40 -> 60
    append(&list2, 30);
    append(&list2, 40);
    append(&list2, 60);

    // Lista-3: 10 -> 70 -> 100
    append(&list3, 10);
    append(&list3, 70);
    append(&list3, 100);

    // Colocar todas as listas em um array de ponteiros
    struct Node* lists[] = {list1, list2, list3};

    // Mesclar as k listas
    struct Node* mergedList = mergeKLists(lists, 3);

    // Imprimir a lista mesclada
    printf("Depois de mesclar as três listas classificadas em uma lista classificada:\n");
    printList(mergedList);

    return 0;
}
