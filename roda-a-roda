#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

typedef struct
{
	char pista[17];
	int qtd;
	char vetpalavras[3][17];
	char descpalavras[3][17];
	char descpalavrasFinal[3][17];
} Jogo;

Jogo ler_jogo(void);
void ler_premios(float[]);
float sorteia_premios(float[]);
int prepara(Jogo*);
void placar (Jogo,float[], int);
int verificaLetra (Jogo*, char);
int verificaPalavra (Jogo);

int main(){
	float placarjogador[3]= {0,0,0}, rodar, premios[12];
	int i=0, j, totalLetras, acerto, totalAcertos=0, contFinal=0, vencedor=-1;
	char letraescolhida;
	Jogo jogo;
	
	jogo = ler_jogo();
	totalLetras = prepara(&jogo);
	ler_premios(premios);
	
	do {
		placar(jogo,placarjogador,vencedor);	
		printf("\nJogador %d: Rode a roda!", i+1);
	  	fflush(stdin);
		getchar();
		rodar = sorteia_premios(premios);

		if (rodar == 0){
			printf("\nPassa a vez!\n");
			i = (i+1)%3; //vai para próximo jogador
      		printf("A vez sera passada para o jogador %d.\nPressione qualquer tecla.", i+1);
      		fflush(stdin);
			getchar(); //espera o usuario clicar em qualquer tecla
		}
	
		else if(rodar == 0.01f){
			printf("\nPerdeu tudo!\nPressione qualquer tecla.");
			placarjogador[i] = 0; //zerar placar do jogador ativo
			i = (i+1)%3; //vai para próximo jogador
			fflush(stdin);
			getchar(); 
		}
		else { 
			do{ //perguntar letra até o usuário digitar um caracter válido
				printf("Uma letra por R$%.2f: ", rodar);
				fflush(stdin);
				scanf("%c", &letraescolhida);
				
			} while ( letraescolhida < 'A' || ( letraescolhida > 'Z' && letraescolhida < 'a' ) || letraescolhida > 'z' ); 
			
			if ( letraescolhida >= 'a' && letraescolhida <= 'z') letraescolhida -= 32;
			
			acerto = verificaLetra (&jogo, letraescolhida); 
      
			if (acerto>0) {
				placarjogador[i] = placarjogador[i] + rodar*acerto;
				totalAcertos += acerto; //armazena total de caracteres descobertos
				if ( totalLetras - totalAcertos == 0 ){ //jogador venceu antes da rodada final
							vencedor = i;
							system("cls");
							placar (jogo, placarjogador, vencedor );
							return 0;
				}
			}
			else if (acerto == -1){
        		i = (i+1)%3;//vai para próximo jogador
        		printf("\nA letra %c ja foi descoberta.\nA vez sera passada para o jogador %d.\n\nPressione qualquer tecla.", letraescolhida, i+1);
        		fflush(stdin);
				getchar(); //espera o usuario clicar em qualquer tecla
     		}
			else{
        		i = (i+1)%3;//vai para próximo jogador
        		printf("\nNao existe letra %c na palavra.\nA vez sera passada para o jogador %d.\n\nPressione qualquer tecla.", letraescolhida, i+1);
        		fflush(stdin);
				getchar(); //espera o usuario clicar em qualquer tecla
			}
		}
      	system("cls"); //limpa a tela
	} while ( totalLetras > totalAcertos + 3 );

	do{ //rodada final
	placar(jogo,placarjogador,vencedor);	
	printf("\nJogador %d: Rode a roda!", i+1);
	fflush(stdin);
	getchar();
	do		rodar = sorteia_premios(premios); //não aceita 'passa a vez' ou 'perde tudo' na última rodada
	while 	( rodar == 0.01f || rodar == 0 );
	printf("\nFalta(m) %d letra(s) para completar a palavra.\n", totalLetras-totalAcertos);
	printf("Voce tem 5 segundos para pensar e depois digitar a palavra...");
	for(j=5;j!=0; j--){ //contagem regressiva
		printf("%d...", j);
		Sleep(1000);
	} 
	printf("\n\nValendo R$ %.2f.\n", rodar+placarjogador[i]);
	acerto = verificaPalavra(jogo);
	if (acerto == 1){ //jogador ganhou
		vencedor = i;
		placarjogador[i] += rodar;
      	system("cls");
		placar (jogo, placarjogador, vencedor );
		return 1;
	}
	else{
		i = (i+1)%3;
		contFinal++;
	}
    system("cls");
	} while ( vencedor==-1 && contFinal<3 );
	
	placar (jogo, placarjogador, vencedor );
	printf("\nFim de jogo! Nao houve vencedor.\n");
		
	
return 2;
}

