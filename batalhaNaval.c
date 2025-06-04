#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HAB 5  // Tamanho das matrizes de habilidade

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// Exibe o tabuleiro com valores brutos: 0 (água), 3 (navio), 5 (habilidade)
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("    ");
    for (int i = 0; i < TAM; i++)
        printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i);
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Cria matriz de habilidade em forma de cone (5x5)
void criarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= 2 && j >= 2 - (i - 2) && j <= 2 + (i - 2))
                matriz[i][j] = 1;
            else if (i == 1 && j >= 1 && j <= 3)
                matriz[i][j] = 1;
            else if (i == 0 && j == 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade em forma de cruz (5x5)
void criarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

// Cria matriz de habilidade em forma de octaedro (5x5)
void criarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
        }
    }
}

// Aplica matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemLinha - offset + i;
            int coluna = origemColuna - offset + j;

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Posiciona quatro navios no tabuleiro
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio horizontal (linha 0)
    for (int i = 0; i < 3; i++)
        tabuleiro[0][i] = NAVIO;

    // Navio vertical (coluna 4)
    for (int i = 0; i < 3; i++)
        tabuleiro[i][4] = NAVIO;

    // Navio diagonal ↘
    for (int i = 0; i < 3; i++)
        tabuleiro[4 + i][4 + i] = NAVIO;

    // Navio diagonal ↙
    for (int i = 0; i < 3; i++)
        tabuleiro[6 + i][8 - i] = NAVIO;
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicar habilidades em pontos específicos
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    // Exibir o resultado final
    printf("=== TABULEIRO FINAL ===\n");
    printf("Legenda: 0 = água | 3 = navio | 5 = habilidade\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
