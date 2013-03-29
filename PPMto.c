// Projet C.cpp : définit le point d'entrée pour l'application console.
//
#define DEBUG 1
#include <stdio.h>
#include <stdint.h>


typedef struct _image_datas image_data;
enum typeImage {
	P1=1,
	P2=2,
	P3=3
};
struct _image_datas {
	enum typeImage t;
	uint32_t l;
	uint32_t h;
	int vmax;
	uint64_t * data;
};

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

