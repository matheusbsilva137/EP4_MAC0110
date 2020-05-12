#include<stdio.h>
/****************************************************************
    Nome: Matheus Barbosa Silva
    NUSP: 11221741

    Fonte e comentários: Para o campeonato, copie da linha 165 até a linha 319.

****************************************************************/

int podejogar (int tabuleiro[8][8], int cor, int l, int c){
    int laux, caux, contCercadas = 0, jogVal = 0;
    if(tabuleiro[l][c] != 0){
        return 0;
    }else if (l < 8 && c < 8){
        //verifica coluna - inferior
        for(contCercadas = 0, laux = l+1; jogVal == 0 && tabuleiro[laux][c] == -cor && laux < 8; laux++, contCercadas++);
        if(contCercadas > 0 && tabuleiro[laux][c] == cor && laux < 8 && jogVal == 0)
            jogVal = 1;

        //verifica coluna - superior
        for(contCercadas = 0, laux = l-1; jogVal == 0 && tabuleiro[laux][c] == -cor && laux >= 0; laux--, contCercadas++);
        if(contCercadas > 0 && tabuleiro[laux][c] == cor && laux >= 0 && jogVal == 0)
            jogVal = 1;

        //verifica linha - direita
        for(contCercadas = 0, caux = c+1; jogVal == 0 && tabuleiro[l][caux] == -cor && caux < 8; caux++, contCercadas++);
        if(contCercadas > 0 && tabuleiro[l][caux] == cor && caux < 8 && jogVal == 0)
            jogVal = 1;

        //verifica linha - esquerda
        for(contCercadas = 0, caux = c-1; jogVal == 0 && tabuleiro[l][caux] == -cor && caux >= 0; caux--, contCercadas++);
        if(contCercadas > 0 && tabuleiro[l][caux] == cor && caux >= 0 && jogVal == 0)
            jogVal = 1;

        //verifica diagonal principal - esquerda
        for(contCercadas = 0, caux = c-1, laux = l-1; jogVal == 0 && tabuleiro[laux][caux] == -cor && caux >= 0 && laux >= 0; caux--, laux--, contCercadas++);
        if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux >= 0 && laux >= 0 && jogVal == 0)
            jogVal = 1;

        //verifica diagonal principal - direita
        for(contCercadas = 0, caux = c+1, laux = l+1; jogVal == 0 && tabuleiro[laux][caux] == -cor && caux < 8 && laux < 8; caux++, laux++, contCercadas++);
        if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux < 8 && laux < 8 && jogVal == 0)
            jogVal = 1;

        //verifica diagonal secundaria - direita
        for(contCercadas = 0, caux = c+1, laux = l-1; jogVal == 0 && tabuleiro[laux][caux] == -cor && caux < 8 && laux >= 0; caux++, laux--, contCercadas++);
        if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux < 8 && laux >= 0 && jogVal == 0)
            jogVal = 1;

        //verifica diagonal secundaria - esquerda
        for(contCercadas = 0, caux = c-1, laux = l+1; jogVal == 0 && tabuleiro[laux][caux] == -cor && caux >= 0 && laux < 8; caux--, laux++, contCercadas++);
        if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux >= 0 && laux < 8 && jogVal == 0)
            jogVal = 1;
    }
    return jogVal;
}

