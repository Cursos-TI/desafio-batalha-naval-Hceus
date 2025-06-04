#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Valor para representar navio no tabuleiro
#define NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro na tela

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar o navio

int podePosicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {

        // Verifica se cabe horizontalmente

        if (coluna + TAMANHO_NAVIO > TAMANHO) return 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0)
                return 0; // Já tem algo aqui
        }
    } else if (orientacao == 'V') {
        // Verifica se cabe verticalmente

        if (linha + TAMANHO_NAVIO > TAMANHO) return 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0)
                return 0; // Já tem algo aqui
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas no código)

    int linhaH = 2, colunaH = 4;  // Navio horizontal
    int linhaV = 5, colunaV = 6;  // Navio vertical

    // Verifica se os navios podem ser posicionados corretamente

    if (podePosicionarNavio(tabuleiro, linhaH, colunaH, 'H')) {
        posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    if (podePosicionarNavio(tabuleiro, linhaV, colunaV, 'V')) {
        posicionarNavio(tabuleiro, linhaV, colunaV, 'V');
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro

    printf("\nTabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

