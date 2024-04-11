#include <stdio.h>
#include <stdlib.h>

#define MAX_REGISTROS 100

typedef struct {
    int quantidade;
    float preco;
} Produto;

int main() {
    FILE *arquivo = fopen("compras.txt", "r");
    if (arquivo == NULL) {
        exit(1);
    }

    Produto registros[MAX_REGISTROS];
    int total = 0;
    int numRegistros = 0;

    while (1) {
        if (fscanf(arquivo, "%*[^|]|%d|%f", &registros[numRegistros].quantidade, &registros[numRegistros].preco) != 2) {
            break;
        }

        total += registros[numRegistros].quantidade * registros[numRegistros].preco;
        numRegistros++;
    }

    fclose(arquivo);

    printf("Total da compra: %d\n", total);

    return 0;
}
