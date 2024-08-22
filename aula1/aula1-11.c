#include <stdio.h>

int main() {
    int i, j, linhas;

    // Solicitar ao usuário o número de linhas
    printf("Digite o número de linhas da figura (inteiro positivo): ");
    scanf("%d", &linhas);

    // Verifica se o valor de linhas é positivo
    if(linhas <= 0) {
        printf("O número de linhas deve ser um inteiro positivo.\n");
        return 1;
    }

    // Parte 1: Triângulo invertido
    for(i = linhas; i > 0; i--) {
        for(j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Parte 2: Triângulo crescente
    for(i = 1; i <= linhas; i++) {
        for(j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
