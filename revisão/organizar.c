#include <stdio.h>

void ordenarinsercao(int v[], int x, int pos) {
    while (pos > 0 && x < v[pos -1]) {
        v[pos] = v[pos -1];
        pos = pos -1;
    }
    x = v[pos-1];   
}

void ordenar (int v[], int x, int pos){
    pos = x + 1;
    while ()
}