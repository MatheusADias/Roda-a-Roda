/*
Relatório:
-Não sei como fazer o arquivo PALAVRAS.DAT, portanto estou desenvolvendo a lógica primeiro.
-É necessário organizar cada função em uma função separada, sem ser tudo no main. Estou com dificuldade nisso.
-Deve ter uma forma melhor de conectar as 5 dicas às 3 possíveis palavras
-Está dificil de ler
-Estou tentando descobrir a quantidade de caracteres

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//void sorteio(char[], int);

main(){

setlocale(LC_ALL, "Portuguese");

float jogador1=0, jogador2=0, jogador3=0;
int i, sorteio,sorteiopalavras,palavrasorteada;
char vetpalavras[3][17]; //tem que ter isso
char pista[5][128] = {"Vegetal", "Automóvel", "Cozinha", "Réptil", "Mamífero"};

//forma que eu achei para conectar as 5 dicas às 3 palavras

char palavras1[3][17] = {"ACELGA", "ALFACE"};
char palavras2[3][17] = {"MOTOR", "EMBREAGEM", "ESCAPAMENTO"};
char palavras3[3][17] = {"PRATO", "PANELA", "ESCAPAMENTO"};
char palavras4[3][17] = {"JARARACA"};
char palavras5[3][17] = {"BALEIA", "MACACO"};

//sorteio

	srand(time(NULL)); // isso é necessário para usar a função rand
	sorteio = rand()%5; //sorteio recebe um num aleatório entre 0 e 5, que vai ser usado para sortear um vetor da matriz pista

	printf("\t\t\t\t\tA palavra está associada com: %s\n\n", pista[sorteio], sorteio);


//mostrar dinheiro dos jogadores

	printf("Jogador 1\n==========\n%.2f\n\n",jogador1);
	printf("Jogador 2\n==========\n%.2f\n\n",jogador2);
	printf("Jogador 3\n==========\n%.2f\n",jogador3);

//associando a dica com as palavras. Tem que sortear as palavras, descobrir o tamanho de caract, e substituir por _.

if (sorteio == 0){
	sorteiopalavras = rand()%2;
	printf("\nPalavra 1 (se cair um tem q ser vegetal): %s\n", palavras1[sorteiopalavras]);
	
	
//procurando uma forma de ler a quantidade de caracteres
//	strcpy(palavras1[sorteiopalavras], palavrasorteada);
//	printf("%s", palavrasorteada);

	}

system("pause");
}
