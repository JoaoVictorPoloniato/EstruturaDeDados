#include <stdio.h>

int main() {
    int i, j, linhas;

    printf("Digite o número de linhas da figura (inteiro positivo): ");
    scanf("%d", &linhas);

    if(linhas <= 0) {
        printf("O número de linhas deve ser um inteiro positivo.\n");
        return 1;
    }

    for(i = linhas; i > 0; i--) {
        for(j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
