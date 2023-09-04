#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação para qsort
int compararStrings(const void *a, const void *b) {
    const char *strA = *(const char **)a;
    const char *strB = *(const char **)b;
    return strcmp(strA, strB);
}

// Função para ler e ordenar os nomes do arquivo
void lerEOrdenarNomes(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int tamanho = 0;
    int capacidade = 10; // Capacidade inicial do array
    char **strings = malloc(capacidade * sizeof(char *));

    if (strings == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return;
    }

    char novaString[100]; // Tamanho máximo da string

    while (fscanf(arquivo, "%s", novaString) != EOF) {
        // Aloca memória para armazenar a string
        strings[tamanho] = malloc(strlen(novaString) + 1);
        if (strings[tamanho] == NULL) {
            perror("Erro ao alocar memória");
            fclose(arquivo);
            return;
        }

        // Copia a string lida para o array de strings
        strcpy(strings[tamanho], novaString);
        tamanho++;

        // Redimensiona o array, se necessário
        if (tamanho == capacidade) {
            capacidade *= 2;
            strings = realloc(strings, capacidade * sizeof(char *));
            if (strings == NULL) {
                perror("Erro ao realocar memória");
                fclose(arquivo);
                return;
            }
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Ordena as strings usando a função qsort
    qsort(strings, tamanho, sizeof(char *), compararStrings);

    // Abre o arquivo para escrita (sobrescrevendo o conteúdo anterior)
    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    // Grava as strings ordenadas no arquivo
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%s\n", strings[i]);
        free(strings[i]);
    }
    
    // Fecha o arquivo novamente
    fclose(arquivo);

    // Libera a memória alocada
    free(strings);
}

int main() {
    char novaString[100];  // Tamanho máximo da string
    char nomeArquivo[] = "strings.txt";

    while (1) {
        printf("Digite uma nova string (ou -1 para sair): ");
        scanf("%s", novaString);

        if (strcmp(novaString, "-1") == 0) {
            break;
        }

        // Abre o arquivo para leitura e escrita
        FILE *arquivo = fopen(nomeArquivo, "a+");

        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo");
            return 1;
        }

        // Escreve a nova string no arquivo
        fprintf(arquivo, "%s\n", novaString);

        // Fecha o arquivo
        fclose(arquivo);

        // Chama a função para ler e ordenar os nomes
        lerEOrdenarNomes(nomeArquivo);
    }

    return 0;
}
