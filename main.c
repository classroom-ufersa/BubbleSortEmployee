#include "funcionario.h"

#define MAX_FUNCIONARIO 10

int main() {

    //Funcionario *var_funcionario[10]; //CONSERTAR

    Funcionario *VarFuncionario[10];

    // criando arquivo de texto para armazenar os dados dos funcionarios.
    FILE *arquivo = fopen("funcionario.txt", "w");
    if(arquivo == NULL) {
        exit(1);
    }

    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    //Funcionario *VarFuncionario = menu(); //CONSERTAR
    
    char nome[50], cargo[50];
    int documento;

    int opc, contador = 0, sair = 0;
    
    /*printf("==========MENU==========\n");
    printf("(1) CADASTRAR\n");
    printf("(2) LISTA\n");
    printf("(3) SAIR\n");
    printf("========================");*/

    do {
        menu();
        scanf("%d", &opc); 

        switch(opc){
            case 1: // Cadastrando os dados na struct Funcionario.
                 do{
                        contador++;
                        printf("FUNCIONARIO %i\n", contador + 1);
                        printf(" Informe Seu Nome: ");
                        scanf(" %[^\n]", VarFuncionario[contador]->nome);

                        printf(" Informe Seu Cargo: ");
                        scanf(" %[^\n]", VarFuncionario[contador]->cargo);

                        printf(" Informe Seu Documento: ");
                        scanf("%d", &VarFuncionario[contador]->documento);
                        printf("Continuar Cadastrando (1) SIM / (2) NÂO");
                        scanf("%d", &sair);

                        if(contador = MAX_FUNCIONARIO) {
                            printf("Limite de cadastro foi atingido! \n");
                        }    

                 } while(sair != 1 || contador != 10);
        
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
                printf("Numero errado! Tente novamente! \n");
                menu(); 
        }
        
    } while(opc != 3);

    //Funcionario *VarFuncionario = CriarFuncionario(nome, cargo, documento);

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
    
    return 0;
}