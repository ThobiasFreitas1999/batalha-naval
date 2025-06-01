#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define TAM_HAB 5

int tabuleiro[TAM][TAM] = {0};

void preencherNavios()
{
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
}

void imprimirTabuleiro()
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void aplicarHabilidade(int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna)
{
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (habilidade[i][j] == 1)
            {
                int linhaTab = origemLinha + i - TAM_HAB / 2;
                int colTab = origemColuna + j - TAM_HAB / 2;
                if (linhaTab >= 0 && linhaTab < TAM && colTab >= 0 && colTab < TAM && tabuleiro[linhaTab][colTab] != 3)
                {
                    tabuleiro[linhaTab][colTab] = 5;
                }
            }
        }
    }
}

void gerarCone(int matriz[TAM_HAB][TAM_HAB])
{
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            matriz[i][j] = (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) ? 1 : 0;
        }
    }
}

void gerarCruz(int matriz[TAM_HAB][TAM_HAB])
{
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            matriz[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }
}

void gerarOctaedro(int matriz[TAM_HAB][TAM_HAB])
{
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            matriz[i][j] = (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) ? 1 : 0;
        }
    }
}

int main()
{
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    preencherNavios();

    gerarCone(cone);
    aplicarHabilidade(cone, 1, 4);
    printf("Tabuleiro com Cone:\n");
    imprimirTabuleiro();

    preencherNavios();
    gerarCruz(cruz);
    aplicarHabilidade(cruz, 5, 5);
    printf("Tabuleiro com Cruz:\n");
    imprimirTabuleiro();

    preencherNavios();
    gerarOctaedro(octaedro);
    aplicarHabilidade(octaedro, 7, 7);
    printf("Tabuleiro com Octaedro:\n");
    imprimirTabuleiro();

    return 0;
}
