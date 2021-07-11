#include "Transformações_lineares.c"

int main() {
	
	int numVer, aux, i, xaux = 1, yaux = 1,saida = 0,escolha = 1;

	while(saida != 1) {
		system("cls");
		xaux = 1;
		yaux = 1;
		escolha = 1;
	    
      	printf("Quantos v%crtices deseja colocar?: ", 130);
	    scanf("%d", &numVer);

	    int vetval[numVer*2]; 
	    
	    for(i = 0; i < numVer*2; i++) { 
	        if (i%2 == 0) { 
	            printf("\nDigite o valor de x%d: ", xaux);
	            scanf("%d",&aux);
	            vetval[i] = aux;
	            xaux++;
	            
	        } else {  
	            printf("Digite o valor de y%d: ", yaux);
	            scanf("%d",&aux);
	            vetval[i] = aux;
	            yaux++;
	        }
	    }
	          
      while(escolha != 0) {
      	
      	    system("cls");
      	    polilinhasDda(vetval,numVer);
      		telaCord(0,0);
			printf("Selecione qual TF deseja fazer:");
			printf("\n1 - Reflex%co",198);
			printf("\n2 - Rota%c%co",135,198);
			printf("\n3 - Cisalhamento");
			printf("\n4 - Escala");
	    	aux = (int)getch() - '0';		
				
			switch(aux) {
				case 1:
					//reflexão
					reflex(vetval, numVer);
					polilinhasDda(vetval, numVer);
	      			telaCord(0,0);
					printf("Deseja realizar outra TF? (0 para n%co, 1 para sim)\n",198);
	    			escolha = (int)getch() - '0';		
					break;
					
				case 2:
					//rotação
					rot(vetval, numVer);
					polilinhasDda(vetval, numVer);
	      			telaCord(0,0);
					printf("Deseja realizar outra TF? (0 para n%co, 1 para sim)\n",198);
	    			escolha = (int)getch() - '0';		
					break;
					
				case 3:
					//cisalhamento
					cisa(vetval, numVer);
					polilinhasDda(vetval, numVer);
	      			telaCord(0,0);
					printf("Deseja realizar outra TF? (0 para n%co, 1 para sim)\n",198);
	    			escolha = (int)getch() - '0';		
					break;
					
				case 4:
					//escala
					esc(vetval, numVer);
					polilinhasDda(vetval, numVer);
	      			telaCord(0,0);
					printf("Deseja realizar outra TF? (0 para n%co, 1 para sim)\n",198);
	    			escolha = (int)getch() - '0';		
					break;
	        
				default:
					break;
			}
	  }
	  	
	  	telaCord(0,0);
	  	system("cls");
		printf("Quer realizar a TF em outra figura? (1 para sair)\n");
	    saida = (int)getch() - '0';
	}
		
	return 0;
}
