#include <stdio.h>
#define PECA_BRANCA 1
#define PECA_PRETA 2
#define CASA_BRANCA -1
#define CASA_PRETA 0
#define DAMA_BRANCA 3
#define DAMA_PRETA 4
						//Nome: Cristierre Gomes Konrath
		// O CÓDIGO FOI COMENTADO PARA AUXILIAR O MESTRE NA CORREÇÃO DO MESMO! 
		//condicionais do tipo da linha 150 estão se repitindo
int jogador = 1;

int main(){

	int tabuleiro[8][8];

	inicioDeJogo(tabuleiro);
	movePeca(tabuleiro);

}

//Função inicio seta as casas com os devidos valores para o tabuleiro
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

//Turno fica responsável por mudar o valor da variável global, para que se possa saber qual o jogador 
int turno(){
	if(jogador == 1){
		printf("Jogador 1 eh sua vez de jogar! \n \n");
	}else{
		printf("Jogador 2 eh sua vez de jogar! \n \n");
	}
	return 0;
}

//Função responsável por desenhar o tabuleiro com as peças correspondentes
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
					if(tabuleiro[indiceLinhas][indiceColunas] == DAMA_PRETA){
						printf(" DP ");
					}else{
						if(tabuleiro[indiceLinhas][indiceColunas] == DAMA_BRANCA){
						printf(" DB ");
						}else{
							if(tabuleiro[indiceLinhas][indiceColunas] == 0){
							printf("  -  ");
							}else{
								printf("  =  ");	
							}
						}
					}

				};
		

		};
	}
		printf(" |");
		printf("\n \n");
}
	return 0;
}

int damas(int tabuleiro[8][8], int linhaOrigem, int colunaOrigem, int dama){
	int linhaDestino;
	int colunaDestino;
	int linha;
	int coluna;	
	int jogadaInvalida = 0;
	//variáveis linha e coluna ja estão iterando sobre as casas, está redundante o que estou fazendo com colunaOrigem e linhaOrigem
	if(linhaDestino > linhaOrigem && colunaDestino > colunaOrigem){
		for(linha = linhaOrigem; linha >= 0; linha ++){
			
			for(coluna = colunaOrigem; coluna >= 0; coluna ++){
				
				if(tabuleiro[linha+1][coluna+1] != 0 && linha){
					
					if(tabuleiro[linha+1][coluna+1] == DAMA_PRETA && jogador == 1){
						
						while(linhaOrigem < linhaDestino){
							
							linhaOrigem++;
							colunaOrigem++;
							if(tabuleiro[linhaOrigem][colunaOrigem] != 0 && colunaOrigem < colunaDestino){
								printf("jogada inválida!");
							}
						}
					}
					
				}else{
					tabuleiro[linhaOrigem][colunaOrigem] == 0;
					while(linhaOrigem < linhaDestino){
						
						
						linhaOrigem++;
						colunaOrigem++;
					}					
				}
			}
		}
	}

	
	return 0;
}

