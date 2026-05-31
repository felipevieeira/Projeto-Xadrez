#include <stdio.h>
#include "funcoes.h"

int main() {
    char entrada[100] = "tcbdrbct-ppp1pppp-8-3p4-4R3-8-PPPPPPPP-TCBD1BCT";
    char matriz[8][8];
    int posicao[2];
    DivisaoStringForsyth(entrada, matriz);
    PrintMatriz(matriz);
    AcharRei(matriz, posicao);
    printf("posicao rei: %d, %d", posicao[0], posicao[1]);
    
}
