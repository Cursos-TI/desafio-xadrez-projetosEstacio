#include <stdio.h>


int main()
{
	char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
	
	int tabuleiro[10][10]; // Declarando a matriz tabuleiro
	
	for(int i = 0; i < 10; i++) // Iniciando o tabuleiro[i][j] com valores i * 10 + j
	{
		for(int j = 0; j < 10; j++)
		{
			tabuleiro[i][j] = (i * 10 + j) * 0; // multiplica todos os valores por zero
			
		}
	}
	//printf("Tabuleiro 10 x 10...\n"); // Imprimindo o tabuleiro de 1 a 10 linhas e de A a J colunas
		printf("\n");
		printf("   "); // Imprime um espaço entre os títulos das colunas
		for(int j = 0; j < 10; j++)
		{
			printf(" %c ", 'A' + j); // imprime o cabeçalho da coluna de A até J
			
		}
		//Posição do navio na horizontal linha 7 (indice 6) e colunas C, D, e E (indices 2, 3, e 4)
		tabuleiro[6][2] = 3;
		tabuleiro[6][3] = 3;
		tabuleiro[6][4] = 3;
		//posição do navio na vertical coluna 7 (indice 6) e linhas 2, 3, e 4 (indices 1, 2, e 3)
		tabuleiro[1][6] = 3;
		tabuleiro[2][6] = 3;
		tabuleiro[3][6] = 3;
		
			printf("\n"); // quebra de linha entre o cabeçalho da coluna e o tabuleiro
			
		for(int i = 0; i < 10; i++)
		{
			printf("%2d", i + 1); // Imprime a ordem das linhas com caracteres de no mínimo 2 digitos.
			for(int j = 0; j < 10; j++)
			{
				printf("%3d", tabuleiro[i][j]); //imprimindo o tabuleiro
				
			}
			printf("\n");
		}
			
	
	return 0;
}