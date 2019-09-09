#include <stdio.h>
#define PECA_BRANCA 1
#define PECA_PRETA 2
#define CASA_BRANCA -1
#define CASA_PRETA 0 

int jogador = 1;

int main(){
	
	int tabuleiro[8][8];
	int indiceLinhas;
	int indiceColunas;
	
	inicioDeJogo(tabuleiro);
	movePeca(tabuleiro);
	

	printf("\n \n");
	printf("\n \n");

}
int inicioDeJogo(int tabuleiro[8][8]) {
	int indiceLinhas;
	int indiceColunas;
	int colunaInicio;
	
	for(indiceLinhas = 0 ; indiceLinhas < 8; indiceLinhas++){
		for(indiceColunas = 0 ; indiceColunas < 8; indiceColunas++){
			tabuleiro[indiceLinhas][indiceColunas] = 0;		
		}
	}
	
	for(indiceLinhas = 0 ; indiceLinhas < 8; indiceLinhas++){
		if(indiceColunas%2 == 0){
			colunaInicio = 1;
		}else{
			colunaInicio = 0;
		}
		for(indiceColunas = colunaInicio; indiceColunas < 8; indiceColunas+=2){
			tabuleiro[indiceLinhas][indiceColunas] = CASA_BRANCA;		
		}
	}
	
	for(indiceLinhas = 0 ; indiceLinhas < 8; indiceLinhas++){
		for(indiceColunas = 0 ; indiceColunas < 8; indiceColunas++){
			if(indiceLinhas <= 2 && tabuleiro[indiceLinhas][indiceColunas] == 0){
				tabuleiro[indiceLinhas][indiceColunas] = PECA_BRANCA;
			}else{
				if(indiceLinhas >= 5 && tabuleiro[indiceLinhas][indiceColunas] == 0){
					tabuleiro[indiceLinhas][indiceColunas] = PECA_PRETA;
				}
			}		
		}
	}
	return 0;
}
int turno(){	
	if(jogador == 1){
		printf("Jogador 1 eh sua vez de jogar! \n \n");
	}else{
		printf("Jogador 2 eh sua vez de jogar! \n \n");
	}	
	return 0;
}


int posicionaPecas(int tabuleiro[8][8]){
	int indiceLinhas = 0;
	int indiceColunas;
	printf("    ");
	while(indiceLinhas < 8){
		printf("  %d  ",indiceLinhas);
		indiceLinhas++;
	}
	printf("\n");
	printf("____________________________________________ \n \n");
	for(indiceLinhas = 0; indiceLinhas < 8; indiceLinhas++){
		printf("%d | ",indiceLinhas);
		
		for(indiceColunas = 0; indiceColunas < 8; indiceColunas++){
			if(tabuleiro[indiceLinhas][indiceColunas] == PECA_BRANCA){
				printf("  A  ");
			}else{
				if(tabuleiro[indiceLinhas][indiceColunas] == PECA_PRETA){
					printf("  B  ");
				}else{
					if(tabuleiro[indiceLinhas][indiceColunas] == 0){
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
//Arrumar a jogada caso seja inválida
int movePeca(int tabuleiro[8][8]){
		
	int jogada;
	int linhaOrigem;
	int colunaOrigem;
	
	int indiceLinhas;
	int indiceColunas;
	int finDeJogo = 0;	
	int jogadaInvalida = 0;
		
	while(finDeJogo == 0){
	
		posicionaPecas(tabuleiro);
		turno();
		
		printf("Digite a linha da peca que deseja mover: \n");
		scanf("%d",&linhaOrigem);
		printf("Digite a coluna da peca que deseja mover: \n");
		scanf("%d",&colunaOrigem);
		
		printf("Digite 1 para mover para a esquerda e 0 para mover para a direita! \n");
		scanf("%d", &jogada);
		if(jogador == 1){
			if(jogada == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_PRETA){
					
					if(	tabuleiro[linhaOrigem-1][colunaOrigem-1] == 0){
						tabuleiro[linhaOrigem][colunaOrigem] = 0;
						tabuleiro[linhaOrigem-1][colunaOrigem-1] = PECA_PRETA;
						jogador = 0;
						jogadaInvalida = 0;						
					}else{
						if(tabuleiro[linhaOrigem-1][colunaOrigem-1] == PECA_BRANCA && tabuleiro[linhaOrigem-2][colunaOrigem-2] == 0){
							tabuleiro[linhaOrigem][colunaOrigem] = 0;
							tabuleiro[linhaOrigem-2][colunaOrigem-2] = PECA_PRETA;
							jogador = 0;	
							jogadaInvalida = 0;						
						}else{
							if(jogada == 0 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_PRETA){
								if(	tabuleiro[linhaOrigem-1][colunaOrigem+1] == 0){
									tabuleiro[linhaOrigem][colunaOrigem] = 0;
									tabuleiro[linhaOrigem-1][colunaOrigem+1] = PECA_PRETA;
									jogador = 0;						
									jogadaInvalida = 0;	
								}else{
									if(	tabuleiro[linhaOrigem-1][colunaOrigem+1] != PECA_BRANCA && tabuleiro[linhaOrigem-1][colunaOrigem+1] == 0){
										tabuleiro[linhaOrigem][colunaOrigem] = 0;
										tabuleiro[linhaOrigem-1][colunaOrigem+2] = PECA_PRETA;
										jogador = 0;
										jogadaInvalida = 0;						
									}else{
										jogadaInvalida = 1;
									}
								}
							}
						}
					}
				}else{
					jogadaInvalida = 1;
				}
		}else{
			if(jogador == 0){
				if(jogada == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_BRANCA){
					if(tabuleiro[linhaOrigem+1][colunaOrigem-1] != PECA_BRANCA &&tabuleiro[linhaOrigem+1][colunaOrigem-1] != PECA_PRETA){
						tabuleiro[linhaOrigem][colunaOrigem] = 0;
						tabuleiro[linhaOrigem+1][colunaOrigem-1] = PECA_BRANCA;	// testar destino aqui 
						jogador = 1;
						jogadaInvalida = 0;
					}else{
						if(tabuleiro[linhaOrigem+1][colunaOrigem-1] == PECA_PRETA && tabuleiro[linhaOrigem+2][colunaOrigem-2] != PECA_PRETA)
						if(jogada == 0 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_BRANCA){
							tabuleiro[linhaOrigem][colunaOrigem] = 0;
							tabuleiro[linhaOrigem+1][colunaOrigem+1] = PECA_BRANCA;
							jogador = 1;
						}else{
					jogadaInvalida = 1;
					}
				}	
			}
		}
	}
}
}






