#ifndef _H
#define _H

enum typeImage {
	P1=1, 			// PBM
	P2=2, 			// PGM
	P3=3  			// PPM
} typeImage;

struct image {
	typeImage t;		//
	uint32_t l;			//
	uint32_t h;			//
	int vmax;			//
	uint64_t * data;	//
} image;

// Converti un PPM en PGM 
void coloredtogray(image * i,float a,float b,float c);

// Converti un PPM en PBM 
void coloredtoBW();

// Lit le type d'une image
void readType();

// Lit les dimmensions d'une image
void readDimension();

// Prend un entier sur 64 bit et retourne le (r,g,b)
void getColor(uint64_t const *pixel, uint32_t *r,uint32_t *g,uint32_t *b);

#endif