//MovePeca é a função responsável pela partida, com os contadores de peças subtraídas de cada jogador e tratamentos para as jogadas válidas e inválidas
int movePeca(int tabuleiro[8][8]){

	int jogada;
	int linhaOrigem;
	int colunaOrigem;

	int indiceLinhas;
	int indiceColunas;
	int pecasBrancasEliminadas = 0;
	int pecasPretasEliminadas = 0;
	int jogadaInvalida = 0;
	char novoJogo[1];

	//Laço que envolverá toda a regra do jogo, enquanto as peças estiverem abaixo de 12 o jogo continua;
	while(pecasPretasEliminadas < 12 || pecasBrancasEliminadas < 12){

		posicionaPecas(tabuleiro);
		turno();
		
		printf("Digite a linha da peca que deseja mover: \n");
		scanf("%d",&linhaOrigem);
		printf("Digite a coluna da peca que deseja mover: \n");
		scanf("%d",&colunaOrigem);

		printf("Digite 1 para mover para a esquerda e 0 para mover para a direita! \n");
		scanf("%d", &jogada);
		
		if(jogador == 1){
			if(jogada == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_PRETA && linhaOrigem -1 >= 0 && colunaOrigem -1 >= 0){

					if(	tabuleiro[linhaOrigem-1][colunaOrigem-1] == 0){
						tabuleiro[linhaOrigem][colunaOrigem] = 0;
						tabuleiro[linhaOrigem-1][colunaOrigem-1] = PECA_PRETA;
						if(linhaOrigem -1 == 0){
							tabuleiro[linhaOrigem-1][colunaOrigem-1] = DAMA_PRETA;
						}
						jogador = 0;
					}else{
						if(tabuleiro[linhaOrigem-1][colunaOrigem-1] == PECA_BRANCA && tabuleiro[linhaOrigem-2][colunaOrigem-2] == 0 && linhaOrigem -2 >= 0 && colunaOrigem -2 >= 0){
							while(tabuleiro[linhaOrigem-1][colunaOrigem-1] == PECA_BRANCA && tabuleiro[linhaOrigem-2][colunaOrigem-2] == 0 && linhaOrigem - 2 >= 0){
							
								tabuleiro[linhaOrigem][colunaOrigem] = 0;
								tabuleiro[linhaOrigem - 1][colunaOrigem - 1] = 0;
								tabuleiro[linhaOrigem-2][colunaOrigem-2] = PECA_PRETA;
								pecasBrancasEliminadas++;
								linhaOrigem-= 2;
								colunaOrigem -= 2;
								
							}
							if(linhaOrigem == 0){
							tabuleiro[linhaOrigem][colunaOrigem] = DAMA_PRETA;
							}
								jogador = 0;
							
						}else{
							jogadaInvalida = 1;
						}
				}
				
            }else{
			if(jogada == 0 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_PRETA  && linhaOrigem -1 >= 0 && colunaOrigem +1 <= 7){
				if(	tabuleiro[linhaOrigem-1][colunaOrigem+1] == 0){

					tabuleiro[linhaOrigem][colunaOrigem] = 0;
					tabuleiro[linhaOrigem-1][colunaOrigem+1] = PECA_PRETA;
					jogador = 0;
					if(linhaOrigem -1 == 0){
						tabuleiro[linhaOrigem-1][colunaOrigem+1] = DAMA_PRETA;
					}
				}else{
					if(	tabuleiro[linhaOrigem-1][colunaOrigem+1] == PECA_BRANCA && tabuleiro[linhaOrigem-2][colunaOrigem+2] == 0  && linhaOrigem -2 >= 0 && colunaOrigem +2 <= 7){
						while(tabuleiro[linhaOrigem-1][colunaOrigem+1] == PECA_BRANCA && tabuleiro[linhaOrigem-2][colunaOrigem+2] == 0 && linhaOrigem - 2 >= 0){
							
							tabuleiro[linhaOrigem][colunaOrigem] = 0;
							tabuleiro[linhaOrigem-1][colunaOrigem+1] = 0;
							tabuleiro[linhaOrigem-2][colunaOrigem+2] = PECA_PRETA;
							pecasBrancasEliminadas++;
							linhaOrigem-= 2;
							colunaOrigem += 2;
							
						}
						if(linhaOrigem == 0){
							tabuleiro[linhaOrigem][colunaOrigem] = DAMA_PRETA;
						}
						jogador = 0;												
					}
				}

			}else{
				jogadaInvalida = 1;
			}
		}
            
		}else{
			if(jogador == 0){
				if(jogada == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_BRANCA && linhaOrigem +1 >= 0 && colunaOrigem -1 >= 0){
					if(tabuleiro[linhaOrigem+1][colunaOrigem-1] == 0){
	
						tabuleiro[linhaOrigem][colunaOrigem] = 0;
						tabuleiro[linhaOrigem+1][colunaOrigem-1] = PECA_BRANCA;
						if(linhaOrigem + 1 == 7){
							tabuleiro[linhaOrigem+1][colunaOrigem-1] = DAMA_BRANCA;
						}
						jogador = 1;

					}else{
						if(tabuleiro[linhaOrigem+1][colunaOrigem-1] == PECA_PRETA && tabuleiro[linhaOrigem+2][colunaOrigem-2] == 0 && linhaOrigem +2 >= 0 && colunaOrigem -2 >= 0){
							while(tabuleiro[linhaOrigem+1][colunaOrigem-1] == PECA_PRETA && tabuleiro[linhaOrigem+2][colunaOrigem-2] == 0 && linhaOrigem + 2 <= 7){
								
								tabuleiro[linhaOrigem][colunaOrigem] = 0;
								tabuleiro[linhaOrigem+1][colunaOrigem-1] = 0;
								tabuleiro[linhaOrigem+2][colunaOrigem-2] = PECA_BRANCA;
								pecasPretasEliminadas++;
								linhaOrigem+= 2;
								colunaOrigem -= 2;
								
							}
							if(linhaOrigem == 7){
								tabuleiro[linhaOrigem][colunaOrigem] = DAMA_BRANCA;
							}
								jogador = 1;
							

						}else{
							jogadaInvalida = 1;
						}
					}
				}else{
					if(jogada == 0 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_BRANCA && linhaOrigem +1 <= 7  && colunaOrigem +1 <= 7){
						if(tabuleiro[linhaOrigem+1][colunaOrigem+1] ==0){
                            tabuleiro[linhaOrigem][colunaOrigem] = 0;
                            tabuleiro[linhaOrigem+1][colunaOrigem+1] = PECA_BRANCA;
                           	if(linhaOrigem + 1 == 7){
								tabuleiro[linhaOrigem+1][colunaOrigem+1] = DAMA_BRANCA;
							}
							jogador = 1;
						}else{
                            if(tabuleiro[linhaOrigem+1][colunaOrigem+1] == PECA_PRETA && tabuleiro[linhaOrigem+2][colunaOrigem+2] == 0 && linhaOrigem +2 <= 7  && colunaOrigem +2 <= 7){
								while(tabuleiro[linhaOrigem+1][colunaOrigem+1] == PECA_PRETA && tabuleiro[linhaOrigem+2][colunaOrigem+2] == 0 && linhaOrigem + 2 <= 7){
									
									tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                	tabuleiro[linhaOrigem+1][colunaOrigem+1] = 0;
                                	tabuleiro[linhaOrigem+2][colunaOrigem+2] = PECA_BRANCA;
									pecasPretasEliminadas++;
									linhaOrigem+= 2;
									colunaOrigem += 2;
									
								}
								if(linhaOrigem == 7){
									tabuleiro[linhaOrigem][colunaOrigem] = DAMA_BRANCA;
								}
                                jogador = 1;
                               
						}
						}
					}else{
						jogadaInvalida = 1;
					}
				}
			}
		
			
		}
	
		// ao final do laço é testada a variável jogadaInválida, para avisar o player a repetir a sua jogada
		system("cls");
		if(jogadaInvalida == 1){
			system("cls");
			printf("JOGADA INVALIDA \n\n");
			jogadaInvalida = 0;
		}
	
	
	if(pecasPretasEliminadas == 12){
		system("cls");
		printf("JOGADOR 2 EH O GANHADOR!!!");
	}else{
		if(pecasBrancasEliminadas == 12){
			system("cls");
		printf("JOGADOR 1 EH O GANHADOR!!!");
			
		}
	}
	
	}
	
	printf("Novo jogo? S/N ");
	scanf("%s", &novoJogo);
	if(novoJogo == "S"){
		pecasPretasEliminadas = 0;
		pecasBrancasEliminadas = 0;
		inicioDeJogo(tabuleiro);
		
	}

return 0;

}


	



	










