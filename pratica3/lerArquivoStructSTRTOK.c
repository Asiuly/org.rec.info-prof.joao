#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função para evitar repetição de código
verificaParticao(char *p){
    if(p==NULL){
            printf("erro em partir string");
            exit(1);
    }
}
int main(){
    //abrir arquivo compras txt
    FILE *file = fopen("compras.txt", "r");
    if(file == NULL){
        exit(1);
    }

    char linha[256];
    float total = 0;

    //lendo a linha inteira
    while(fgets(linha, sizeof(linha), file)){

        //strtok divide uma string baseada em um delimitador
        char *particao;

        //escrita antes do 1º | é o nome do produto
        particao = strtok(linha, "|");
        verificaParticao(particao);
        char *nomeProduto = particao;

        //escrita entre 1º e 2º | é a quantidade do produto
        particao = strtok(NULL, "|"); //com o NULL, ele continua de onde parou na ultima strtok
        verificaParticao(particao);
        int quantidade = atoi(particao); //conversão string para inteiro

        //escrita entre 2º e 3º | é o valor do produto
        particao = strtok(NULL, "|");
        verificaParticao(particao);
        float preco = atof(particao); //converão string para float

        float subTotal = quantidade * preco;
        total += subTotal;
    }

    //fechando arquivo
    fclose(file);

    printf("Total: %.2f\n", total);
    return 0;
}