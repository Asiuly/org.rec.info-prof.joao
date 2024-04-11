#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *file = fopen("compra.txt", "r");

    if(file == NULL){
        exit(1);
    }

    char nome[100];
    int quantidade;
    float preco, total=0;

    while(1){
        if(fscanf(file, "%s%d%f", nome, &quantidade, &preco) != 3){
            break;
        }

        total += preco * quantidade;
        printf("%s\n", nome);
    }
    
    fclose(file);
    printf("Total: R$%.2f\n", total);
    return 0;
}