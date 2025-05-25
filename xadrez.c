#include <stdio.h>
// DEFININDO O TAMANHO DA MATRIZ DO CONE 
//============================================================= (3x5) tamanho original (testei outros valores < 10)
#define lcone 3
#define ccone 5
// DEFININDO O TAMANHO DA MATRIZ DA CRUZ
//============================================================= (4x5) tamanho original (testei outros valores < 10)
#define lcruz 4
#define ccruz 5
// DEFININDO O TAMANHO DA MATRIZ DO OCTAEDR0
//============================================================= (5x5) tamanho original (testei outros valores < 10)
#define loct 5 
#define coct 5

int main()
{
	//DEFININDO AS TRÊS MATRIZES DAS FIGURAS AQUI PARA MUDAR SEUS VALORES NA MATRIZ (10X10) SEM ERRO
	int cone[lcone][ccone] = {0}; // Declarando a matriz do cone
	int cruz[lcruz][ccruz] = {0}; // Declarando a matriz da cruz
	int octaedro[loct][coct] = {0}; // Declarando a matriz do octaedro
	//----------------------------------------------------------------
	if(lcone > 10 || ccone > 10 || ccone < lcone) // condição para criar a matriz
    {
        printf("\nA matriz do cone tem que ser menor ou igual a (10x10)" 
		" ou numero de colunas maior ou igual ao numero de linhas\n");
    }
    else
    {
    	
    	// se a coluna central for par divide por 2 se não diminui 1 para ficar divisão exata por 2
    	int centro_cone = (ccone % 2 == 0) ? (ccone / 2) : ((ccone - 1) / 2); // determina o centro do cone
		
		for(int i = 0; i < lcone; i++) // inicia o loop de i de 0 ao número de linhas da matriz
		{
			for(int j = centro_cone - i; j <= centro_cone + i; j++) // inicia o loop de j a partir do centro do cone
			{
				cone[i][j] = 3; // três é o caracter que representa o navio
				
				
			} 
		}
		//Imprimindo o cone
		//loops percorrendo linhas e colunas para impressão, obedecendo o limite da matriz
		printf("Impressao do cone (3x5)\n\n");
		for(int i = 0; i < lcone; i++) 
		{
			for(int j = 0; j < ccone; j++)
			{
				printf("%d", cone[i][j]);
				
			}
			printf("\n");
		}
	}
	
	
	//DEFININDO A CRUZ
	 // DEFININDO A CRUZ
    if(lcruz > 10 || ccruz > 10) // condição para criar a matriz
    {
        printf("\nA matriz da cruz tem que ser menor ou igual a (10x10)\n");
    }
    else
    {
        // criando a linha e coluna central da cruz (a cruz não sera simétrica se o numero de colunas for par)
        // se a coluna for par divide por 2 se não diminui 1 para ficar divisão exata por 2
        int centro_cruz = (ccruz % 2 == 0) ? (ccruz / 2) : ((ccruz - 1) / 2); 
        
        
        for(int i = 0; i < lcruz; i++) 
        {
            cruz[i][centro_cruz] = 3;  // coluna central preenchida, caracter três representa o navio
        }
        
        for(int j = 0; j < ccruz; j++) 
        {
        	cruz[1][j] = 3;  // braço da cruz, sempre na linha 1
            
        }
        
        // Imprimindo a cruz
        //loops percorrendo linhas e colunas para impressão, obedecendo o limite da matriz
        printf("\nImpressao da cruz (4x5)\n\n");
        for(int i = 0; i < lcruz; i++)
        {
            for(int j = 0; j < ccruz; j++)
            {
                printf("%d ", cruz[i][j]);
            }
            printf("\n");
        }
    }

	//DEFININDO O OCTAEDRO
	//----------------------------------------------------------------
	if(loct > 10 || coct > 10 || coct < loct) // condição para criar a matriz
    {
        printf("\nA matriz do octaedro tem que ser menor ou igual a (10x10)"
		" ou numero de colunas maior ou igual ao numero de linhas\n");
    }
    else
    {   
    	// se a coluna central for par divide por 2 se não diminui 1 para ficar divisão exata por 2
    	int centro_octa = (coct % 2 == 0) ? (coct / 2) : ((coct - 1) / 2); // determina o centro do octaedro
       	// loop da parte de cima do octaedro 
	    for (int i = 0; i < centro_octa; i++) 
		{
	        for (int j = 0; j < coct; j++) // Incrementa j até o limite das colunas - 1
			 {
	            if (j >= centro_octa - i && j <= centro_octa + i) // condição para preencher as colunas 
				{
	                octaedro[i][j] = 3; // três é o caracter para representar o novio
	            }
	            
	        }
	    }
	    // loop da parte de baixo do octaedro (essa parte de baixo foi elaborada como ajuda da internet, não consegui
	    // desenvolver sozinho, sempre dava errado. Só resolveu com a variavel "alvo"	
	    for (int i = centro_octa; i < loct; i++)
		{
		    int alvo = loct - 1 - i; // Decrementa quantas colunas a preencher a partir do centro, diminuindo a cada linha
		    for (int j = 0; j < coct; j++)
			 {
		        if (j >= centro_octa - alvo && j <= centro_octa + alvo)
				{
		            octaedro[i][j] = 3; // três é o caracter para representar o novio
        		}
    		}
		}
	    // Imprime o octaedro
	    //loops percorrendo linhas e colunas para impressão, obedecendo o limite da matriz
	    printf("\n");
	    printf("Impressao do octaedro (5x5)\n\n");
	    for (int i = 0; i < loct; i++)
		{
	        for (int j = 0; j < coct; j++)
			{
	            printf("%d ", octaedro[i][j]);
	        }
	        printf("\n");
    	}
	}
	
    //=============== DETERMINANDO AS POSIÇÕES DAS TRÊS FIGURAS NA MATRIZ (10X10) ===============
    //POSICIONANDO O CONE
    //--------------------------------------------------------------------------------------------
	int matriz[10][10]	= {0}; // Definindo a matriz
	
	for(int i = 0; i < 3; i++) // Iniciando o cone no visual da matriz na linha 1 e coluna 3
	{
		for(int j = 0; j < 5; j++)
		{	
			if(cone[i][j] == 3) // Alterando o valor 3 para 1
				matriz[i][j] = 1;
		}
	}
	//POSICIONANDO A CRUZ
	//--------------------------------------------------------------------------------------------
	for(int i = 0; i < lcruz; i++) // Iniciando a cruz no visual da matriz na linha 3 e coluna 7
	{
		for(int j = 0; j < ccruz; j++)
		{	
			if(cruz[i][j] == 3) // Alterando o valor 3 para 1
				matriz[i+2][j+4] = 2;
		}
	}//POSICIONANDO O OCTAEDRO
	//--------------------------------------------------------------------------------------------
	for(int i = 0; i < loct; i++) // Iniciando a cruz no visual da matriz na linha 6 e coluna 4
	{
		for(int j = 0; j < coct; j++)
		{	
			if(octaedro[i][j] == 3) // Alterando o valor 3 para 1
				matriz[i+5][j+1] = 3;
		}
	}
	
	// ============== IMPRIMINDO AS TRÊS FIGURAS NA MATRIZ (10X10) ==============
	printf("\nMatriz (10x10) com as tres figuras\n\n");
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{	
			printf("%d", matriz[i][j]);
		}	
		printf("\n");	
	}
	
	return 0;
}