#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"



//a funcao de Divisao vai passar caracter por caracter de uma string e verificar se o digito nao eh null terminator,
//e enquanto nao for, vai verificar se o caracter eh diferente do divisor de linhas (-)
//enquanto nao for divisor de linhas, vai para a funcao de Condicional, que faz as verificacoes para transcrever a
//notacao forsyth para uma matriz
//a funcao sempre ajusta os indices i(linha) e j(coluna) para preencher a matriz corretamente
void DivisaoStringForsyth(char entrada[100], char matriz[8][8]) {
    int i = 0, j = 0, contador = 0;
    for (contador = 0; entrada[contador] != '\0'; contador++) {
        if (entrada[contador] != '-') {
            Condicionais(entrada, matriz, i, &j, contador);
        }
        else {
            i++;
            j = 0;
        }
    }
}


//a funcao de Condicional verifica se o caracter eh um numero ou uma letra. se for uma letra, ele a salva na posicao
//atual da matriz e passa pra proxima coluna. se for um digito, ele primeiramente converte o char em um int e depois
//entra em um loop colocando um valor "nulo" nas colunas vazias correspondentes
void Condicionais(char entrada[100], char matriz[8][8], int i, int *j, int contador) {
    if (!isdigit(entrada[contador])) {
        matriz[i][*j] = entrada[contador];
        (*j)++;
    }
    else {
        int numero = entrada[contador] - '0';
        while (numero > 0) {
            matriz[i][*j] = ' ';
            (*j)++;
            numero--;
        }
    }
}

void PrintMatriz(char matriz[8][8]){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}