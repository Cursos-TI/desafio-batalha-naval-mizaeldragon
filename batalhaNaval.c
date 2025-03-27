#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {

    printf("***TABULEIRO NAVAL***\n");
    
    int tabuleiro[10][10] = {0};
    int tamanhoNavio = 3;

    // colocar navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[2][4 + i] = 3;
    }

    // colocar navio vertical
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[5 + i][7] = 3;
    }

    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
