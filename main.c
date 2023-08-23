#include <stdio.h>
#include <time.h>
#include "funcionario.h"

int main() {
    clock_t inicio = clock();
    // Executar o algoritmo
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", tempo);
    return 0;
}