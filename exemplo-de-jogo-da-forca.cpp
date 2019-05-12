#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <iostream>

using namespace std;

main(){
	char palavra[30],letra[1],secreta[30];
	int tam,i,chances,acertos;
	bool acerto;
	
	chances=6;
	tam=0;
	i=0;
	acerto=false;
	acertos=0;
	
	cout << "Insira palavra secreta: ";
	cin >> palavra;
	system("cls");
	
	while(palavra[i] != '\0') {
		i++;
		tam++;	
	}
	for(i=0;i<30;i++){
		secreta[i]='_';
	}
	
	while(chances > 0 && acertos < tam){
		cout << "Chances restantes: "<< chances << "\n\n";
		cout << "Palavra secreta> ";
		for(i=0; i<tam; i++){
			cout << secreta[i];
		}
		cout << "\n\nDigite uma letra: ";
		cin >> letra[0];
		for(i=0; i<tam; i++){
			if(palavra[i]==letra[0]){
				acerto=true;
				secreta[i]=palavra[i];
				acerto++;
			}
		}
		if(!acerto){
			chances--;
		}
		acerto=false;
		system("cls");
	}
	
	if(acertos==tam){
		cout << "Você venceu.";
	} else{
		cout << "Você perdeu";
	}
	system("pause");
}
