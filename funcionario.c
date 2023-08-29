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

/*void menu(Funcionario *VarFuncionario){  //CONSERTAR

    int opc, contador;
    
    printf("==========MENU==========\n");
    printf("(1) CADASTRAR\n");
    printf("(2) LISTA\n");
    printf("(3) SAIR\n");
    printf("========================");
    scanf("%d",&opc);

    switch(opc){
        case 1: // Cadastrando os dados na struct Funcionario.
           
           for(contador = 0; contador < MAX_FUNCIONARIO; contador++) {
                printf(" Informe Seu Nome: ");
                scanf(" %[^\n]", VarFuncionario[contador].nome);

                printf(" Informe Seu Cargo: ");
                scanf(" %[^\n]", VarFuncionario[contador].cargo);

                printf(" Informe Seu Documento: ");
                scanf("%d", &VarFuncionario[contador].documento);
                printf("Continuar Cadastrando (1) SIM / (2) NÂO");
                scanf("%d",&opc);

                if(contador = MAX_FUNCIONARIO) {
                    printf("Limite de cadastro foi atingido! \n");
                }
           }     

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
            menu(); // CONSERTAR
    }
}*/