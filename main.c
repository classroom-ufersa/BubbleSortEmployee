#include "funcionario.c"  //.c compila gcc -o main main.c

int main() {
    //SalvarDados(arquivo2, &VarFuncionario, contador);
    int escolha, contador = 0, contador2 = 0, sair = 0;

    Funcionario **VarFuncionario = NULL;

    //FILE *arquivo = fopen("funcionario.txt", "w");
   
/*   
    FILE *arquivo2 = fopen("funcionario.txt", "r"); //colocar no main pra leitura
        if(arquivo2 == NULL) {
            printf("Erro ao abrir o arquivo! \n");
            exit(1);
        }
  */  

    FILE *arquivo = fopen("funcionario.txt", "a");
        if(arquivo == NULL) {
            exit(1);
        }

    char nome[50], cargo[50];
    int documento;

    do {
        menu();
        scanf("%d", &escolha); 

        switch(escolha){
            case 1: // Cadastrando os dados na struct Funcionario.
                 do{
                    arquivo = fopen("funcionario.txt", "a");
                    
                        contador++;
                        contador2++;
                        printf("FUNCIONARIO %i \n", contador2);
                        printf("Informe Seu Nome: ");
                        scanf(" %[^\n]", nome);

                        printf("Informe Seu Cargo: ");
                        scanf(" %[^\n]", cargo);

                        printf("Informe Seu Documento: ");
                        scanf("%d", &documento);

                        // Passando as strings para serem formatadas.
                        FormatarString(nome);
                        FormatarString(cargo);

                       /* VarFuncionario = (Funcionario**)realloc(VarFuncionario, contador * sizeof(Funcionario*));
                        if(VarFuncionario == NULL) {
                            printf("Erro ao alocar no main a variavel VarFuncionario! \n");
                            exit(1);
                        }

                        VarFuncionario[contador - 1] = *CriarFuncionario(nome, cargo, documento, contador);
                        */

                       Funcionario *NovoFuncionario = CriarFuncionario(nome, cargo, documento);

                        VarFuncionario = (Funcionario **)realloc(VarFuncionario, contador * sizeof(Funcionario *));
                            if (VarFuncionario == NULL) {
                                printf("Erro na realocação de memória.\n");
                                exit(1);
                            }

                        VarFuncionario[contador - 1] = NovoFuncionario;
                        
                        printf("Continuar Cadastrando (1) SIM / (2) NAO: ");
                        scanf("%d", &sair);

                        if(sair != 1 && sair != 2) {
                            while(sair != 1 && sair != 2) { 
                                printf("Voce digitou um numero incorreto! \n");
                                printf("Continuar cadastrando (1) SIM / (2) NAO: \n");
                                scanf("%d", &sair);
                            }
                        }  

                 } while(sair != 2);
        
                break;

            case 2: // Listando os dados do arquivo.  
                while(sair != 1) {
                    if(contador == 0) {
                        printf("Voce precisa fazer algum cadastro! \n");
                        printf("Digite 1 para sair! \n");
                        scanf("%d", &sair);
                    } else {
                        printf("Digite 1 para sair! \n");
                        scanf("%d", &sair);    //resolver o bug de entrar consecutivamente
                    }

                }
                    
                break;

            case 3: // Fechando o programa.
                printf("OBRIGADO POR USAR O PROGRAMA! \n");
                printf("SAINDO... \n");
                break;

            default:
                printf("\nNumero errado! Tente novamente! \n\n");
        }
    // Fazendo a ordenação no final do switch para assim a ordenação funcionar.
    Ordenar(arquivo, VarFuncionario, contador);
    printf("LISTA ATUALIZADA! \n");
    fclose(arquivo);
    // fclose(arquivo2);

    } while(escolha != 3);

    /* Passando os dados para a função bublleSort.
    bubbleSort(vetor, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("Ordenado com Bubble Sort ");
    */

    /*clock_t inicio = clock();
       
    // Executar o algoritmo
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; //milisegundos
    printf("Tempo de execucao: %.50f\n", tempo); */

    LimpaBuffer(VarFuncionario, contador);
    

    return 0;
}