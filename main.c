#include "funcionario.h"

int main() {

    //Funcionario *funcionario = (Funcionario*)malloc(sizeof * (Funcionario));

    FILE *arquivo = fopen("funcionario.txt", "w");
    if(arquivo == NULL) {
        exit(1);
    }

    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    bubbleSort(vetor, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf(" Ordenado com Bubble Sort ");

    clock_t inicio = cloc