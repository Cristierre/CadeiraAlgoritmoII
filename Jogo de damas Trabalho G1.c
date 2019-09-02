#include <stdio.h>
#define A 3
#define B 4
 
int jogadorPecasBrancas = 1;

int main(){
	
	int tabuleiro[8][8] = {
		
	{A , 0 , A , 0 , A , 0 , A , 0},
	{0 , A , 0 , A , 0 , A , 0 , A},
	{1 , 0 , 1 , 0 , 1 , 0 , 1 , 0},
	{0 , 1 , 0 , 1 , 0 , 1 , 0 , 1},
	{1 , 0 , 1 , 0 , 1 , 0 , 1 , 0},
	{0 , 1 , 0 , 1 , 0 , 1 , 0 , 1},
	{B , 0 , B , 0 , B , 0 , B , 0},
	{0 , B , 0 , B , 0 , B , 0 , B},
	
	};
	
	turno(tabuleiro);
	
	printf("\n \n");
	printf("\n \n");

}
int turno(int tabuleiro[8][8]){
	
	
	if(jogadorPecasBrancas == 1){
		printf("Jogador 1 eh sua vez de jogar! \n \n");
		selecionaPeca(tabuleiro);
		movePeca(tabuleiro);
		jogadorPecasBrancas = 0;
		system("cls");
	}else{
		printf("Jogador 2 eh sua vez de jogar! \n \n");
		selecionaPeca(tabuleiro);
		movePeca(tabuleiro);
		jogadorPecasBrancas = 1;
		system("cls");
	}
	turno(tabuleiro);	
	
	return 0;
}


int posicionaPecas(int tabuleiro[8][8]){
	int i;
	int ii;

	for(i = 0; i < 8; i++){
		printf("%d | ",i);
		
		for(ii = 0; ii < 8; ii++){
			if(tabuleiro[i][ii] == A){
				printf("  A  ");
			}else{
				if(tabuleiro[i][ii] == B){
					printf("  B  ");
				}else{
					if(tabuleiro[i][ii] == 1){
						printf("  _  ");						
					}else{
						printf("  =  ");
					}
				}
			}
			
		};
		printf(" |");
		printf("\n \n");
	
	};	
	return 0;
}

int selecionaPeca(int tabuleiro[8][8]){
	
	int linhaOrg;
	int colunaOrg;
	
	
	int i;
	int ii;
	
	posicionaPecas(tabuleiro);
	printf("\n \n");
	
	printf("Digite a linha da peca que deseja mover: \n");
	scanf("%d", &linhaOrg);
	
	printf("Digite a coluna da peca que deseja mover: \n");
	scanf("%d", &colunaOrg);
	
	system("cls");
	
	for(i = 0; i < 8; i++){
		printf("%d | ",i);
		
		for(ii = 0; ii < 8; ii++){
			if(tabuleiro[linhaOrg][colunaOrg] == B && jogadorPecasBrancas == 1){
				tabuleiro[linhaOrg][colunaOrg] = 1;
			}else{	
				if(tabuleiro[linhaOrg][colunaOrg] == B && jogadorPecasBrancas == 0){
					system("cls");
					printf("Nao pode mexer a peca do adversario! \n \n");
					selecionaPeca(tabuleiro);
				}else{
					if(tabuleiro[linhaOrg][colunaOrg] == A && jogadorPecasBrancas == 0){
						tabuleiro[linhaOrg][colunaOrg] = 1;
					}else{
						if(tabuleiro[linhaOrg][colunaOrg] == A && jogadorPecasBrancas == 1){
							system("cls");
							printf("Nao pode mexer a peca do adversario! \n \n");
							selecionaPeca(tabuleiro);
						}
					}
				}				
			}
				
		};
		printf("\n \n");
	};
	posicionaPecas(tabuleiro);
	printf("\n \n");
	return 0;
}


int movePeca(int tabuleiro[8][8]){
		
	int linhaDest;
	int colunaDest;
	
	int i;
	int ii;
	
	posicionaPecas(tabuleiro);
	printf("\n \n");
		
	printf("Digite a linha para onde deseja mover a peca: \n");
	scanf("%d", &linhaDest);
	printf("Digite a coluna para onde deseja mover a peca: \n");
	scanf("%d", &colunaDest);		
	
	if((linhaDest+2 % 2 == 0 && colunaDest+2 % 2 == 0 && tabuleiro[linhaDest][colunaDest] + 2 % 2 == 0) || (linhaDest+2 % 2 == 1 && colunaDest+2 % 1 == 1 && tabuleiro[linhaDest][colunaDest] + 2 % 2 == 1)){
			if(tabuleiro[linhaDest][colunaDest] == 1 && jogadorPecasBrancas == 1){
				tabuleiro[linhaDest][colunaDest] = B;
				posicionaPecas(tabuleiro);
		}else{
			if(tabuleiro[linhaDest][colunaDest] == 1 && jogadorPecasBrancas == 0){
				tabuleiro[linhaDest][colunaDest] = A;
				posicionaPecas(tabuleiro);
			}
		}	
	}else{
		system("cls");
		printf("So eh possivel jogar nas casas pretas \n \n");
		movePeca(tabuleiro);
	}	

		posicionaPecas(tabuleiro);
		return 0;
}






