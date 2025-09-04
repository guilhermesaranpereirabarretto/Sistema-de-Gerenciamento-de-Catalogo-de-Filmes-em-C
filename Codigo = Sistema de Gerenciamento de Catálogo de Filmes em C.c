#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Define um filme com os campos: nome(string), genero(string), Ano(int), duração(int)
typedef struct {
    char nome[100];
    char genero[50];
    int ano;
    int duracao;
} Filme;


void filmesMaisDeDuasHoras(Filme filmes[], int tamanho) {
    printf("\n--- Filmes com mais de 2 horas de duracao ---\n");
    for (int i = 0; i < tamanho; i++) {
        if (filmes[i].duracao > 120) {
            printf("- %s\n", filmes[i].nome);
        }
    }
}


void filmesMaisDeDezAnos(Filme filmes[], int tamanho) {
    int anoAtual = 2025;
    int count = 0;
    for (int i = 0; i < tamanho; i++) {
        if ((anoAtual - filmes[i].ano) > 10) {
            count++;
        }
    }
    printf("\n--- Quantidade de filmes com mais de 10 anos de lancamento ---\n");
    printf("%d filmes tem mais de 10 anos de lancamento.\n", count);
}


void filmeMaisAntigo(Filme filmes[], int tamanho) {
    if (tamanho == 0) {
        printf("\nNenhum filme para analisar.\n");
        return;
    }

    int indiceMaisAntigo = 0;
    for (int i = 1; i < tamanho; i++) {
        if (filmes[i].ano < filmes[indiceMaisAntigo].ano) {
            indiceMaisAntigo = i;
        }
    }
    printf("\n--- Filme mais antigo ---\n");
    printf("O filme mais antigo e: %s (Ano: %d)\n", filmes[indiceMaisAntigo].nome, filmes[indiceMaisAntigo].ano);
}
\\Test

int main() {
    Filme meusFilmes[5];


    printf("Por favor, insira os dados de 5 filmes:\n");
    for (int i = 0; i < 5; i++) {
        printf("\n--- Filme %d ---\n", i + 1);
        printf("Nome: ");

        fgets(meusFilmes[i].nome, sizeof(meusFilmes[i].nome), stdin);

        meusFilmes[i].nome[strcspn(meusFilmes[i].nome, "\n")] = 0;

        printf("Genero: ");
        fgets(meusFilmes[i].genero, sizeof(meusFilmes[i].genero), stdin);
        meusFilmes[i].genero[strcspn(meusFilmes[i].genero, "\n")] = 0;

        printf("Ano de Lancamento: ");
        scanf("%d", &meusFilmes[i].ano);

        printf("Duracao (em minutos): ");
        scanf("%d", &meusFilmes[i].duracao);


        while (getchar() != '\n');
    }


    printf("\n--- Informacoes dos Filmes Cadastrados ---\n");
    for (int i = 0; i < 5; i++) {
        printf("\nFilme %d:\n", i + 1);
        printf("  Nome: %s\n", meusFilmes[i].nome);
        printf("  Genero: %s\n", meusFilmes[i].genero);
        printf("  Ano: %d\n", meusFilmes[i].ano);
        printf("  Duracao: %d minutos\n", meusFilmes[i].duracao);
    }


    filmesMaisDeDuasHoras(meusFilmes, 5);
    filmesMaisDeDezAnos(meusFilmes, 5);
    filmeMaisAntigo(meusFilmes, 5);

    return 0;
}