void joga(int tabuleiro[8][8], int cor, int l, int c){
    int contCercadas = 0, laux, caux;
    tabuleiro[l][c] = cor;

    //ajustes do tabuleiro
    //altera coluna - inferior
    for(contCercadas = 0, laux = l+1; tabuleiro[laux][c] != 0 && tabuleiro[laux][c] != cor && laux < 8; laux++, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][c] == cor && laux < 8){
        for(laux = l+1; contCercadas > 0; laux++, contCercadas--)
            tabuleiro[laux][c] = cor;
    }

    //altera coluna - superior
    for(contCercadas = 0, laux = l-1; tabuleiro[laux][c] != 0 && tabuleiro[laux][c] != cor && laux >= 0; laux--, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][c] == cor && laux >= 0){
        for(laux = l-1; contCercadas > 0; laux--, contCercadas--)
            tabuleiro[laux][c] = cor;
    }

    //altera linha - direita
    for(contCercadas = 0, caux = c+1; tabuleiro[l][caux] != 0 && tabuleiro[l][caux] != cor && caux < 8; caux++, contCercadas++);
    if(contCercadas > 0 && tabuleiro[l][caux] == cor && caux < 8){
        for(caux = c+1; contCercadas > 0; caux++, contCercadas--)
            tabuleiro[l][caux] = cor;
    }

    //altera linha - esquerda
    for(contCercadas = 0, caux = c-1; tabuleiro[l][caux] != 0 && tabuleiro[l][caux] != cor && caux >= 0; caux--, contCercadas++);
    if(contCercadas > 0 && tabuleiro[l][caux] == cor && caux >= 0){
        for(caux = c-1; contCercadas > 0; caux--, contCercadas--)
            tabuleiro[l][caux] = cor;
    }

    //altera diagonal principal - esquerda
    for(contCercadas = 0, caux = c-1, laux = l-1; tabuleiro[laux][caux] != 0 && tabuleiro[laux][caux] != cor && caux >= 0 && laux >= 0; caux--, laux--, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux >= 0 && laux >= 0){
        for(caux = c-1, laux = l-1; contCercadas > 0; caux--, laux--, contCercadas--)
            tabuleiro[laux][caux] = cor;
    }

    //altera diagonal principal - direita
    for(contCercadas = 0, caux = c+1, laux = l+1; tabuleiro[laux][caux] != 0 && tabuleiro[laux][caux] != cor && caux < 8 && laux < 8; caux++, laux++, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux < 8 && laux < 8){
        for(caux = c+1, laux = l+1; contCercadas > 0; caux++, laux++, contCercadas--)
            tabuleiro[laux][caux] = cor;
    }

    //altera diagonal secundaria - direita
    for(contCercadas = 0, caux = c+1, laux = l-1; tabuleiro[laux][caux] != 0 && tabuleiro[laux][caux] != cor && caux < 8 && laux >= 0; caux++, laux--, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux < 8 && laux >= 0){
        for(caux = c+1, laux = l-1; contCercadas > 0; caux++, laux--, contCercadas--)
            tabuleiro[laux][caux] = cor;
    }

    //altera diagonal secundaria - esquerda
    for(contCercadas = 0, caux = c-1, laux = l+1; tabuleiro[laux][caux] != 0 && tabuleiro[laux][caux] != cor && caux >= 0 && laux < 8; caux--, laux++, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux >= 0 && laux < 8){
        for(caux = c-1, laux = l+1; contCercadas > 0; caux--, laux++, contCercadas--)
            tabuleiro[laux][caux] = cor;
    }  
}

void imprimeTabuleiro(int tabuleiro[8][8]){
    int i, j;
    printf("   0  1  2  3  4  5  6  7 \n");
    printf("  -------------------------\n");
    for( i = 0; i < 8; i++){
        printf("%d |", i);
        for( j = 0; j < 8; j++){
            if(tabuleiro[i][j] == -1){
                printf("* |");
            }else if (tabuleiro[i][j] == 1){
                printf("O |");
            }else{
                printf("  |");
            }
        }
        printf("\n");
        printf("  -------------------------\n");
    }
}

void contaPecas(int tabuleiro[8][8], int * b, int *p){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(tabuleiro[i][j] == -1){
                *p = *p + 1;
            }else if(tabuleiro[i][j] == 1){
                *b = *b + 1;
            }
        }
    }
}

int verificaJogadasValidas(int tabuleiro[8][8], int cor){
    int existeJogVal = 0, i, j;
    for(i = 0; i < 8 && existeJogVal == 0; i++){
        for(j = 0; j<8 && existeJogVal == 0; j++){
            if(tabuleiro[i][j] == 0 && podejogar(tabuleiro, cor, i, j)){
                existeJogVal = 1;
            }
        }
    }
    return existeJogVal;
}

/*************************** COPIE A PARTIR DAQUI **********************************************/
int pedrasAnt = 2, cercMaxAdv = 0, jogEstrategica = 0, jogMaxima = 0;

