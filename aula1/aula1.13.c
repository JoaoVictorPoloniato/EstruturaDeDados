#include <stdio.h>

int main() {
    int i, j, linhas;

    // Solicitar ao usuário o número de linhas
    printf("Digite o número de linhas da figura (inteiro positivo e par): ");
    scanf("%d", &linhas);

    // Verifica se o valor de linhas é positivo e par
    if(linhas <= 0 || linhas % 2 != 0) {
        printf("O número de linhas deve ser um inteiro positivo e par.\n");
        return 1;
    }

    // Imprime a primeira metade da figura
    for(i = 0; i < linhas / 2; i++) {
        for(j = 0; j < linhas; j++) {
            if (j < linhas / 2) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Imprime a segunda metade da figura
    for(i = 0; i < linhas / 2; i++) {
        for(j = 0; j < linhas; j++) {
            if (j >= i && j < linhas - i) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
