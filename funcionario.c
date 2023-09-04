#include "funcionario.h"

struct funcionario {
    char nome[50];
    char cargo[50];
    int documento;
};

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
    
    printf("==========MENU===========\n");
    printf("|\t(1) CADASTRAR\t|\n");
    printf("|\t(2) LISTAR\t|\n");
    printf("|\t(3) SAIR\t|\n");
    printf("=========================\n");
}

void Ordenar(FILE *arquivo, Funcionario **VarFuncionario, int tamanho) {
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
        //fprintf(arquivo, "%s\t%s\t%i\n", VarFuncionario[i]->nome, VarFuncionario[i]->cargo, VarFuncionario[i]->documento);
    }
}
void SalvarDados(FILE *arquivo, Funcionario **VarFuncionario, int contador) {
    
    /*
    // vai realocar o tamanho do vetor da struct.
    VarFuncionario=(Funcionario**)realloc(VarFuncionario, linhas*sizeof(Funcionario*));
    if(VarFuncionario==NULL){
    printf("erro na memoria!\n");
    }
   
    int i;
    // vai passar os dados para a struct.
    for(i=0;i<linhas;i++){
        fscanf(arquivo,"%s %s %i",VarFuncionario[i]->nome, VarFuncionario[i]->cargo, &VarFuncionario[i]->documento);

    }
    // vai printa na tela os funcionarios que estão no arquivo.
    for(i=0;i<linhas;i++){
        printf("%s\t%s\t%ls\n",VarFuncionario[i]->nome, VarFuncionario[i]->cargo, &VarFuncionario[i]->documento);
    }
    fclose(arquivo);
*/
    
    int i, j;

    Funcionario **temp;
    Funcionario **dados = NULL;
    int tamanho = 0;

    while (fscanf(arquivo, "%s\t%s\t%d\n", temp[contador]->nome, temp[contador]->cargo, &temp[contador]->documento) != EOF) {
        int duplicata = 0;

        // Verifica se o funcionário já existe na variável
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(temp[i]->nome, dados[i]->nome) == 0) {
                duplicata = 1;
                break;
            }
        }

        // Se não for uma duplicata, armazena o funcionário na variável
        if (!duplicata) {
            tamanho++;
            dados = realloc(dados, tamanho * sizeof(Funcionario *));
            dados[tamanho - 1] = malloc(sizeof(Funcionario));
            strcpy(dados[tamanho - 1]->nome, temp[tamanho]->nome);
            strcpy(dados[tamanho - 1]->cargo, temp[tamanho]->cargo);
            dados[tamanho - 1]->documento = temp[tamanho]->documento;
        }
        contador++;
    }

    VarFuncionario = dados;
    contador = tamanho;
    
    
}
void AdicionarNovosDados(Funcionario **VarFuncionario, int contador) {
    int tamanho = contador;
    Funcionario **dados = VarFuncionario;

    int duplicata = 0;

    // Verifica se o funcionário já existe na variável
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(VarFuncionario[i]->nome, dados[i]->nome) == 0) {
            duplicata = 1;
            break;
        }
    }

    // Se não for uma duplicata, adiciona o funcionário à variável
    if (!duplicata) {
        tamanho++;
        dados = realloc(dados, tamanho * sizeof(Funcionario *));
        dados[tamanho - 1] = malloc(sizeof(Funcionario));
        strcpy(dados[tamanho - 1]->nome, VarFuncionario[tamanho]->nome);
        strcpy(dados[tamanho - 1]->cargo, VarFuncionario[tamanho]->cargo);
        dados[tamanho - 1]->documento = VarFuncionario[tamanho]->documento;
    }

    VarFuncionario = dados;
    contador = tamanho;
}

void OrdenarEAtualizarArquivo(FILE *arquivo, Funcionario **VarFuncionario, int contador) {
    // Ordena os funcionários por nome (você pode usar sua função de ordenação)
    // Suponha que você tenha uma função de ordenação chamada OrdenarPorNome
    // Esta função não está definida aqui, você precisa implementá-la

    FILE *LerArquivo = fopen("funcionario.txt", "r");
    if(LerArquivo == NULL) {
        exit(1);
    }

    Ordenar(LerArquivo, VarFuncionario, contador);

    // Escreve os funcionários ordenados no arquivo
    fseek(arquivo, 0, SEEK_SET);
    for (int i = 0; i < contador; i++) {
        fprintf(arquivo, "%s %s %d\n", VarFuncionario[i]->nome, VarFuncionario[i]->cargo, VarFuncionario[i]->documento);
    }
}

void LimpaBuffer(Funcionario **VarFuncionario, int tamanho) {
    int i;

    for (int i = 0; i < tamanho; i++) {
        free(VarFuncionario[i]);
    }   
    free(VarFuncionario);

}
// Função que formata as strings.
void FormatarString(char*nomeF){
	
	int Inicial=1,i;// Inicial serve para identificar se a próxima letra é maiuscula.
	
	for(i=0;i<strlen(nomeF);i++){// Comparando o contador com otamalho da string.
        if(isspace(nomeF[i])){// Isspace identifica se a um espaço em branco na posiçao
            Inicial=1;
        }else if(Inicial){
		    nomeF[i]=toupper(nomeF[i]);// Toupper é a função que transforma a letra em maiuscula.
		    Inicial=0;
		}else {
		    nomeF[i]=tolower(nomeF[i]);// Tolower é a função que transforma a letra em minuscula.
		}
		
	}
	
}