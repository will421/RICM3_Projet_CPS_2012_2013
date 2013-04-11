// Projet C.cpp : définit le point d'entrée pour l'application console.
//

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "util.h"
#include "ppm.h"

int main(int argc, char* argv[])
{
	/*int option; // 0 => g / 1 => d
	char * nomFichier;
	FILE *f;
	if(*(argv+1)=="-g") { 
		option = 0;
	}
	else if (*(argv+1)=="-d") {
		option = 1;
	}
	else { printf("Erreur : Option %s inconnu\n",argv[1]); return 1;}

	if(*(argv+2)) {
		f = fopen(*(argv+2),"r");
	}
	else {
		f = NULL;
	}
	if (f==NULL)
	{
		f = stdin;
	}*/
	
	FILE *fileSource = NULL;
   FILE *fileDest = NULL;
   char *sourceName = NULL;
   char *destName = NULL; 
   image *img = NULL;
   
   sourceName = *(argv+1);
	
	fileSource = fopen(sourceName,"r");

	img = readppm(fileSource);
	
	printf("img -> type : %d\n",img->t);
	printf("img -> l : %d\n",img->l);
	printf("img -> h : %d\n",img->h);
	printf("img -> max : %d\n",img->vmax);
	
}

