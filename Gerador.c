#include <stdio.h>
#include <stdlib.h>

int main() {

	int i,j,x;
	int qtdSim; // quantidade de simbolos
	int qtdEst; // quantidade de estados
	int estIni; // armazena estado inicial
	int qtdFin; // quantidade de estados finais
	int estFin; // caso final unico
	int cFDP; // variavel auxiliar



	// coletar quantidade de simbolos
	printf("Quantidade de simbolos: ");
	scanf("%d", &qtdSim);

	char vSim[qtdSim];  // vetor para armazenar os simbolos

	// amazenamentos dos simobolos
	for(i=0; i<qtdSim; i++){
		printf("Insira o simbolo %d: ", i);
		scanf("%d", &cFDP);
		scanf("%c", &vSim[i]);
	}


	// quantidade de estados
	printf("Insira a quantidade de estados: ");
	scanf("%d", &qtdEst);


	// armazena o estado inicial
	printf("Insira o estado inicial: ");
	scanf("%d", &estIni);



	// Definir estado(s) final
	printf("Insira quantidade de estados finais: ");
	scanf("%d", &qtdFin);


	int vFin[qtdFin]; // vetor para armazenar os finais


	// Caso seja mais de 1 final
	if(qtdFin > 1){
		for(i=0; i<qtdFin; i++){
    	printf("Insira o final %d:", i);
    	scanf("%d", &vFin[i]);
		}
	}
	else{
    	printf("Insira o estado final: ");
    	scanf("%d", &estFin);
	}


	int m[qtdEst][qtdSim];

	for(i=0; i<qtdEst; i++){
    	for(j=0; j<qtdSim; j++){
    		printf("para o estado e%d e simbolo %c, qual o proximo estado? ", i,vSim[j]);
    		scanf("%d", &m[i][j]);
    	}
	}

	for(i=0; i<qtdEst; i++){
  		for(j=0; j<qtdSim; j++){
  			printf("%d ", m[i][j]);
		}
		printf("\n");
	}

    // ===========================================================INICIO ARQUIVO==================================================
	int fpp = 0; // flag para controlar o primeiro if
	int fef = 0; // flag para saber se é estado final
	

	FILE *arq;
	arq = fopen("mec.c", "wt");  // Cria um arquivo texto para gravação
	
	
		
		
	//Incio padrão
	fprintf(arq,"#include <stdio.h>\n");
	fprintf(arq,"#include <stdlib.h>\n");
	fprintf(arq,"#include <conio.h>\n");
	fprintf(arq,"\n");
	fprintf(arq,"int main(){\n");
	fprintf(arq,"\n");
	fprintf(arq,"	char p[100];\n");
	fprintf(arq,"	int i;\n");
	fprintf(arq,"	i=0;\n");
	fprintf(arq,"	printf(\"Digite a palavra: \");\n");
	fprintf(arq,"	gets(p);\n");
	
	
	// ======================================================UTILIZANDO GOTO======================================================
	fprintf(arq,"	goto E%d;\n", estIni);
	fprintf(arq,"\n");

	
	

	for(i=0; i<qtdEst; i++){
		fprintf(arq,"	E%d:\n", i);
		
		for(j=0; j<qtdSim; j++){
			if(m[i][j] != -1){
			
				
				if(fpp == 0){
				fprintf(arq,"		if(p[i] == '%c'){\n", vSim[j]);
				fprintf(arq,"			i++;\n");	
				fprintf(arq,"			goto E%d;\n", m[i][j]);	
				fprintf(arq,"		}\n");			
				}
					
				else{
					fprintf(arq,"		else if(p[i] == '%c'){\n", vSim[j]);
					fprintf(arq,"			i++;\n");
					fprintf(arq,"			goto E%d;\n", m[i][j]);
					fprintf(arq,"		}\n");
				}
				
				fpp += 1;			
			}	
		}
		fpp = 0;
		
		// só se for UM final
		if(qtdFin == 1){
			fef = estFin;
			if(fef == i){
				fprintf(arq,"		else if(p[i] == 0){\n");
				fprintf(arq,"			goto ACEITA;\n");
				fprintf(arq,"		}\n");
			}
		}else{
			for(x=0; x<qtdFin; x++){
				if(vFin[x] == i){
					fprintf(arq,"		else if(p[i] == 0){\n");
					fprintf(arq,"			goto ACEITA;\n");
					fprintf(arq,"		}\n");
				}
			}
		}
			
		fprintf(arq,"		else{\n");
		fprintf(arq,"			goto REJEITA;\n");
		fprintf(arq,"		}\n");
		fprintf(arq,"\n");
		fprintf(arq,"\n");
	}
	
	fprintf(arq,"	ACEITA:\n");
	fprintf(arq,"		printf(\"Palavra aceita\");\n");
	fprintf(arq,"		getch();\n");
	fprintf(arq,"		exit(0);\n");
	fprintf(arq,"\n");
	fprintf(arq,"\n");
	
	fprintf(arq,"\n");
	fprintf(arq,"	REJEITA:\n");
	fprintf(arq,"		printf(\"Palavra rejeitada\");\n");
	fprintf(arq,"		getch();\n");
	fprintf(arq,"		exit(0);\n");
	fprintf(arq,"}\n");
	
	system("PAUSE");
	return 0;
}
