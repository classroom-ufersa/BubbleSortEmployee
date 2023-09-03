#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


// Protótipo da struct funcionário.
typedef struct funcionario Funcionario; 

// Protótipo da bubbleSort.
void bubbleSort(int *vetor, int tamanho);

// Protótipo da função da struct dinâmica.
Funcionario *CriarFuncionario(char *nome, char *cargo, int documento);

// Protótipo do menu.
void menu(); 

// Protótipo da função arquivo.
void arquivo(FILE *arquivo);

// Protótipo da função para ordernar.
void Ordenar(FILE *arquivo, Funcionario **VarFuncionario, int contador);

// Protótipo da função que faz a formatação das stings.
void FormatarString(char*nomeF);

void SalvarDados(FILE *arquivo, Funcionario **VarFuncionario, int contador);

void LimpaBuffer(Funcionario **VarFuncionario, int tamanho);