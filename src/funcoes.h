#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdbool.h>

void DivisaoStringForsyth(char entrada[100], char matriz[8][8]);
void Condicionais(char entrada[100], char matriz[8][8], int i, int *j, int contador);
void PrintMatriz(char matriz[8][8]);
void AcharRei(char matriz[8][8], int PosicaoRei[2]);

bool AtaquePeao(char matriz[8][8], int PosicaoRei[2]);
bool AtaqueTorre(char matriz[8][8], int PosicaoRei[2]);
bool AtaqueBispo(char matriz[8][8], int PosicaoRei[2]);
bool AtaqueCavalo(char matriz[8][8], int PosicaoRei[2]);
bool AtaqueRainha(char matriz[8][8], int PosicaoRei[2]);

#endif