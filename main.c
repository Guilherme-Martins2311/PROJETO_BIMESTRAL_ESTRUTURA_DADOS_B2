#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

int main() {
    Estrada *T1 = getEstrada("teste01.txt");

    if (T1 == NULL) {
        printf("❌ Erro ao carregar o arquivo teste01.txt\n");
        return 1;
    }

    double D1 = calcularMenorVizinhanca("teste01.txt");
    char *C1 = cidadeMenorVizinhanca("teste01.txt");

    printf("\n=== RESULTADOS DA ESTRADA DE WAKANDA ===\n");
    printf("Comprimento total da estrada: %d\n", T1->T);
    printf("Numero de cidades: %d\n", T1->N);
    printf("Menor vizinhanca: %.2lf km\n", D1);
    printf("Cidade com menor vizinhanca: %s\n", C1);
    printf("=========================================\n\n");

    free(C1);

    // Libera a memória das cidades
    Cidade *aux = T1->Inicio;
    while (aux) {
        Cidade *tmp = aux;
        aux = aux->Proximo;
        free(tmp);
    }
    free(T1);

    return 0;
}
