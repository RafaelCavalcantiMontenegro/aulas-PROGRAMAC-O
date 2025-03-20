#include <stdio.h>

int main() {

    int T;
    int N[1000];
    int x = -1;
    
    
    scanf("%d", &T);

    

    for (int i = 0; i < 1000; i ++) {
        N[i] += x;
        x +=1 ;
        if (x >= T) {
            x = 0;
        }
        printf("N[%d] = %d\n", i, x);
    }

    return 0;    
}