int contaCercadas(int tabuleiro[8][8], int cor, int l, int c){
    int laux, caux, contCercadas = 0, totCercadas = 0;
    //verifica coluna - inferior
    for(laux = l+1, contCercadas = 0; tabuleiro[laux][c] == -cor && laux < 8; laux++, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][c] == cor && laux < 8)
        totCercadas += contCercadas;

    //verifica coluna - superior
    for(laux = l-1, contCercadas = 0; tabuleiro[laux][c] == -cor && laux >= 0; laux--, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][c] == cor && laux >= 0)
        totCercadas += contCercadas;
    
    //verifica linha - direita
    for(caux = c+1, contCercadas = 0; tabuleiro[l][caux] == -cor && caux < 8; caux++, contCercadas++);
    if(contCercadas > 0 && tabuleiro[l][caux] == cor && caux < 8)
        totCercadas += contCercadas;

    //verifica linha - esquerda
    for(caux = c-1, contCercadas = 0; tabuleiro[l][caux] == -cor && caux >= 0; caux--, contCercadas++);
    if(contCercadas > 0 && tabuleiro[l][caux] == cor && caux >= 0)
        totCercadas += contCercadas;

    //verifica diagonal principal - esquerda
    for(caux = c-1, laux = l-1, contCercadas = 0; tabuleiro[laux][caux] == -cor && caux >= 0 && laux >= 0; caux--, laux--, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux >= 0 && laux >= 0)
        totCercadas += contCercadas;

    //verifica diagonal principal - direita
    for(caux = c+1, laux = l+1, contCercadas = 0; tabuleiro[laux][caux] == -cor && caux < 8 && laux < 8; caux++, laux++, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux < 8 && laux < 8)
        totCercadas += contCercadas;

    //verifica diagonal secundaria - direita
    for(caux = c+1, laux = l-1, contCercadas = 0; tabuleiro[laux][caux] == -cor && caux < 8 && laux >= 0; caux++, laux--, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux < 8 && laux >= 0)
        totCercadas += contCercadas;

    //verifica diagonal secundaria - esquerda
    for(caux = c-1, laux = l+1, contCercadas = 0; tabuleiro[laux][caux] == -cor && caux >= 0 && laux < 8; caux--, laux++, contCercadas++);
    if(contCercadas > 0 && tabuleiro[laux][caux] == cor && caux >= 0 && laux < 8 )
        totCercadas += contCercadas;

    return totCercadas;
}

void copiaTabuleiro(int tabOriginal[8][8], int tabCopia[8][8]){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            tabCopia[i][j] = tabOriginal[i][j];
        }
    }
}

void escolhejogada11221741(int tabuleiro[8][8], int cor, int *linha, int *coluna){
    int tabuleiroProjecao[8][8], i, j, r, s, t, u;
    int maiorCercamento = 0, proxMaiorCercamentoAdv = 0, proxMaiorCercamento = 0, proxCercamento, proxCercamentoAdv;
    int melhorLinha, melhorColuna, cercAtual, vantagem, maiorVantagem, it = 0, pedras = 0, pedrasAdv = 0;

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(tabuleiro[i][j] == cor){
                pedras++;
            }else if(tabuleiro[i][j] == -cor){
                pedrasAdv++;
            }
        }
    }
    
    if(pedrasAnt - cercMaxAdv == pedras){
        jogMaxima++;
    }else{
        jogEstrategica++;
    }

    //comparo a quantidade de pedras anterior do outro jogador com a quantidade atual
    //se a diferenca for menor que a quantidade maxima de cercamentos esperada,
    //tento capturar o maior numero possivel de pecas do outro jogador
    copiaTabuleiro(tabuleiro, tabuleiroProjecao);
    
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(tabuleiro[i][j] == 0 && podejogar(tabuleiro, cor, i, j)){
                it++;
                cercAtual = contaCercadas(tabuleiro, cor, i, j);

                if( it != 1 && jogMaxima >= jogEstrategica && pedrasAdv < pedras){
                    //simula quantas peças o proximo jogador pode cercar se jogar nesta posicao
                    joga(tabuleiroProjecao, cor, i, j);
                    for(r = 0; r < 8; r++){
                        for(s = 0; s < 8; s++){
                            proxCercamentoAdv = contaCercadas(tabuleiroProjecao, -cor, r, s);
                            if( proxCercamentoAdv > proxMaiorCercamentoAdv ){
                                proxMaiorCercamentoAdv = proxCercamentoAdv;
                                joga(tabuleiroProjecao, -cor, r, s);
                                for(t = 0; t < 8; t++){
                                    for(u = 0; u < 8; u++){
                                        proxCercamento += contaCercadas(tabuleiroProjecao, cor, t, u);
                                        if(proxCercamento > proxMaiorCercamento){
                                            proxMaiorCercamento = proxCercamento;
                                        }
                                    }
                                }
                                copiaTabuleiro(tabuleiro, tabuleiroProjecao);
                                joga(tabuleiroProjecao, cor, i, j);
                            }
                        }
                    }

                    vantagem = cercAtual - proxMaiorCercamentoAdv + proxMaiorCercamento;
                    if((vantagem > maiorVantagem && jogMaxima >= jogEstrategica) || it == 1 ){
                        melhorLinha = i;
                        melhorColuna = j;
                        maiorVantagem = vantagem;
                    }

                    copiaTabuleiro(tabuleiro, tabuleiroProjecao);
                }else{
                    if( cercAtual > maiorCercamento ){
                        //se o jogador costuma cercar o maximo que consegue das minhas pedras
                        //ou estou perdendo, cerco o maximo que posso dele para conquistar espaço.
                        maiorCercamento = cercAtual;
                        melhorLinha = i;
                        melhorColuna = j;
                    }
                }
            }
        }
    }

    //simula quantas peças o proximo jogador pode cercar ao jogar nesta posicao
    joga(tabuleiroProjecao, cor, melhorLinha, melhorColuna);
    proxMaiorCercamentoAdv = 0;
    pedrasAnt = 0;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(tabuleiroProjecao[i][j] == cor)
                pedrasAnt++;
            if(tabuleiroProjecao[i][j] == 0){
                proxCercamentoAdv = contaCercadas(tabuleiroProjecao, -cor, i, j);
                if( proxCercamentoAdv > proxMaiorCercamentoAdv ){
                    proxMaiorCercamentoAdv = proxCercamentoAdv;
                }
            }
        }
    }

    cercMaxAdv = proxMaiorCercamentoAdv;
    *linha = melhorLinha;
    *coluna = melhorColuna;
}
/*************************** COPIE ATÉ AQUI *****************************************************/

