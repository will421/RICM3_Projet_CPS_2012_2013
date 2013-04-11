
#include <stdint.h>



// Converti un PPM en PGM 
void coloredtogray(struct image * im,float a,float b,float c)
{
	uint64_t nbpixel = (im->l * im->h);
	uint64_t * data = im->data ;
	uint64_t i;
	for(i=0;i<=nbpixel;i++) {
	        RGBtoGrey(data+i,0.299,0.587,0.114);
	}
}

//Prend RGB et convertis en gris avec les constantes associés
void RGBtoGrey(uint64_t *pixel,float a,float b,float c) {
        uint16_t r,g,bl;
        getColor(pixel,&r,&g,&bl);
        *pixel = a*r + b*g + c*bl;
}

// Prend un entier sur 64 bit et retourne le (r,g,b)
void getColor(uint64_t const *pixel, uint16_t *r,uint16_t *g,uint16_t *b) {
	int decalr = 32;
	int decalg = 16;
	int decalb = 0;
	int mask = 65535;
	
	*r = (*pixel >> decalr /*decalage*/ ) & mask;
	*g = (*pixel >> decalg /*decalage*/ ) & mask;
	*b = (*pixel >> decalb /*decalage*/ ) & mask;

}
