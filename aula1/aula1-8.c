#include <stdio.h>

int main() {
    int i = 5; 
    int j;

    
    if(i <= 0 || i >= 20) {
        printf("O valor de i deve ser um inteiro positivo não nulo e menor que 20.\n");
        return 1;
    }

    
    for(int row = 1; row <= i; row++) {

        for(j = 1; j <= i - row; j++) {
            printf(" ");
        }
        
        for(j = 1; j <= row; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
