#include <stdio.h>
#define lin 10
#define col 10


int main()
{
	int tabuleiro[lin][col]; // Declarando a matriz tabuleiro
	
	for(int i = 0; i < lin; i++) // Iniciando o tabuleiro[i][j] com valores i * 10 + j
	{
		for(int j = 0; j < col; j++)
		{
			tabuleiro[i][j] = (i * col + j) * 0; // multiplica todos os valores por zero
			
		}
	}
	//printf("Tabuleiro 10 x 10...\n"); // Imprimindo o tabuleiro de 1 a 10 linhas e de A a J colunas
		printf("\n");
		printf("   "); // Imprime um espaço entre os títulos das colunas
		for(int j = 0; j < col; j++)
		{
			printf(" %c ", 'A' + j); // imprime o cabeçalho da coluna de A até J. (incrementa A até j)
		}
		// ============== NAVIOS NA HORIZONTAL ==============
		// PRIMEIRO NAVIO
		int linNav1 = 0; // índice da linha inicial
		int colNav1 = 0; // índice da coluna inicial
		
		int colFinal1 = colNav1 + 2; // Ocupa da primeira a terceira coluna (índice 0 a 2)
		// Verifica se está dentro do tabuleiro
		if(colFinal1 < col)
		{
			for(int j = 0; j < 3; j++) // ocupa as colunas 1, 2, e 3
			{
				tabuleiro[linNav1][colNav1 + j] = 3;
			}
		}
		else
		{
			printf("Primeiro navio nao cabe nessa posicao...");
		}
		
		// SEGUNDO NAVIO
		int linNav2 = 1; // índice da linha inicial
		int colNav2 = 5; // índice da coluna inicial
		
		int colFinal2 = colNav2 + 2; // Ocupa da sexta a oitava coluna (índice 5 a 7)
		// Verifica se está dentro do tabuleiro
		if(colFinal2 < col)
		{
			for(int j = 0; j < 3; j++) // ocupa as colunas 6, 7, e 8
			{
				tabuleiro[linNav2][colNav2 + j] = 3;
			}
		}
		else
		{
			printf("Segundo navio nao cabe nessa posicao...");
		}
		// ============ NAVIOS NA DIAGONAL ============	F
		// TERCEIRO NAVIO
		int linDiag3 = 6; // índice da linha inicial da primeira diagonal (terceiro navio)
		int colDiag3 = 0; // indice da coluna inicial da primeira diagonal (terceiro navio)
		
		int linFimDiag3 = linDiag3 + 2; // final linha da diagonal
		int colFimDiag3 = colDiag3 + 2; // final da coluna da diagonal
		
		if(linFimDiag3 < lin && colFimDiag3 < col)
		{
			for(int i = 0; i < 3; i++)
			{
				tabuleiro[linDiag3 + i][colDiag3 + i] = 3; // ocupa o espaço [6,0] a [8,2]
			}
		}
		else
		{
			printf("Terceiro navio nao cabe nessa posicao...");
		}
		// QUARTO NAVIO
		int linDiag4 = 5; // índice da linha inicial da primeira diagonal (quarto navio)
		int colDiag4 = 6; // indice da coluna inicial da primeira diagonal (quarto navio)
		
		int linFimDiag4 = linDiag4 - 2; // final linha da diagonal
		int colFimDiag4 = linDiag4 - 2; // final da coluna da diagonal
		
		if(linFimDiag4 < lin && colFimDiag4 < col)
		{
			for(int j = 0; j < 3; j++)
			{
				tabuleiro[linDiag4 - j][colDiag4 + j] = 3; // ocupa o espaço [5,6] a [3,8]
			}
		}
		else
		{
			printf("Quarto navio nao cabe nessa posicao...\n");
		}
		//+++++++++++++++++++++++++++
		printf("\n");	
		for(int i = 0; i < lin; i++) //loop externo
		{
			printf("%2d", i + 1); // Imprime a ordem das linhas com caracteres de no mínimo 2 digitos.
			for(int j = 0; j < col; j++) //loop interno
			{
				printf("%3d", tabuleiro[i][j]); //imprimindo o tabuleiro
				
			}
			printf("\n");
		}
			
	
	return 0;
}