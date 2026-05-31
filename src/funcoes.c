#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"



//a funcao de Divisao vai passar caracter por caracter de uma string e verificar se o digito nao eh null terminator.
//tambem vai verificar se o caracter atual eh o divisor de linha (-), e enquanto nao for, vai entrar dentro da funcao
//de Condicional. se ele for o divisor de linhas, vai passar para a proxima linha e resetar o contador de colunas
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
//entra em um loop colocando um valor "nulo" nas colunas vazias correspondentes. o j tem que ser ponteiro pq ele tem que
//alterar a variavel original, o que nao aconteceria se ele nao fosse ponteiro
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



//print simples em todos os elementos da matriz
void PrintMatriz(char matriz[8][8]){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}



//funcao que percorre a matriz e devolve as posicoees i e j do rei
void AcharRei(char matriz[8][8], int PosicaoRei[2]){
    int i, j;
    for (i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if (matriz[i][j] == 'R'){
                PosicaoRei[0] = i, PosicaoRei[1] = j;
                return;
            }
        }
    }
}



//verifica se i>0, pq o rei na linha 0 nunca pode tomar xeque pra um peao. ele faz as duas verificacoes separadamente
//pra nao dar out of bounds (acessar o indice da esquerda quando j=0 ou o indice da direita quando j=7)
bool AtaquePeao(char matriz[8][8], int PosicaoRei[2]){
    int i = PosicaoRei[0], j = PosicaoRei[1];
    if (i > 0){
        if (j > 0 && matriz[i-1][j-1] == 'p'){
            return true;
        }
        if (j < 7 && matriz[i-1][j+1] == 'p') {
            return true;
        }
    }
    return false;
}