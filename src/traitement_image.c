// Projet C.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include <stdio.h>

#define DEBUG 1

int main(int argc, char* argv[])
{
	int option; // 0 => g / 1 => d
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
	}
}

