#include <stdio.h>
 
int main() {
 
    int X[10];
    
    for (int i = 0; i <= 10; i+=1) {
        printf("digite um numero\n");
        scanf("%d", X[i]);

        if (X[i]> 0) {
        
            printf("X[%d]", i,"=%d\n", X[i] );
        }    
        else {
            
            printf("X[%d]", i,"=%d\n", X[i] );
            
        }
    
    }
    return 0;
}