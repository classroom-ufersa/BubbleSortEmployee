#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Protótipo da struct funcionário.
typedef struct funcionario Funcionario; 

// Prototico da bubbleSort.
void bubbleSort(int *vetor, int tamanho);

// Protótipo da função da struct dinâmica
Funcionario *CriarFuncionario(char *nome, char *cargo, int documento);

// Prototico do menu.
void menu();