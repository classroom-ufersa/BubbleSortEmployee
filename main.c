#include <time.h>
#include "funcionario.c"

int main() {

    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    bubbleSort(vetor, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf(" Ordenado com Bubble Sort ");

    clock_t inicio = clock();
    // Executar o algoritmo
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; //milisegundos
    printf("Tempo de execucao: %.50f\n", tempo);

    return 0;
}