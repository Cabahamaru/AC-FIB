#include "CacheSim.h"
#include <stdio.h>
/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

int cache[128];
int valid[128];

int counthit = 0;
int countmiss = 0;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */

    int i;
    for (i = 0; i < 128; ++i) {
        valid[i] = 0; //vaciamos caché
    }

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
    
    unsigned int x = address;
    
    byte = x & 31; // 5 bits de menor peso
    
    x = x >> 5;
    
    bloque_m = x & 134217727;
    
    linea_mc = x & 127;
    
    x = x >> 7;
    
    tag = x & 1048575;
    
    if ( valid[linea_mc] == 0) {
        miss = 1;
        replacement = 0;
        cache[linea_mc] = tag;
        valid[linea_mc] = 1;
        countmiss++;
    }
    else if (cache[linea_mc] == tag) {
        miss = 0;
        replacement = 0;
        counthit++;
    }
    else {
        miss = 1;
        replacement = 1;
        tag_out = cache[linea_mc];
        cache[linea_mc] = tag;
        countmiss++;
    }

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  printf("Hits: %d, Miss: %d\n", counthit, countmiss);
}
