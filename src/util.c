
#include <stdint.h>


// Prend un entier sur 64 bit et retourne le (r,g,b)
void getColor(uint64_t const *pixel, uint32_t *r,uint32_t *g,uint32_t *b) {
	int decalr = 0;
	int decalg = 0;
	int decalb = 0;
	int mask = 0;
	
	*r = (*pixel >> decalr /*decalage*/ ) & mask;
	*g = (*pixel >> decalg /*decalage*/ ) & mask;
	*b = (*pixel >> decalb /*decalage*/ ) & mask;

}
