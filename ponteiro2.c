#include <stdio.h>

const int TAM = 4;

int main() {
    int v[] = { 1, 2, 3, 4};
    printf("v = %p\n", v);
    for (int i = 0; i < TAM; i ++) {
        printf("v[%d] = %d - (%p)\n", i, v[i], &v[i]);

    }
    printf("*v = %d\n", *v);
    printf("*(v +1) = %d - (v + 1) = %p\n", *(v + 1), v + 1);
    return 0;
}