#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE_AFETADA 5

#define CHAR_AGUA '~'
#define CHAR_NAVIO 'N'
#define CHAR_HABILIDADE '*'
#define CHAR_DESCONHECIDO '?'

int tabuleiro[TAM][TAM];

// Preenche o tabuleiro com água
void limparMatriz(int matriz[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            matriz[i][j] = AGUA;
        }
    }
}

// Posiciona um navio de tamanho 3 como exemplo
void preencherNavios(int matriz[TAM][TAM])
{
    matriz[4][4] = NAVIO;
    matriz[4][5] = NAVIO;
    matriz[4][6] = NAVIO;
}

// Imprime o tabuleiro no console
void imprimirTabuleiro(int matriz[TAM][TAM])
{
    printf("\n");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            char c;
            if (matriz[i][j] == AGUA)
                c = CHAR_AGUA;
            else if (matriz[i][j] == NAVIO)
                c = CHAR_NAVIO;
            else if (matriz[i][j] == HABILIDADE_AFETADA)
                c = CHAR_HABILIDADE;
            else
                c = CHAR_DESCONHECIDO;
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("\n");
}

// Gera padrão de Cone
void gerarCone(int mat[TAM_HAB][TAM_HAB])
{
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (j >= centro - i && j <= centro + i)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
}

// Gera padrão de Cruz
void gerarCruz(int mat[TAM_HAB][TAM_HAB])
{
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (i == centro || j == centro)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
}

// Gera padrão de Octaedro ( losango )
void gerarOctaedro(int mat[TAM_HAB][TAM_HAB])
{
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (abs(i - centro) + abs(j - centro) <= centro)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
}

// Aplica matriz de habilidade centrada em ( origemLinha, origemColuna )
void aplicarHabilidade(int hab[TAM_HAB][TAM_HAB], int origL, int origC, int matTab[TAM][TAM])
{
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (hab[i][j] == 1)
            {
                int l = origL + i - offset;
                int c = origC + j - offset;
                if (l >= 0 && l < TAM && c >= 0 && c < TAM)
                {
                    matTab[l][c] = HABILIDADE_AFETADA;
                }
            }
        }
    }
}

int main()
{
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Mostra cada habilidade separadamente
    int origemL = 4, origemC = 5;
    printf("Tabuleiro Inicial (com navios):\n");
    limparMatriz(tabuleiro);
    preencherNavios(tabuleiro);
    imprimirTabuleiro(tabuleiro);

    printf("Tabuleiro com Habilidade Cone (Origem: L%d, C%d):\n", origemL, origemC);
    limparMatriz(tabuleiro);
    preencherNavios(tabuleiro);
    aplicarHabilidade(cone, origemL, origemC, tabuleiro);
    imprimirTabuleiro(tabuleiro);

    printf("Tabuleiro com Habilidade Cruz (Origem: L%d, C%d):\n", origemL, origemC);
    limparMatriz(tabuleiro);
    preencherNavios(tabuleiro);
    aplicarHabilidade(cruz, origemL, origemC, tabuleiro);
    imprimirTabuleiro(tabuleiro);

    printf("Tabuleiro com Habilidade Octaedro (Origem: L%d, C%d):\n", origemL, origemC);
    limparMatriz(tabuleiro);
    preencherNavios(tabuleiro);
    aplicarHabilidade(octaedro, origemL, origemC, tabuleiro);
    imprimirTabuleiro(tabuleiro);

    // Mostra as três habilidades separadas no mesmo tabuleiro usando origens diferentes
    int origConeL = 2, origConeC = 2;
    int origCruzL = 2, origCruzC = 7;
    int origOctL = 7, origOctC = 4;

    printf("Tabuleiro com Cone (L2,C2), Cruz (L2,C7) e Octaedro (L7,C4) separados:\n");
    limparMatriz(tabuleiro);
    preencherNavios(tabuleiro);
    aplicarHabilidade(cone, origConeL, origConeC, tabuleiro);
    aplicarHabilidade(cruz, origCruzL, origCruzC, tabuleiro);
    aplicarHabilidade(octaedro, origOctL, origOctC, tabuleiro);
    imprimirTabuleiro(tabuleiro);

    system("pause");
    return 0;
}
