# Batalha Naval com Habilidades

Este projeto é uma versão do jogo Batalha Naval feita em linguagem C. O diferencial é que ele mostra como habilidades especiais (cone, cruz e octaedro) podem afetar o tabuleiro, marcando áreas com um símbolo diferente.

## O que o programa faz

- Cria um tabuleiro 10x10.
- Coloca um navio de 3 partes fixo no tabuleiro.
- Gera três padrões de habilidade: cone (triângulo), cruz e losango.
- Aplica cada habilidade no tabuleiro e mostra o resultado.
- Depois aplica as três habilidades ao mesmo tempo em posições diferentes.
- Mostra tudo no terminal com símbolos simples:
  - `~` = água
  - `N` = navio
  - `*` = área afetada pela habilidade
  - `?` = outro valor qualquer

## Como rodar

Compile com GCC:

```bash
gcc batalha_naval.c -o batalha_naval.exe
./batalha_naval.exe
