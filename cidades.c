#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

int compararCidades(const void *a, const void *b) {
    Cidade *c1 = *(Cidade **)a;
    Cidade *c2 = *(Cidade **)b;
    return c1->Posicao - c2->Posicao;
}

Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (!arq) return NULL;

    Estrada *E = (Estrada *) malloc(sizeof(Estrada));
    if (!E) { fclose(arq); return NULL; }

    fscanf(arq, "%d", &E->T);
    fscanf(arq, "%d", &E->N);

    if (E->T < 3 || E->T > 1000000 || E->N < 2 || E->N > 10000) {
        fclose(arq); free(E); return NULL;
    }

    Cidade **vetorCidades = (Cidade **) malloc(E->N * sizeof(Cidade *));
    if (!vetorCidades) { fclose(arq); free(E); return NULL; }

    for (int i = 0; i < E->N; i++) {
        vetorCidades[i] = (Cidade *) malloc(sizeof(Cidade));
        fscanf(arq, "%d %255s", &vetorCidades[i]->Posicao, vetorCidades[i]->Nome);
        vetorCidades[i]->Proximo = NULL;

        if (vetorCidades[i]->Posicao <= 0 || vetorCidades[i]->Posicao >= E->T) {
            for (int j = 0; j <= i; j++) free(vetorCidades[j]);
            free(vetorCidades); free(E); fclose(arq); return NULL;
        }

        for (int j = 0; j < i; j++) {
            if (vetorCidades[j]->Posicao == vetorCidades[i]->Posicao) {
                for (int k = 0; k <= i; k++) free(vetorCidades[k]);
                free(vetorCidades); free(E); fclose(arq); return NULL;
            }
        }
    }

    fclose(arq);
    qsort(vetorCidades, E->N, sizeof(Cidade *), compararCidades);

    for (int i = 0; i < E->N - 1; i++)
        vetorCidades[i]->Proximo = vetorCidades[i + 1];
    vetorCidades[E->N - 1]->Proximo = NULL;
    E->Inicio = vetorCidades[0];

    free(vetorCidades);
    return E;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *E = getEstrada(nomeArquivo);
    if (!E) return -1.0;

    Cidade *cidades[E->N];
    Cidade *aux = E->Inicio;
    for (int i = 0; i < E->N; i++) {
        cidades[i] = aux;
        aux = aux->Proximo;
    }

    double menor = (double)E->T;
    for (int i = 0; i < E->N; i++) {
        double viz;
        if (i == 0)
            viz = (cidades[i + 1]->Posicao - cidades[i]->Posicao) / 2.0 + cidades[i]->Posicao;
        else if (i == E->N - 1)
            viz = (E->T - cidades[i]->Posicao) + (cidades[i]->Posicao - cidades[i - 1]->Posicao) / 2.0;
        else
            viz = (cidades[i + 1]->Posicao - cidades[i - 1]->Posicao) / 2.0;

        if (viz < menor) menor = viz;
    }

    aux = E->Inicio;
    while (aux) {
        Cidade *tmp = aux;
        aux = aux->Proximo;
        free(tmp);
    }
    free(E);
    return menor;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *E = getEstrada(nomeArquivo);
    if (!E) return NULL;

    Cidade *cidades[E->N];
    Cidade *aux = E->Inicio;
    for (int i = 0; i < E->N; i++) {
        cidades[i] = aux;
        aux = aux->Proximo;
    }

    double menor = (double)E->T;
    int indice = 0;
    for (int i = 0; i < E->N; i++) {
        double viz;
        if (i == 0)
            viz = (cidades[i + 1]->Posicao - cidades[i]->Posicao) / 2.0 + cidades[i]->Posicao;
        else if (i == E->N - 1)
            viz = (E->T - cidades[i]->Posicao) + (cidades[i]->Posicao - cidades[i - 1]->Posicao) / 2.0;
        else
            viz = (cidades[i + 1]->Posicao - cidades[i - 1]->Posicao) / 2.0;

        if (viz < menor) { menor = viz; indice = i; }
    }

    char *nome = (char *) malloc(strlen(cidades[indice]->Nome) + 1);
    strcpy(nome, cidades[indice]->Nome);

    aux = E->Inicio;
    while (aux) {
        Cidade *tmp = aux;
        aux = aux->Proximo;
        free(tmp);
    }
    free(E);
    return nome;
}
