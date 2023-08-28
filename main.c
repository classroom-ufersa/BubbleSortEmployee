#include "funcionario.h"

int main() {
    
    // criando arquivo de texto para armazenar os dados dos funcionarios.
    FILE *arquivo = fopen("funcionario.txt", "w");
    if(arquivo == NULL) {
        exit(1);
    }

    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    // Passando os dados para a função bublleSort.
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

    fclose(arquivo);

    char nome[50], cargo[50];
    int documento;


    printf(" informe seu nome: ");
    scanf(" %[^\n]", nome);

    printf(" informe seu cargo: ");
    scanf(" %[^\n]", cargo);

    printf(" informe seu documento: ");
    scanf("%d", &documento);


    return 0;
}