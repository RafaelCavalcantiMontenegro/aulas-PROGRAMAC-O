// *#include <stdio.h>

void ordenar_insercao(int v[], int x, int pos) {
    int tamanho = 6;
    for (int i = 1; i < tamanho; i+=1) {
        int x = v[i];
        int pos = i;
        while (pos > 0 && x < v[pos -1]) {
            v[pos] = v[pos -1];
            pos = pos -1;
        
        }
        x = v[pos-1];
    }  
}

int main() {
    int v[] = {9,4,2,5,6,1};
    int tamanho = 6;
    int x, pos;
    ordenar_insercao(v[], x, pos);
    
}

//

