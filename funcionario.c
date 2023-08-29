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

Funcionario *CriarFuncionario(char *nome, char *cargo, int documento) {
    Funcionario *VarFuncionario = (Funcionario*)malloc(sizeof(Funcionario));
    if(VarFuncionario == NULL) {
        printf("Variavel VarFuncionario nao foi alocada dinamicamente! \n");
        exit(1);
    }

    strcpy(VarFuncionario->nome, nome); //copiar string
    strcpy(VarFuncionario->cargo, cargo); //copiar string
    VarFuncionario->documento = documento; //documento(struct) recebe documento(parâmetro)

    return VarFuncionario;
}

void menu() {
    
    printf("==========MENU==========\n");
    printf("(1) CADASTRAR\n");
    printf("(2) LISTA\n");
    printf("(3) SAIR\n");
    printf("======================== \n");
}