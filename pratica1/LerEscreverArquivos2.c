#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE *file = fopen("notas.txt", "r");
    if(file == NULL){
        exit(1);
    }

    char nome[30], maiorNotaNome[30];
    float nota, maiorNota = 0, media=0;
    int cont=0;

    while(1){
        if((fscanf(file, "%*s%s%*s%f", nome, &nota))!= 2){
            break;
        }

        if(nota>maiorNota){
            maiorNota = nota;
            strcpy(maiorNotaNome, nome);
        }

        media+=nota;
        cont++;
        printf("%s\n", nome);
    }
    fclose(file);

    media /= cont;
    printf("media das notas = %f\n", media);
    printf("maior nome = %s\n", maiorNotaNome);
    
    return 0;
}