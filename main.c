#include "funcionario.c"  //.c compila gcc -o main main.c

#define MAX_FUNCIONARIO 10

int main() {

    Funcionario *VarFuncionario[10];

    // criando arquivo de texto para armazenar os dados dos funcionarios.
    FILE *arquivo = fopen("funcionario.txt", "w");
    if(arquivo == NULL) {
        exit(1);
    }

    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;
    
    char nome[50], cargo[50];
    int documento;

    int escolha, contador = 0, contador2 = 0, sair = 0;

    do {
        menu();
        scanf("%d", &escolha); 

        switch(escolha){
            case 1: // Cadastrando os dados na struct Funcionario.
                 do{
                        contador2++;
                        printf("FUNCIONARIO %i \n", contador2);
                        printf("INFORME SEU NOME: ");
                        scanf(" %[^\n]", nome);

                        printf("INFORME SEU CARGO: ");
                        scanf(" %[^\n]", cargo);

                        printf("INFORME SEU DOCUMENTO: ");
                        scanf("%d", &documento);

                        VarFuncionario[contador] = CriarFuncionario(nome, cargo, documento);

                        printf(" CONTINUAR CADASTRANDO (1) SIM / (2) NAO ");
                        scanf("%d", &sair);

                        if(sair != 1 && sair != 2) {
                            while(sair != 1 && sair != 2) { 
                                printf(" VOCE DIGITOU UM NUMERO INCORETO! \n");
                                printf("CONTINUAR CADASTRANDO (1) SIM / (2) NAO: \n");
                                scanf("%d", &sair);
                            }
                        }
                        if(contador == MAX_FUNCIONARIO) {
                            printf("LIMITE DE CADASTRO ATINGIDO! \n");
                            exit(1);
                        }    
                        contador++;

                 } while(sair != 2 && contador != 10);
        
                break;

            case 2: // Listando os dados do arquivo. 
                printf("NADA AINDA! ");

                break;

            case 3: // Fechando o programa.
                printf("OBRIGADO POR USAR O PROGRAMA! \n");
                printf("SAINDO... ");
                exit(1);

                break;

            default:
                printf("NUMERO ERRADO! TENTE NOVAMENTE! \n");
        }
        
    } while(escolha != 3);

    // Passando os dados para a função bublleSort.
    bubbleSort(vetor, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf(" ORDENANDO COM BUBBLE SORT ");

    clock_t inicio = clock();
       
    // Executar o algoritmo
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; //milisegundos
    printf("TEMPO DE EXECUCAO: %.50f\n", tempo);

    fclose(arquivo);
    
    return 0;
}