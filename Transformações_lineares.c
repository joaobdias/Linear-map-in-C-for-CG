#include "Transformações_lineares.h"

void telaCord (int x, int y) {
    
	COORD tela; 
    tela.X = x; 
    tela.Y = y;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), tela);
}

void plano () {
    
    int hor, ver;
        
        for  (ver = 5; ver < 35; ver++) {
            telaCord(75,ver);
            printf("|");
        }
        
        for (hor = 37; hor < 117; hor++) {
            telaCord(hor, 20);
            printf("-");
        }
        
        telaCord(75,20);
        printf("0");
        telaCord(0,0);
}

void polilinhasDda(int *vetval,int numver) { 
    
    int numlinhas, deltax, deltay, aux, i;
    float xinc, yinc, xaux, yaux, step;
    
	system("cls");
    plano();
    
    xaux = 0; yaux = 0; aux = 0; i = 1;
    
        while (i <= numver) {
                            
                if (i < numver){
                    xaux = *(vetval+aux);
                    yaux = *(vetval+(aux+1));
				
                    deltax = *(vetval+(aux+2)) - *(vetval+aux);
                    deltay = *(vetval+(aux+3)) - *(vetval+(aux+1));

                    if (abs(deltax) >= abs(deltay))
                        step = abs(deltax);
                    else
                        step = abs(deltay);
            
                    xinc = deltax/step;
                    yinc = deltay/step;
        
                    telaCord(round(xaux+75),round(-yaux+20));
                    printf("%c", 254);
        
                    while ((round(xaux) != *(vetval+(aux+2))) || (round(yaux) != *(vetval+(aux+3)))) {
        
                        xaux = xaux + xinc;
                        yaux = yaux + yinc;
                        telaCord(round(xaux+75),round(-yaux+20));
                        printf("%c", 254);

                    }
                
                aux += 2;
                    
                } else if (i == numver) {
                    
                    xaux = *(vetval+aux);
                    yaux = *(vetval+(aux+1));
    
                    deltax = *vetval - *(vetval+aux);
                    deltay = *(vetval+1) - *(vetval+(aux+1));

                    if (abs(deltax) >= abs(deltay))
                        step = abs(deltax);
                    else
                        step = abs(deltay);
            
                    xinc = deltax/step;
                    yinc = deltay/step;
        
                    telaCord(round(xaux+75),round(-yaux+20));
                    printf("%c", 254);
                    
                    while ((round(xaux) != *vetval) || (round(yaux) != *(vetval+1))){
                                                                                     
                        xaux = xaux + xinc;
                        yaux = yaux + yinc;
                        telaCord(round(xaux+75),round(-yaux+20));
                        printf("%c", 254);
            
                    }  
                }
                
            i++;
        }
        
} 

void rot(int *vetval, int numver) {
	
	int ang, aux = 0;
	float pi = 3.141592, angc, angs, aux2;
	
	printf("\n\nDigite o %cngulo de rota%c%co: ", 131,135,198);
	scanf("%d", &ang);
  
  	angc = cos(ang*pi/180);
  	angs = sin(ang*pi/180);
    
	while(aux < numver*2){
    
	    aux2 = *vetval;
	    *vetval = round(*vetval * angc) + round(*(vetval+1) * -angs);
	    *vetval++;
	    *vetval = round(aux2 * angs) + round(*vetval * angc);
	    *vetval++;
	    aux+=2;
  	}

  	vetval = vetval - numver*2; 	
}

void cisa(int *vetval, int numver) { 
	
	int aux, ang;
	float pi = 3.141592, angt, aux2;
	
	printf("\n\nComo ser%c feito o cisalhamento? ",160);
	printf("\n1 - em x");
	printf("\n2 - em y");
	aux = (int)getch() - '0';		

	printf("\n\nDigite o %cngulo de cisalhamento: ",131);
	scanf("%d", &ang);
	
	angt = tan(ang*pi/180);

	if (aux == 1){ 
		aux = 0;
	    while(aux < numver*2){
	       
			aux2 = *vetval;  
		    *vetval = (*vetval * 1) + (*(vetval+1) * angt);
		    *vetval++;
		    *vetval = (aux2 * 0) + (*vetval * 1);
		    *vetval++;
		    aux+=2;
	    }
	
	} else {
	 	aux = 0;
	    while(aux < numver*2){
	    
			aux2 = *vetval;        
		    *vetval = (*vetval * 1) + (*(vetval+1) * 0);
		    *vetval++;
		    *vetval = (aux2 * angt) + (*vetval * 1);
		    *vetval++;
		    aux+=2;
		    
	    }
	  }

  vetval = vetval - numver*2; 
		
}

void reflex(int *vetval, int numver) {
	
	int aux, aux2;
	
	printf("\n\nComo ser%c feita a reflex%co? ",160,198);
	printf("\n1 - em y");
	printf("\n2 - em x");
	printf("\n3 - y = x");
	aux = (int)getch() - '0';		

    switch(aux){
	
	    case 1:
		  aux = 0;
	      while(aux < numver*2){
	        
	      	*vetval = (*vetval * -1) + (*vetval * 0);
	        *vetval++;
	        *vetval = (*vetval * 0) + (*vetval * 1);
	        *vetval++;
	        aux+=2;
	      }
	      break;
	      
	    case 2:
	      aux = 0;
	      while(aux < numver*2){
	          
	        *vetval = (*vetval * 1) + (*vetval * 0);
	        *vetval++;
	        *vetval = (*vetval * 0) + (*vetval * -1);
	        *vetval++;
	        aux+=2;
	      }
	      break;
	      
	    case 3:
	      	aux = 0;
	        while(aux < numver*2){
	        
	          *vetval = (*vetval * 0) + (*vetval * -1);
	          *vetval++;
	          *vetval = (*vetval * -1) + (*vetval * 0);
	          *vetval++;
	          aux+=2;
	        }
	        
	      break;
	      
	    default:
	      break;

  	}
  
  	vetval = vetval - numver*2;			
}

void esc(int *vetval, int numver) {
	
	int aux = 0;
	float escx, escy;
	
	printf("\n\nDigite o valor das escalas em x e y respectivamente: ");
	printf("\nEm x: ");
	scanf("%f", &escx);
	printf("\nEm y: ");
	scanf("%f", &escy);

    while(aux < numver*2){
        
        *vetval = (*vetval * escx) + (*vetval * 0);
        *vetval++;
        *vetval = (*vetval * 0) + (*vetval * escy);
        *vetval++;
        aux+=2;
    }

    vetval = vetval - numver*2;	
		
}
