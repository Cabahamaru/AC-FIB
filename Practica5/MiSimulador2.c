#include "CacheSim.h"
#include <stdio.h>
/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */


typedef struct {
  int via0;
  int via1;
  int LRU;
} S;

typedef struct {
    int v0;
    int v1;
} V;

S cache[64];
V valid[64];

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
    for (i = 0; i < 64; ++i) {
        valid[i].v0 = 0;
        valid[i].v1 = 0;
    }

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

    unsigned int x = address;
    
    byte = x & 31;
    
    x = x >> 5;

    
    bloque_m = x & 134217727;
    
    conj_mc = x & 63;
    
    x = x >> 6;
    
    tag = x & 2097151;
    
    if (valid[conj_mc].v0 == 0) { //via0 empty
        miss = 1;
        cache[conj_mc].via0 = tag;
        valid[conj_mc].v0 = 1;
        cache[conj_mc].LRU = 1; //via1 es el least recently used
        via_mc = 0;
        replacement = 0;
        ++countmiss;
    }
    else if (cache[conj_mc].via0 != tag) { //via0 != tag
        
        if (valid[conj_mc].v1 == 0) { //via0 != tag and via1 vacia
            miss = 1;
            cache[conj_mc].via1 = tag;
            valid[conj_mc].v1 = 1;
            cache[conj_mc].LRU = 0; //via0 es el least recently used
            via_mc = 1;
            replacement = 0;
            ++countmiss;
        }
        else if (cache[conj_mc].via1 != tag) { // via0 != via1 != tag
            
            if (cache[conj_mc].LRU == 0) { //reemplazo de via0
                miss = 1;
                replacement = 1;
                tag_out = cache[conj_mc].via0;
                cache[conj_mc].via0 = tag;
                via_mc = 0;
                cache[conj_mc].LRU = 1;
                ++countmiss;
            }
            else { //reemplazo de via1
                miss = 1;
                replacement = 1;
                tag_out = cache[conj_mc].via1;
                cache[conj_mc].via1 = tag;
                via_mc = 1;
                cache[conj_mc].LRU = 0;
                ++countmiss;
            }
        }
        else { //via1 == tag
            miss = 0;
            replacement = 0;
            via_mc = 1;
            cache[conj_mc].LRU = 0;
            ++counthit;
        }
    }
    else { //via0 == tag
        miss = 0;
        replacement = 0;
        via_mc = 0;
        cache[conj_mc].LRU = 1;
        ++counthit;
    }

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
    printf("Hits: %d, Miss: %d\n", counthit, countmiss);
  
}
