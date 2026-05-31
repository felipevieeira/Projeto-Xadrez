#include "funcoes.h"

int main() {
    char entrada[100] = "rnbqkbnr-pppppppp-8-8-8-8-PPPPPPPP-RNBQKBNR";
    char matriz[8][8];
    DivisaoStringForsyth(entrada, matriz);
    PrintMatriz(matriz);
}
