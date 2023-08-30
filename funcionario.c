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
/*void CriaArquivo(FILE *arquivo, Funcionario **VarFuncionario) {
    int contador;

    for(contador = 0; contador < 10; contador++) {
        printf("FUNCIONARIO %i \n", contador);
        fprintf(arquivo, "Nome: %s \n Cargo: %s \n Documento: %i \n\n", VarFuncionario[contador]->nome, VarFuncionario[contador]->cargo, VarFuncionario[contador]->documento);
    }
}*/
void Ordenar(FILE *arquivo, Funcionario *VarFuncionario[], int tamanho) {
    int i, j;
    Funcionario *aux;  // var do tipo funcionario 
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho - 1; j++) {
            if (strcmp(VarFuncionario[j]->nome, VarFuncionario[j + 1]->nome) > 0){ // > 0 - compara se o vetor de trás é maior do que o da frente
                aux = VarFuncionario[j]; //passa tudo, nao somente o nome
                VarFuncionario[j] = VarFuncionario[j + 1]; 
                VarFuncionario[j + 1] = aux;
            }
        }
    }

    for(i = 0; i < tamanho; i++) {

        fprintf(arquivo, "Nome: %s \nCargo: %s \nDocumento: %i \n", VarFuncionario[i]->nome, VarFuncionario[i]->cargo, VarFuncionario[i]->documento);
        fprintf(arquivo, "-----------------------\n");
    }
}

void ImprimirTela(FILE *arquivo, Funcionario *VarFuncionario[], int tamanho) {
    int contador;
    for(contador = 0; contador < tamanho; contador++) {
        printf("Nome: %s \nCargo: %s\nDocumento: %i \n", VarFuncionario[contador]->nome, VarFuncionario[contador]->cargo, VarFuncionario[contador]->documento);  //trocar para pegar dentro do arquivo e imprimir na tela
    }
}