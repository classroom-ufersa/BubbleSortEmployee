#include "funcionario.h"

struct funcionario {
    char nome[50];
    char cargo[50];
    int documento;
};

// Função que vai ordenar as string em ordem.
void bubbleSort(int *vetor, int tamanho) {
    int i, j, aux;
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void menu(){

    int opc;
    
    printf("==========MENU==========\n");
    printf("(1) CADASTRAR\n");
    printf("(2) LISTA\n");
    printf("(3) SAIR\n");
    printf("========================")
    scanf("%d",&opc);

    switch(opc){
        case 1:
            printf("NADA AINDA!");
            break;
        case 2:
            printf("NADA AINDA!");
            break;
        case 3:
            printf("OBRIGADO POR USAR O PROGRAMA!\n")
            printf("SAINDO...")
            exit(1);
            break;
        default:
            menu();

    }
}