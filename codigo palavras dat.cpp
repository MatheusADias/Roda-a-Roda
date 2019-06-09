#include <stdio.h>

int main(void)
{
 char url[]="PALAVRAS.dat", pista[17], palavras[17], palavras2[17], palavras3[17];
 int qtd;
 FILE *arq;
 
 arq = fopen(url, "r");
 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
  while( (fscanf(arq,"%s %d %s %s %s\n", pista, &qtd, palavras, palavras2, palavras3))!=EOF )
   printf("%s %d %s %s %s\n", pista, qtd, palavras, palavras2, palavras3);
 
 fclose(arq);
 
 return 0;
}
