#include <stdio.h>
#include <stdlib.h>

#include "program.h"
#include "turing.h"

int tete11=1;
int tete12=1;
unsigned char bande11[16]= {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
unsigned char bande12[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};

void _affiche()
{
	int i=0;
	printf(" ");
	for (i=0;i<16;i++){
		if( i == tete11){
			printf("[");
		}
		if (bande11[i]==0){
			printf("-");
		}
		else {
			printf("%d",bande11[i]);
		}
		if( i == tete11){
			printf("]");
		}
		printf("  ");
	}
	printf("\n");
	printf(" ");
	
	for (i=0;i<16;i++){
		if( i == tete12){
			printf("[");
		}
		if (bande12[i]==0){
			printf("-");
		}
		else {
			printf("%d",bande12[i]);
		}	
		if( i == tete12){
			printf("]");
		}
		printf("  ");
		}
	printf("\n");
}

unsigned char _lire_tete(unsigned char t)
{
	
	if(t==1) {
		return bande11[tete11];
	}
	else {
		return bande12[tete12];
	}
	
}

void _droite(unsigned char t)
{
	if(t==1) {
		tete11=tete11+1;
	}
	else if(t==2) {
		tete12=tete12+1;
	}
}

void _gauche(unsigned char t)
{
	if(t == 1) {
		tete11=tete11-1;
	}
	else if(t==2) {
		tete12=tete12-1;
	}
}

void _ecrire_tete(unsigned char t, unsigned char val){
	if(t == 1){
		bande11[tete11] = val;
	}
	  
	else if( t == 2){
	bande12[tete12] = val;
	}	
}



void execute_action(unsigned int action)
{ 
	unsigned int a=(action>>6);
	unsigned int b=(action>>5) & 0b0001;
	unsigned int c=(action>>3) & 0b000011;
	unsigned int d =(action>>2) &0b0000001;
	unsigned int e = action & 	 0b000000011;
	
	_ecrire_tete(1,b);
	_ecrire_tete(2,d);
	
	if (c==0b10){
		_gauche(1);
	}

	else if (c==0b01){
		_droite(1);
	}
		
	if (e==0b10){
		_gauche(2);
	}

	else if (e==0b01){
		_droite(2);
	}
		
	ecrire_etat(a);
}

void run()
{
    int n = 0;
    affiche();
    while(lire_etat()!=(Netats-1))
    {
        unsigned int act = lire_prog(lire_etat(),_lire_tete(1),_lire_tete(2));
        execute_action(act);
        n++; printf("Etape %d\n",n);
        _affiche();
        getchar();
    }
}

int main()
{
    printf("Simulation d'une machine de Turing a 2 bandes\n");
    run();
    printf("Fin d'execution\n");
    return 0;
}

/// 00 01 01 02 03 05 08 13 07 06
/// 13 05 04 09 13 08 07 01 08 09
/// 03 12 01 13 00 13 13 12 11 09
/// 06 01 07 08 01 09 10 05 01 06
/// 07 13 06 05 11 02 13 01

