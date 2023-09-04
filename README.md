# Strings-com-Bubble-Sort
### Ordenação de Strings com Bubble Sort:

* A função Bubble Sort, é uma função utilizada para organizar uma sequência de números, strings e vários outros elementos, para deixar em uma certa ordem especifica. A função funciona examinando cada elementos na string, da esquerda para a direita, trocando suas posições se estiverem fora de ordem. Ou seja, ela verifica se o caracter ou número na sua frente tem um valor maior que o valor atual, se essa condição estiver verdadeira, a função troca as posições dos números ou caracteres.

 # como funciona o bubble sort:

 * O Bubble Sort realiza múltiplas passagem por uma lista. Ele compara itens adjacentes e troca aqueles que estão fora de ordem. Começando na primeira posição da lista, compara o primeiro elemento com o segundo elemento. Se o primeiro elemento for maior que o segundo, então se ocorre a troca, assim esse comando se repete até que os elementos fiquem ordenados.


![image](https://github.com/srlv/Strings-com-Bubble-Sort/assets/138056513/a9d6e402-8544-4d41-9567-1821ede94b14)

Imagem disponível em: <https://lh5.googleusercontent.com/_oLwPF5ZvaZZ4pGD-HvSUSw6nTwwHjUwcLpNigUvb24-PKNwjMUwXcWYWf2wp4HopzHkh9JVmZd_AFYP4HjSYelidbw4FRo1fHrWV3KxbFM13xlRLALb-y-EbLhEmln11lhwEZPV>

# Função Bubble Sort:

void bubbleSort(int *vetor, int tamanho) {<br>
    int i, j, aux;<br>
    for (i = 0; i < tamanho; i++) { <br>
        for (j = 0; j < tamanho - 1; j++) { <br>
            if (vetor[j] > vetor[j + 1]) { <br>
                aux = vetor[j]; <br>
                vetor[j] = vetor[j + 1]; <br>
                vetor[j + 1] = aux; <br>
            }<br>
        }<br>
    }<br>
}<br>

# Análise de complexidade do Bubble sort:
### resultado:

T(n) = (c3+c4c5+c6)(n²-n) + c2(n-1)+ c7*n + c1<br>
T(n) = (   an²-n  )        ( bn-1)  (cn)   (d)<br>
T(n) = an²-n + bn-n + cn + d<br>
T(n) =  O(n²)<br>


 Após a análise tem-se o resultado de que tanto no melhor caso quanto no pior caso o resultado final irá ser de:<br>
 T(n) = O(n²), pelo motivo de se ter dois laços de repetição onde um depende do outro.


# Vantagens e desvantagens do Bubble Sort:

* As das vantagens desse algoritmo é ser simples de entender e ser fácil de executar. 
 * A principal desvantagem é o fato de que não apresenta bons resultados quando o código contém muitos itens para serem organizados. 
