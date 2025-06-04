#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("    ");
    for (int i = 0; i < TAMANHO; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d |", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Valida posicionamento horizontal/vertical
int podePosicionarHV(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + TAMANHO_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0)
                return 0;
        }
    } else if (orientacao == 'V') {
        if (linha + TAMANHO_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0)
                return 0;
        }
    }
    return 1;
}

void posicionarHV(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (orientacao == 'V') {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Valida e posiciona diagonal
int podePosicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i;
        int c = (direcao == 1) ? coluna + i : coluna - i;

        if (l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] != 0)
            return 0;
    }
    return 1;
}

void posicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i;
        int c = (direcao == 1) ? coluna + i : coluna - i;
        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Navio 1 - Horizontal em (0,0)
    if (podePosicionarHV(tabuleiro, 0, 0, 'H'))
        posicionarHV(tabuleiro, 0, 0, 'H');
    else
        printf("Erro ao posicionar navio 1 (horizontal).\n");

    // Navio 2 - Vertical em (0,4)
    if (podePosicionarHV(tabuleiro, 0, 4, 'V'))
        posicionarHV(tabuleiro, 0, 4, 'V');
    else
        printf("Erro ao posicionar navio 2 (vertical).\n");

    // Navio 3 - Diagonal principal (↘) em (4,4)
    if (podePosicionarDiagonal(tabuleiro, 4, 4, 1))
        posicionarDiagonal(tabuleiro, 4, 4, 1);
    else
        printf("Erro ao posicionar navio 3 (diagonal ↘).\n");

    // Navio 4 - Diagonal secundária (↙) em (6,8)
    if (podePosicionarDiagonal(tabuleiro, 6, 8, -1))
        posicionarDiagonal(tabuleiro, 6, 8, -1);
    else
        printf("Erro ao posicionar navio 4 (diagonal ↙).\n");

    // Exibe o tabuleiro final
    printf("\nTabuleiro final com 4 navios:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
