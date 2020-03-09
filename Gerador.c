#include <stdio.h>
#include <stdlib.h>

int main() {

  int i,j;
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
		printf("Insira o simbolo %d: ", i+1);
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
      printf("Insira o final %d+1:", i);
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
      printf("para o estado e%d e simbolo %c, qual o proximo estado? ", 1+i,vSim[j]);
      scanf("%d", &m[i][j]);
    }
  }

  for(i=0; i<qtdEst; i++){
  	for(j=0; j<qtdSim; j++){
  		printf("%d ", m[i][j]);

	  }
	printf("\n");
  }


system("PAUSE");
return 0;
}