Jogo ler_jogo(void){	
	int qtd, i,j, sorteio;
	char pista[17], vetpalavras[3][17];
	Jogo jogo[5];
	FILE *arq;
	arq = fopen("PALAVRAS.dat", "r");
	if (arq == NULL)
	{
		printf("\nErro, nao foi possivel abrir o arquivo\n");
 		exit(1);
	}
	for (j=0;j<5;j++)
	{
		if (fscanf(arq,"%16s %d", pista, &qtd) != 2) //primeiro faz a leitura do nome e da quantidade de palavras
		{ //se nao conseguiu ler os 2 campos
			if (feof(arq)) //é fim do arquivo ?
				printf("* ok, fim de arquivo\n");
			else
				printf("\nErro no conteudo do arquivo\n");
			exit(0);
    	}
		for (i = 0; i < qtd; i++)
		{
			if (fscanf(arq, "%16s", vetpalavras[i]) != 1)
			{
				printf("\nErro no conteudo do arquivo\n");
 				exit(2);
      		}
    	}
		strcpy(jogo[j].pista, pista);
		jogo[j].qtd = qtd;
		for (i = 0; i < qtd; i++)
			strcpy(jogo[j].vetpalavras[i], vetpalavras[i]);
	}
  	srand(time(NULL));
	sorteio = rand()%5;
	fclose(arq);
	return jogo[sorteio];
}

void ler_premios(float premios[]){
	int i=0;
	FILE *arq;
	
	arq = fopen("PREMIOS.dat", "r"); // define arq como o arquivo premio.dat para somente ler
	if(arq == NULL) {
		printf("Erro, nao foi possivel abrir o arquivo\n");
		exit(2);
		}
	while ( i<12 ){
		fscanf(arq, "%f\n", &premios[i]);
		i++;
	}
	
	fclose(arq);
}

float sorteia_premios(float premios[]){ 
	float valor;
	srand(time(NULL));
	valor =  premios[rand()%12];
 	return valor;
}

int prepara(Jogo*jogo){ 
	int i, j, contagem=0, qtddLetras, qtddPalavras;
	qtddPalavras = (*jogo).qtd;
	for (i=0;i<qtddPalavras;i++) { //percorre todas as palavras
		qtddLetras = strlen((*jogo).vetpalavras[i]);
		for (j=0;j<qtddLetras;j++){ //percorre todas as letras até o tamanho de cada palavra
			(*jogo).descpalavras[i][j]='_';
			contagem++; //conta quantos caracteres existem no total das palavras
		}
	}
	return contagem;
}

void placar (Jogo jogo, float jog[], int iVencedor ){
	int i, j;
	printf("\n\t\tA dica eh: %s\n\n\t\t\t", jogo.pista);
	for (i=0; i<jogo.qtd; i++) {
		for (j=0;j<strlen(jogo.vetpalavras[i]);j++){
			if ( iVencedor == -1 ) printf(" %c ", jogo.descpalavras[i][j]); 
			else printf(" %c ", jogo.vetpalavras[i][j]); //caso alguem vença, imprime o vetor original
		}
		printf("\n\t\t\t");
	}
	printf("\n\nJogador 01\t\tJogador 02\t\tJogador 03\n");
	printf("==========\t\t==========\t\t==========\n");
	printf("R$%8.2f\t\tR$%8.2f\t\tR$%8.2f\n",jog[0],jog[1],jog[2]);
	switch (iVencedor){ //caso alguém vença o jogo
		case 0: printf(" VENCEDOR\n");
		break;
		case 1: printf("\t\t\t VENCEDOR\n");
		break;
		case 2: printf("\t\t\t\t\t\t VENCEDOR\n");
		break;
	}
}

int verificaLetra (Jogo *jogo, char letra){
	int i, j, acert=0;
	for (i=0; i<(*jogo).qtd ; i++){ //percorre todas as palavras
		for (j=0;j<strlen((*jogo).vetpalavras[i]);j++){ //percorre todas as letras até atingir o tamanho da palavra
    		if ((*jogo).descpalavras[i][j] == letra) return -1; //se a letra já foi descoberta, retorna -1
			else if ((*jogo).vetpalavras[i][j] == letra ) { //compara letra por letra da palavra original para ver se é igual
				(*jogo).descpalavras[i][j] = letra; //revela a letra na palavra descoberta
				acert++; //contagem para saber quantas letras foram descobertas
			} 
		}
	}
  return acert;
}

int verificaPalavra (Jogo jogo){
	int i, verif, acert=0;
	char palavrasFinal[3][17];
	for ( i=0 ; i<jogo.qtd ; i++ ){
		printf("A palavra %d eh: ", i+1);
		fflush(stdin);
		gets(palavrasFinal[i]);
		verif = strcmp ( strupr(palavrasFinal[i]),jogo.vetpalavras[i] );
		if ( verif == 0 ) acert++;
	}
	if ( acert == jogo.qtd ) return 1;
	else return 0;
}
