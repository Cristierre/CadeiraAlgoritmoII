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

	/*for(indiceLinhas = 0 ; indiceLinhas < 8; indiceLinhas++){
		for(indiceColunas = 0 ; indiceColunas < 8; indiceColunas++){
			if(indiceLinhas <= 2 && tabuleiro[indiceLinhas][indiceColunas] == 0){
				tabuleiro[indiceLinhas][indiceColunas] = PECA_BRANCA;
			}else{
				if(indiceLinhas >= 5 && tabuleiro[indiceLinhas][indiceColunas] == 0){
					tabuleiro[indiceLinhas][indiceColunas] = PECA_PRETA;
				}
			}
		}
	}*/

	tabuleiro[0][0] = DAMA_PRETA;
	//tabuleiro[4][2] = PECA_BRANCA;
//	tabuleiro[5][1] = PECA_BRANCA;
	tabuleiro[1][1] = PECA_BRANCA;
	//tabuleiro[3][3] = PECA_BRANCA;
 	//tabuleiro[5][5] = PECA_BRANCA;
	//tabuleiro[6][2] = PECA_PRETA;

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

int damas(int tabuleiro[8][8], int linhaOrigem, int colunaOrigem, int dama, int pecaJoga){

	int linhaDestino;
	int colunaDestino;
	int linhaAtual = linhaOrigem;
	int colunaAtual = colunaOrigem;
	int ladoJogada = 0;
	int fimDaJogada = 0;
	int pecasNoCaminho = 0;

	int damaInimiga = 0;
	int pecaInimiga = 0;

    if(dama== DAMA_PRETA && pecaJoga == PECA_PRETA ){
        damaInimiga = DAMA_BRANCA;
        pecaInimiga = PECA_BRANCA;
    }else{
        damaInimiga = DAMA_PRETA;
        pecaInimiga = PECA_PRETA;
    }


	while(fimDaJogada == 0){

        printf("Jogador %d eh sua vez! \n\n", jogador);
        system("cls");
        posicionaPecas(tabuleiro);
        printf("Para qual linha deseja move a dama? \n");
        scanf("%d", &linhaDestino);

        printf("Para qual coluna deseja move a dama? \n");
        scanf("%d", &colunaDestino);
        system("cls");
        posicionaPecas(tabuleiro);

            fimDaJogada = 1;
        if(tabuleiro[linhaDestino][colunaDestino] == 0){

            if(linhaDestino != linhaOrigem && linhaDestino <= 7 && linhaDestino >= 0 && colunaDestino <= 7 && colunaDestino >= 0){
                    //jogada inferior esquerda
                    if(linhaDestino > linhaOrigem && colunaDestino < colunaOrigem && tabuleiro[linhaDestino][colunaDestino]==0){
                        while(linhaAtual < linhaDestino){
                            linhaAtual++;
                            colunaAtual--;

                            if(tabuleiro[linhaAtual][colunaAtual] != 0){
                                pecasNoCaminho++;
                            }else{
                                 if(tabuleiro[linhaDestino][colunaDestino] == 0 && pecasNoCaminho == 0){
                                    tabuleiro[linhaDestino][colunaDestino] = dama;
                                    tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                }
                            }

                        }

                        if(pecasNoCaminho == 1 && tabuleiro[linhaDestino-1][colunaDestino+1]==pecaInimiga || tabuleiro[linhaDestino-1][colunaDestino+1]==damaInimiga){
                            tabuleiro[linhaDestino][colunaDestino] = dama;
                            tabuleiro[linhaDestino-1][colunaDestino+1] = 0;
                            tabuleiro[linhaOrigem][colunaOrigem] = 0;



                            while(tabuleiro[linhaDestino+1][colunaDestino-1]==damaInimiga || tabuleiro[linhaDestino+1][colunaDestino-1] == pecaInimiga && tabuleiro[linhaDestino+2][colunaDestino-2] == 0){
                                linhaOrigem= linhaDestino;
                                colunaOrigem = colunaDestino;
                                tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                linhaDestino = linhaDestino + 2;
                                colunaDestino = colunaDestino - 2;
                                tabuleiro[linhaDestino][colunaDestino] = dama;
                                tabuleiro[linhaDestino-1][colunaDestino+1] = 0;

                            }
                        }else{
                            printf("JOGADA INVALIDA");
                            fimDaJogada = 0;
                        }
                    }else{
                        //jogada superior esquerda
                        if(linhaDestino < linhaOrigem && colunaDestino < colunaOrigem && tabuleiro[linhaDestino][colunaDestino]==0){

                             while(linhaAtual < linhaDestino){
                                linhaAtual--;
                                colunaAtual--;

                                if(tabuleiro[linhaAtual][colunaAtual] != 0){
                                    pecasNoCaminho++;
                                }else{
                                    if(tabuleiro[linhaDestino][colunaDestino] == 0 && pecasNoCaminho == 0){
                                        tabuleiro[linhaDestino][colunaDestino] = dama;
                                        tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                    }
                                }

                            }
                            if(pecasNoCaminho == 1 && tabuleiro[linhaDestino+1][colunaDestino+1]==pecaInimiga || tabuleiro[linhaDestino+1][colunaDestino+1]==damaInimiga){
                                tabuleiro[linhaDestino][colunaDestino] = dama;
                                tabuleiro[linhaDestino+1][colunaDestino+1] = 0;
                                tabuleiro[linhaOrigem][colunaOrigem] = 0;



                            while(tabuleiro[linhaDestino-1][colunaDestino-1]==damaInimiga || tabuleiro[linhaDestino-1][colunaDestino-1] == pecaInimiga && tabuleiro[linhaDestino-2][colunaDestino-2] == 0){
                                linhaOrigem= linhaDestino;
                                colunaOrigem = colunaDestino;
                                tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                linhaDestino -= 2;
                                colunaDestino -=  2;
                                tabuleiro[linhaDestino][colunaDestino] = dama;
                                tabuleiro[linhaDestino-1][colunaDestino-1] = 0;

                            }


                        }else{
                            if(pecasNoCaminho > 1){
                                system("cls");
                                printf("JOGADA INVALIDA 2\n");
                                fimDaJogada = 0;
                                pecasNoCaminho = 0;
                            }
                        }
                        }else{
                            //jogada superior direita
                           if(linhaDestino < linhaOrigem && colunaDestino > colunaOrigem && tabuleiro[linhaDestino][colunaDestino]==0){
                                printf("entrou 1");
                                system("cls");
                                while(linhaAtual > linhaDestino){
                                    linhaAtual--;
                                    colunaAtual++;

                                if(tabuleiro[linhaAtual][colunaAtual] != 0){
                                pecasNoCaminho++;
                                    }else{
                                        if(tabuleiro[linhaDestino][colunaDestino] == 0 && pecasNoCaminho == 0){
                                            tabuleiro[linhaDestino][colunaDestino] = dama;
                                            tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                        }
                                    }

                                }

                                if(pecasNoCaminho == 1 && tabuleiro[linhaDestino+1][colunaDestino-1]==pecaInimiga || tabuleiro[linhaDestino+1][colunaDestino-1]==damaInimiga){
                                    tabuleiro[linhaDestino][colunaDestino] = dama;
                                    tabuleiro[linhaDestino+1][colunaDestino-1] = 0;
                                    tabuleiro[linhaOrigem][colunaOrigem] = 0;


                                    while(tabuleiro[linhaDestino-1][colunaDestino+1]==damaInimiga || tabuleiro[linhaDestino-1][colunaDestino+1] == pecaInimiga && tabuleiro[linhaDestino-2][colunaDestino+2] == 0){
                                        linhaOrigem= linhaDestino;
                                        colunaOrigem = colunaDestino;
                                        tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                        linhaDestino -= 2;
                                        colunaDestino += 2;
                                        tabuleiro[linhaDestino][colunaDestino] = dama;
                                        tabuleiro[linhaDestino+1][colunaDestino-1] = 0;

                                    }
                                }else{
                                    printf("JOGADA INVALIDA");
                                    fimDaJogada = 0;
                                }
                            }else{
                                // jogada inferior direita
                                if(linhaDestino > linhaOrigem && colunaDestino > colunaOrigem && tabuleiro[linhaDestino][colunaDestino]==0){

                                     while(linhaAtual < linhaDestino){
                                        linhaAtual++;
                                        colunaAtual++;

                                        if(tabuleiro[linhaAtual][colunaAtual] != 0){
                                            pecasNoCaminho++;
                                        }else{
                                            if(tabuleiro[linhaDestino][colunaDestino] == 0 && pecasNoCaminho == 0){
                                                tabuleiro[linhaDestino][colunaDestino] = dama;
                                                tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                            }
                                        }

                                    }
                                    if(pecasNoCaminho == 1 && tabuleiro[linhaDestino-1][colunaDestino-1]==pecaInimiga || tabuleiro[linhaDestino-1][colunaDestino-1]==damaInimiga){
                                        tabuleiro[linhaDestino][colunaDestino] = dama;
                                        tabuleiro[linhaDestino-1][colunaDestino-1] = 0;
                                        tabuleiro[linhaOrigem][colunaOrigem] = 0;


                                    while(tabuleiro[linhaDestino+1][colunaDestino+1]==damaInimiga || tabuleiro[linhaDestino+1][colunaDestino+1] == pecaInimiga && tabuleiro[linhaDestino+2][colunaDestino+2] == 0){
                                        linhaOrigem= linhaDestino;
                                        colunaOrigem = colunaDestino;
                                        tabuleiro[linhaOrigem][colunaOrigem] = 0;
                                        linhaDestino += 2;
                                        colunaDestino += 2;
                                        tabuleiro[linhaDestino][colunaDestino] = dama;
                                        tabuleiro[linhaDestino-1][colunaDestino-1] = 0;

                                    }


                                }else{
                                    if(pecasNoCaminho > 1){
                                        system("cls");
                                        printf("JOGADA INVALIDA 2\n");
                                        fimDaJogada = 0;
                                        pecasNoCaminho = 0;
                                    }
                                }
                            }
                    }
                    }
                }
            }else{
                system("cls");
                printf("JOGADA INVALIDA 3\n");
                fimDaJogada = 0;
            }
        }else{
            system("cls");
            printf("JOGADA INVALIDA 4\n");
            fimDaJogada = 0;
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
	int pecasBrancasEliminadas = 1;
	int pecasPretasEliminadas = 1;
	int jogadaInvalida = 0;
	char novoJogo[1];
	int damaJoga = 0;



	//Laço que envolverá toda a regra do jogo, enquanto as peças estiverem abaixo de 12 o jogo continua;
	while(pecasPretasEliminadas > 0 || pecasBrancasEliminadas > 0){
            pecasBrancasEliminadas = 0;
            pecasPretasEliminadas = 0;
        system("cls");

		posicionaPecas(tabuleiro);
		turno();

		printf("Digite a linha da peca que deseja mover: \n");
		scanf("%d",&linhaOrigem);
		printf("Digite a coluna da peca que deseja mover: \n");
		scanf("%d",&colunaOrigem);

        if(tabuleiro[linhaOrigem][colunaOrigem] == DAMA_PRETA){
                damas(tabuleiro,linhaOrigem,colunaOrigem,DAMA_PRETA, PECA_PRETA);
                damaJoga = 1;
                jogador = !jogador;
                system("cls");

        }else{
             if(tabuleiro[linhaOrigem][colunaOrigem] == DAMA_BRANCA){
                damas(tabuleiro,linhaOrigem,colunaOrigem,DAMA_BRANCA, PECA_BRANCA);
                damaJoga = 1;
                jogador = !jogador;
                system("cls");
             }
        }
		if(jogador == 1 && damaJoga == 0){
            printf("Digite 1 para mover para a esquerda e 0 para mover para a direita! \n");
            scanf("%d", &jogada);

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
			if(jogador == 0 && damaJoga == 0){

                printf("Digite 1 para mover para a esquerda e 0 para mover para a direita! \n");
                scanf("%d", &jogada);

				if(jogada == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PECA_BRANCA && linhaOrigem +1 >= 0 && colunaOrigem -1 >= 0){
					if(tabuleiro[linhaOrigem+1][colunaOrigem-1] == 0){
						tabuleiro[linhaOrigem][colunaOrigem] = 0;
						tabuleiro[linhaOrigem+1][colunaOrigem-1] = PECA_BRANCA;
						jogador = 1;

					}else{
						if(tabuleiro[linhaOrigem+1][colunaOrigem-1] == PECA_PRETA && tabuleiro[linhaOrigem+2][colunaOrigem-2] == 0 && linhaOrigem +2 >= 0 && colunaOrigem -2 >= 0){
							while(tabuleiro[linhaOrigem+1][colunaOrigem-1] == PECA_PRETA && tabuleiro[linhaOrigem+2][colunaOrigem-2] == 0 && linhaOrigem + 2 <= 7){

								tabuleiro[linhaOrigem][colunaOrigem] = 0;
								tabuleiro[linhaOrigem+1][colunaOrigem-1] = 0;
								tabuleiro[linhaOrigem+2][colunaOrigem-2] = PECA_BRANCA;
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
            damaJoga = 0;

		}

		// ao final do laço é testada a variável jogadaInválida, para avisar o player a repetir a sua jogada

		if(jogadaInvalida == 1){
			system("cls");
			printf("JOGADA INVALIDA 3\n\n");
			jogadaInvalida = 0;
		}
		 for(indiceLinhas = 0; indiceLinhas <= 7; indiceLinhas++){
            for(indiceColunas = 0; indiceColunas <= 7; indiceColunas++){
                if(tabuleiro[indiceLinhas][indiceColunas] == PECA_BRANCA || tabuleiro[indiceLinhas][indiceColunas] == DAMA_BRANCA ){
                    pecasBrancasEliminadas++;
                }else{
                    if(tabuleiro[indiceLinhas][indiceColunas] == PECA_PRETA || tabuleiro[indiceLinhas][indiceColunas] == DAMA_PRETA ){
                        pecasPretasEliminadas++;
                    }
                }
            }
        }

	if(pecasPretasEliminadas == 0){
		system("cls");
		printf("JOGADOR 2 EH O GANHADOR!!!\n");
		posicionaPecas(tabuleiro);
		system("pause");
		break;
	}else{
		if(pecasBrancasEliminadas == 0){
			system("cls");
            printf("JOGADOR 1 EH O GANHADOR!!! \n");
            posicionaPecas(tabuleiro);
            system("pause");
            break;
        }
	}

	}



return 0;

}

















