// Esse código gera um número aleatorio dos números do arquivo PREMIOS.DAT
// Está funcionando perfeitamente de maneira isolada, mas quando tento colocar no código principal sempre dá erro

#include <stdio.h>

int main(void)
{
 char url[]="PREMIOS.dat";
 float premio[12], valor;
 int i;
 FILE *arq;
 
 arq = fopen(url, "r"); // define arq como o arquivo premio.dat para somente ler
 if(arq == NULL) // teste de erro
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
 for(i=0;i<12;i++){ //cria um loop para armazenar cada valor de premio no vetor premio
if ((fscanf(arq, "%f\n", &premio[i])) == 1 ) // leia a explicacao no final do código
    srand(time(NULL));
	valor = premio[rand()%12];
}
 fclose(arq);

	printf("%.2f\n", valor);

 return 0;
}

// tentativa de colocar dentro de uma função:

/*

float premios()
{
 char url[]="PREMIOS.dat";
 float premio[12], valor;
 int i;
 FILE *arq;
 
 arq = fopen(url, "r");
 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
 for(i=0;i<12;i++){
if ((fscanf(arq, "%f\n", &premio[i])) == 1 )
    srand(time(NULL));
	valor = premio[rand()%12];
}
 fclose(arq);
 
 return valor;
}

*/

/*
A função fscanf serve para transformar uma linha de um arquivo em uma variável podendo ter varios formatos.
Foi a unica função que eu consegui fazer funcionar para ler esse arquivo como float

arq é o arquivo. %f é o tipo de dado da primeira linha e coluna do arquivo (se o arquivo fosse, por exemplo:
200 abc
dava pra ler usando fscanf(arq,%f %s\n) e daria para criar um loop para ler várias linhas). premio[i] é
o valor dos premios que serão armazenados. == 1 é para caso dê tudo certo na leitura (como se fosse um teste de erro).

depois disso acho que dá para entender.

falta adicionar esse código em uma função no arquivo principal
*/
