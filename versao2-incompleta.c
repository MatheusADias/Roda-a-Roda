/*
Relatório:
-Não sei como fazer o arquivo PALAVRAS.DAT, portanto estou desenvolvendo a lógica primeiro.
-É necessário organizar cada função em uma função separada, sem ser tudo no main. Estou com dificuldade nisso.
-Deve ter uma forma melhor de conectar as 5 dicas às 3 possíveis palavras
-Está dificil de ler
-Estou tentando descobrir a quantidade de caracteres
-Colocar variáveis dentro de funções específicas
-Tem que arrumar alguma forma de transformar a palavra escolhida em uma variável

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//void sorteio(char[], int);
float premios(float);


main(){

setlocale(LC_ALL, "Portuguese");

float jogador1=0, jogador2=0, jogador3=0;
int i, sorteio,sorteiopalavras,palavrasorteada, tamanho, rodar;
char vetpalavras[3][17]; //tem que ter isso
char pista[5][17] = {"Vegetal", "Automóvel", "Cozinha", "Réptil", "Mamífero"}, letraescolhida;

//forma que eu achei para conectar as 5 dicas às 3 palavras

char palavras1[3][17] = {"ACELGA", "ALFACE"};
char palavras2[3][17] = {"MOTOR", "EMBREAGEM", "ESCAPAMENTO"};
char palavras3[3][17] = {"PRATO", "PANELA", "ESCAPAMENTO"};
char palavras4[3][17] = {"JARARACA"};
char palavras5[3][17] = {"BALEIA", "MACACO"};

//sorteio

	srand(time(NULL)); // isso é necessário para usar a função rand
	sorteio = rand()%5; //sorteio recebe um num aleatório entre 0 e 5, que vai ser usado para sortear um vetor da matriz pista

	printf("\t\t\t\t\tA palavra está associada com: %s\n\n\0", pista[sorteio]);


//mostrar dinheiro dos jogadores

	printf("Jogador 1\tJogador 2\tJogador3\n");
	printf("==========\t==========\t==========\n");
	printf("%.2f\t\t%.2f\t\t%.2f\n",jogador1,jogador2,jogador3);


//associando a dica com as palavras. Tem que sortear as palavras, descobrir o tamanho de caract, e substituir por _.
	sorteiopalavras = rand()%2;

/*procurando uma forma de ler a quantidade de caracteres
	strcpy(palavras1[sorteiopalavras], palavrasorteada);
	printf("%s", palavrasorteada);
*/
if (sorteio == 0)
	printf("\n\t\t%s\n\0", palavras1[sorteiopalavras]);

 if (sorteio == 1)
	printf("\n\t\t%s\n\0", palavras2[sorteiopalavras]);

 if (sorteio == 2)
	printf("\n\t\t%s\n", palavras3[sorteiopalavras]);

 if (sorteio == 3)
	printf("\n\t\t%s\n", palavras4[sorteiopalavras]);

 if (sorteio == 4)
	printf("\n\t\t%s\n", palavras5[sorteiopalavras]);

/*
	printf("\nJogador 1\tJogador 2\tJogador3\n");
	printf("==========\t==========\t==========\n");
	printf("%.2f\t\t%.2f\t\t%.2f\n",jogador1,jogador2,jogador3);
*/

printf("rode a roda\n");
fflush(stdin);
scanf("%d", &rodar);

if (rodar == 1){
	printf("o valor deu %2.f\n", premios(rodar));
	if(premios(rodar) == 0)
		printf("passou a vez irmao\n");
	else if (premios(rodar) == 0.01)
		printf("perdeu tudo irmão");
	else {
		//criar outra função aqui
		
		printf("Uma letra por %.2f R$: ");
		fflush(stdin);
		scanf("%c", letraescolhida);
		
		
//		for(i=0;i<10;i++){
//			if(/*palavra[i]=='letraescolhida'*/)
//		}
		
		
	}
}


system("pause");
}

float premios(float valor){
	int sorteiovalor;
	float premios[12] = {100,900,600,1000,0,400,200,800,0.01,300,500,700};

	srand(time(NULL));
	sorteiovalor = rand()%12;
	valor = premios[sorteiovalor];

		return valor;
	
}


