#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da árvore binária
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para percorrer a árvore binária em ordem (in-order traversal)
void inOrderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }

    // Percorrer a subárvore à esquerda
    inOrderTraversal(node->left);

    // Imprimir o valor do nó
    printf("%d ", node->data);

    // Percorrer a subárvore à direita
    inOrderTraversal(node->right);
}

// Função principal
int main() {
    // Criar os nós da árvore manualmente
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    // Exibir a travessia em ordem (in-order) da árvore binária
    printf("Travessia de uma árvore binária (in-order): ");
    inOrderTraversal(root);

    return 0;
}
