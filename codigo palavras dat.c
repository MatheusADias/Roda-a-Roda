#include <stdio.h> // exit
#include <stdlib.h> // exit

typedef struct
{
	char pista[17];
	int qtd;
	char vetpalavras[17];
} Teste;
Teste teste[5];

int main(void)
{	

  int qtd, i,j;
  char url[] = "palavras.dat", pista[17], vetpalavras[3][17];
  printf("*\n");

  FILE *arq = fopen(url, "r");
  if (arq == NULL)
  {
    printf("* erro, nao foi possivel abrir o arquivo\n");
    printf("*\n");
    exit(1);
  }

  for (;;)
  {
    // primeiro faz a leitura do nome e da quantidade de palavras
    if (fscanf(arq,"%16s %d", pista, &qtd) != 2)
    {
      // nao conseguiu ler os 2 campos

      // e' fim de arquivo ?
      if (feof(arq)){
        printf("* ok, fim de arquivo\n");

    }  else
        printf("* erro no conteudo do arquivo\n");

      printf("*");
      exit(0);
    }

    // neste ponto leu o nome e a quantidade de palavras

    // agora vai ler as palavras

    if (qtd > 3)
      qtd = 3;

    for (i = 0; i < qtd; i++)
    {
      if (fscanf(arq, "%16s", vetpalavras[i]) != 1)
      {
        printf("* erro no conteudo do arquivo\n");
        printf("*\n");
        exit(2);
      }
    }

    // ok, leu as palavras

    printf("* nome=%-10s qtd=%d", pista, qtd);

    for (i = 0; i < qtd; i++)
      printf(" %s", vetpalavras[i]);
    printf("\n");
  }

  fclose(arq);
}
