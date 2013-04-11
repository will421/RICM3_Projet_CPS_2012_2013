#ifndef PPM_H
#define PPM_H

#include "util.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// lit une ligne dans le fichier et retourne un etier qui correspond à la couleur
int readPixelppm(FILE *sourceFile, uint64_t *pixel);

// lit toute la data du fichier et remplis une image.
int readDatappm(FILE *sourceFile,image *i);

// lit une image ppm
image* readppm(FILE *sourceFile);

#endif
