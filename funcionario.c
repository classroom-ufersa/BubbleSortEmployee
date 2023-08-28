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

void menu(Funcionario*cadastro){

    int opc;
    
    printf("==========MENU==========\n");
    printf("(1) CADASTRAR\n");
    printf("(2) LISTA\n");
    printf("(3) SAIR\n");
    printf("========================");
    scanf("%d",&opc);

    switch(opc){
        case 1: // Cadastrando os dados na struct Funcionario.
           
            do{
                
                printf(" Informe Seu Nome: ");
                scanf(" %[^\n]", cadastro[i]->nome);

                printf(" Informe Seu Cargo: ");
                scanf(" %[^\n]", cadastro[i]->cargo);

                printf(" Informe Seu Documento: ");
                scanf("%d", &cadastro[i]->documento);
                printf("Continuar Cadastrando (1) SIM / (2) NÂO");
                scanf("%d",&opc);
            }while(opc!=2);
         
            break;
        case 2: // Listando os dados do arquivo. 
            printf("NADA AINDA!");
            break;
        case 3: // Fechando o programa.
            printf("OBRIGADO POR USAR O PROGRAMA!\n");
            printf("SAINDO...");
            exit(1);
            break;
        default:
            menu();

    }
}