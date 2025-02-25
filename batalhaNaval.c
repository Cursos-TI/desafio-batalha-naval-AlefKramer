#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10
#define NAVIO 3
#define TAM_NAVIO 3
#define TOTAL_NAVIOS 4

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se um navio pode ser posicionado sem sobreposição
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
        int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));
        
        if (x >= TAMANHO || y >= TAMANHO || tabuleiro[x][y] != 0) {
            return 0; // Não pode posicionar
        }
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int diagonal) {
    int linha, coluna, direcao;
    do {
        linha = rand() % TAMANHO;
        coluna = rand() % TAMANHO;
        direcao = rand() % 2; // 0 = horizontal, 1 = vertical
    } while (!podePosicionar(tabuleiro, linha, coluna, direcao, diagonal));

    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
        int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));
        tabuleiro[x][y] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    inicializarTabuleiro(tabuleiro);

    // Posiciona dois navios horizontais ou verticais
    for (int i = 0; i < 2; i++) {
        posicionarNavio(tabuleiro, 0);
    }

    // Posiciona dois navios diagonais
    for (int i = 0; i < 2; i++) {
    posicionarNavio(tabuleiro, 1);
    }

    imprimirTabuleiro(tabuleiro);
    return 0;
}


