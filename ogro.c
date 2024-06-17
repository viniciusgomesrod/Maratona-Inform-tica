#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N == 0) {
        printf("*\n*\n");  // Caso especial para N igual a 0
    } else if (N <= 5) {
        for (int i = 0; i < N; ++i) {
            printf("I");
        }
        printf("\n");
        printf("*\n");
    } else {
        printf("IIIII\n");
        for (int i = 0; i < N - 5; ++i) {
            printf("I");
        }
        printf("\n");
    }

    return 0;
}