int main(){
    int tabuleiro[8][8], l, c, jog = -1, i, j, brancas = 0, pretas = 0, fimDeJogo = 0;
    for( i = 0; i < 8; i++){
        for( j = 0; j < 8; j++){
            tabuleiro[i][j] = 0;
        }
    }
    tabuleiro[3][3] = 1; tabuleiro [3][4] = -1;
    tabuleiro[4][3] = -1; tabuleiro [4][4] = 1;
    printf("*****TABULEIRO INICIAL*****\n");
    imprimeTabuleiro(tabuleiro);

    while((verificaJogadasValidas(tabuleiro, jog) == 1 || verificaJogadasValidas(tabuleiro, -jog) == 1) && !fimDeJogo){
        if(verificaJogadasValidas(tabuleiro, jog) == 1){
            if(jog == -1){
                printf("\nTurno do jogador Preto!\n");
                printf("Digite as coordenadas de sua jogada: ");
                scanf("%d %d", &l, &c);
                printf("Jogada na posição (%d, %d)\n", l, c);
            }else{
                printf("\nTurno do jogador Branco!\n");
                escolhejogada11221741(tabuleiro, jog, &l, &c);
                printf("Jogada na posição (%d, %d)\n", l, c);
            }

            if(podejogar(tabuleiro, jog, l, c)){
                joga(tabuleiro, jog, l, c);
                imprimeTabuleiro(tabuleiro);
            }else{
                if(jog == -1){
                    printf("\nAs pretas fizeram um movimento irregular em (%d, %d) - DERROTA!\n", l, c);
                }else{
                    printf("\nAs brancas fizeram um movimento irregular em (%d, %d) - DERROTA!\n", l, c);
                }
                fimDeJogo = 1;
            }
        }else{
            if(jog == -1){
                printf("\nNão há jogadas possíveis para as pedras pretas.\n");
            }else{
                printf("\nNão há jogadas possíveis para as pedras brancas.\n");
            }
        }

        jog = -jog;
    }

    printf("\nNão há mais jogadas possíveis no tabuleiro!\n");
    contaPecas(tabuleiro, &brancas, &pretas);
    if(!fimDeJogo){
        if( brancas > pretas ){
            printf("\nAs brancas venceram!\n");
            printf("PLACAR: Pretas - %d, Brancas - %d\n", pretas, brancas);
        }else if( pretas > brancas ){
            printf("\nAs pretas venceram!\n");
            printf("PLACAR: Pretas - %d, Brancas - %d\n", pretas, brancas);
        }else {
            printf("\nO jogo resultou em EMPATE! Ambos os jogadores tem %d peças no tabuleiro.", pretas);
        }
    }
    
}