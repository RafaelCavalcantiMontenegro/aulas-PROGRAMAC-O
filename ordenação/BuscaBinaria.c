int BuscarBinario(int vetor[], int tam, int numero) {
    int inicio = 0, fim = tam - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == numero) {
            return meio;
        } else if (vetor[meio] > numero) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;