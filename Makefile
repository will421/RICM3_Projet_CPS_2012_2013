

all : PPMto

PPMto : PPMto.c
	gcc -o $@ $<