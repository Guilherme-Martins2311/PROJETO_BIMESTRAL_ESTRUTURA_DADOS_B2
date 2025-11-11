#ifndef CIDADES_H
#define CIDADES_H

typedef struct Cidade {
    char Nome[256];
    int Posicao;
    struct Cidade *Proximo;
} Cidade;

typedef struct {
    int N;
    int T;
    Cidade *Inicio;
} Estrada;

Estrada *getEstrada(const char *nomeArquivo);

double calcularMenorVizinhanca(const char *nomeArquivo);

char *cidadeMenorVizinhanca(const char *nomeArquivo);

#endif
