#include "ppm.h"

int readPixelppm(FILE *sourceFile, uint64_t *pixel){
	uint64_t r=0,g=0,b=0,p=0;
	int rf=0,res=EXIT_SUCCESS;
	rf = fscanf(sourceFile, "%*[ \t\n]%llu%*[ \t\n]%llu%*[ \t\n]%llu", &r, &g, &b);
	if (rf == 3){
		r = (r <= 65535) ? r : 65535;
		b = (b <= 65535) ? b : 65535;
		g = (g <= 65535) ? g : 65535;
     	p = b + (g << 16) + (r << 32);    
     	*pixel = p;
     	/* MODE DEBUG */
     	if(DEBUG){
     		printf("Fonction: readPixelppm =>\n");
     		printf("r= %llu g=%llu b=%llu p=%llu\n",r,g,b,p);
     	}
	}else{
		res = EXIT_FAILURE;
	}
	return res;
}

int readDatappm(FILE *sourceFile,image *img){
	int i,res;
	uint64_t size,pixel;
	size = img->h * img->l;
	img->data = (uint64_t *)malloc(size * sizeof(uint64_t));
	for(i = 0; i<size && (res = readPixelppm(sourceFile,&pixel)) == EXIT_SUCCESS ;i++){
		img->data[i] = pixel;
	}
	return res;
}

/* lit une image ppm et retourne une image(struct) */
image* readppm(FILE *sourceFile){
	image *img = NULL;
   typeImage type;
   uint32_t l, h;
   int max;
	int t;
	int bfile=1,btype=1,bdim=1,bmax=1,bdata=1;
	
	if(sourceFile != NULL){
		img = (image *)malloc(sizeof(image));
		t = readType(sourceFile,&type);
		if( t == EXIT_SUCCESS && type == P3){
			img->t = type;
			t = readDimension(sourceFile,&l,&h);
			if(t == EXIT_SUCCESS){
				img->l = l;
				img->h = h;
				t = readMax(sourceFile,&max);
				if(t == EXIT_SUCCESS){
					img->vmax = max;
					t = readDatappm(sourceFile,img);
					if(t != EXIT_SUCCESS){
						bdata = 0;
					}
				}else {bmax = 0;}
			} else {bdim = 0;}
		} else{ btype = 0;}
	}else{
		bfile = 0;
	}
	/**********************************/
	/* ERREUR */
	if(!bfile){
		printf("ERREUR: Impossible d'ouvrir le fichier\n");
	}
	if(!btype){
		printf("ERREUR: Mauvais type\n");
	}
	if(!bdim){
		printf("ERREUR: Impossible de lire les dimmensions\n");
	}
	if(!bmax){
		printf("ERREUR: Impossible de lire la valeur max\n");
	}
	if(!bdata){
		printf("ERREUR: Impossible de lire la data de l'image\n");
	}
	
	return img;
}

/********************************************/
/* */
image* readppmIn(){
	image *img;
	int t,vm,l,h,i;
	int r=0,g=0,b=0;
	int size;
	
	do {
		printf("Largeur et hauteur: \n"); t = scanf("%d %d",&l,&h);
	}while( t != 2);
	do {
		printf("Valeur max: \n"); t = scanf("%d",&vm);
		if(vm > 65536) { printf("ERREUR: vm > 65536");}
	}while( vm > 65536);
	
	img = (image *)malloc(sizeof(image));
	printf("%d\n",img);
	if( img != NULL){
		img->t = P3;
		img->l = l;
		img->h = h;
		img->vmax = vm;
		img->data = (uint64_t *)malloc(size * sizeof(uint64_t));
		if(img->data != NULL){
			size = l*h;
			i=0;
			while(i<size){
				do{
					printf("\nr g b:");
					scanf("%d %d %d",&r,&g,&b);
					if(r > vm || g > vm || b > vm){
						printf("ERREUR, we need: r < vmax && g < vmax && b < vmax\n");
					}
					
				}while( r > vm || g > vm || b > vm);
				img->data[i] = r + g << 16 + b << 32;
				printf("%d \n",i);
				i++;
			}
		}else{
			printf("ERREUR: Impossible d'allouer de la mémoir pour la data de l'image");
		}
	}else{
		printf("ERREUR: Impossible d'allouer de la mémoir pour l'image");
	}
	return img;
}


