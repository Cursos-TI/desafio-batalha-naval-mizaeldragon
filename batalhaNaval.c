#include <stdio.h>

#define TAMANHO 10

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j] == 0 ? '~' : tabuleiro[i][j] == 3 ? 'N' : 'X');
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int padrao[5][5], int x, int y) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int px = x + i - 2, py = y + j - 2;
            if (px >= 0 && px < TAMANHO && py >= 0 && py < TAMANHO && padrao[i][j] && tabuleiro[px][py] != 3)
                tabuleiro[px][py] = 5;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    int padraoCone[5][5] = {
        {0,0,1,0,0}, 
        {0,1,1,1,0}, 
        {1,1,1,1,1}, 
        {0,0,0,0,0}, 
        {0,0,0,0,0}
    };

    int padraoCruz[5][5] = {
        {0,0,1,0,0}, 
        {0,0,1,0,0}, 
        {1,1,1,1,1}, 
        {0,0,1,0,0}, 
        {0,0,1,0,0}
    };

    int padraoOctaedro[5][5] = {
        {0,0,1,0,0}, 
        {0,1,1,1,0}, 
        {1,1,1,1,1}, 
        {0,1,1,1,0}, 
        {0,0,1,0,0}
    };
    
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][4 + i] = tabuleiro[5 + i][7] = tabuleiro[1 + i][1 + i] = tabuleiro[8 - i][1 + i] = 3;
    }
    
    aplicarHabilidade(tabuleiro, padraoCone, 4, 4);
    aplicarHabilidade(tabuleiro, padraoCruz, 6, 6);
    aplicarHabilidade(tabuleiro, padraoOctaedro, 7, 2);
    
    imprimirTabuleiro(tabuleiro);
    return 0;
}