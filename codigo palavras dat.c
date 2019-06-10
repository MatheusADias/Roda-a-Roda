#include <stdio.h> // exit
#include <stdlib.h> // exit
#include <string.h>

typedef struct
{
	char pista[17], sorteio[17];
	int qtd;
	char vetpalavras[3][17];
} Jogo;
Jogo jogo[5];

int main(void)
{	

	int qtd, i,j;
	char url[] = "palavras.dat", pista[17], vetpalavras[3][17];
//  printf("*\n");

	FILE *arq = fopen(url, "r");
	if (arq == NULL)
	{
		printf("* erro, nao foi possivel abrir o arquivo\n");
//		printf("*\n");
 		exit(1);
	}
	
	for (j=0;j<5;j++)
	{
//primeiro faz a leitura do nome e da quantidade de palavras
		if (fscanf(arq,"%16s %d", pista, &qtd) != 2)
		{
//nao conseguiu ler os 2 campos

//é fim de arquivo ?

			if (feof(arq))
			{
			printf("* ok, fim de arquivo\n");
			} 
				else
				printf("* erro no conteudo do arquivo\n");
				printf("*");
				exit(0);
    	}

//neste ponto leu o nome e a quantidade de palavras

//agora vai ler as palavras

		if (qtd > 3)
		qtd = 3;

		for (i = 0; i < qtd; i++)
		{
			if (fscanf(arq, "%16s", vetpalavras[i]) != 1)
			{
				printf("* erro no conteudo do arquivo\n");
 //				printf("*\n");
 				exit(2);
      		}
    	}

//ok, leu as palavras

//		printf("* nome=%-10s qtd=%d", pista, qtd);

		for (i = 0; i < qtd; i++)
		{
//			printf(" %s", vetpalavras[i]);
			strcpy(jogo[j].vetpalavras[i], vetpalavras[i]);
			jogo[j].qtd=qtd;
			strcpy(jogo[j].pista, pista);
     
//			printf("\n\nTeste (%d):\n quantidade: %d\n pista: %s\n palavras:%s %s %s\n\n", j,jogo[j].qtd,jogo[j].pista,jogo[j].vetpalavras[0], jogo[j].vetpalavras[1], jogo[j].vetpalavras[2]);
//			printf("\n");
		}
	}

//o código a seguir é exatamente o que queriamos:
	int sorteio;

  	srand(time(NULL));
	sorteio = rand()%5;
	
	jogo[sorteio].vetpalavras[0];
		
	printf("\nPista: %s\nPalavras: %s %s %s\n\n", jogo[sorteio].pista, jogo[sorteio].vetpalavras[0], jogo[sorteio].vetpalavras[1], jogo[sorteio].vetpalavras[2]);

  	srand(time(NULL));
  	
//esse FOR a seguir é só para mostrar que o struct está funcionando corretamente:
  	
	for(j=0;j<5;j++)
	{
		for(i=0;i<3;i++)
		printf("linha: %d, coluna: %d, palavra: %s\n", j, i, jogo[j].vetpalavras[i]);
	
	printf("\n");
	}

	fclose(arq);
}

/*

Fiz essa lógica de forma separada do arquivo principal. Basicamente, para sortear uma palavra vc deve: rodar o sorteio que armazena um número aleatório de 0 a 5 (esse número corresponde a pista escolhida)
Depois, para saber as palavras correspondentes a essas pistas, use jogo[sorteio].vetpalavras[*0-2*] (0 a 2). Dá pra fazer um for aqui, mas achei desnecessário e meio complicado.

Agora, só falta colocar isso em uma função dentro do arquivo principal e fazer retornar a dica e as palavras.

*/
