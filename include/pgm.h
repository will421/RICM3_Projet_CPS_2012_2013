#ifndef PGM_H
#define PGM_H

#include "util.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* ecris l'image dans un fichier pgm */
int writepgm(FILE * destFile, image* img);

#endif
