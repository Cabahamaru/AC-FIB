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
	/* Escriu aqui el teu codi */

    int i;
    for (i = 0; i < 128; ++i) {
        valid[i] = 0; //vaciamos caché
    }

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */

    unsigned int x = address;
    
    byte = x & 31; // 5 bits de menor peso
    
    x = x >> 5;
    
    bloque_m = x & 134217727;
    
    linea_mc = x & 127;
    
    x = x >> 7;
    
    tag = x & 1048575;
    tag_out = 0;
    
    mida_esc_mp = 0;
    mida_lec_mp = 0;
    
    if ( valid[linea_mc] == 0) { //bloque dirty
        miss = 1;
        replacement = 0;
        countmiss++;
        if (LE == 0) { 
         lec_mp = 1;
         esc_mp = 0;
         mida_lec_mp = 32;
         cache[linea_mc] = tag;
        valid[linea_mc] = 1;
        }
        else if (LE == 1) {
            esc_mp = 1;
            lec_mp = 0;
            mida_esc_mp = 1;
        }
            
    }
    else if (cache[linea_mc] == tag) {
        miss = 0;
        replacement = 0;
        counthit++;
        if (LE == 0) { //hit de lectura
         lec_mp = 0;
         esc_mp = 0;
         mida_lec_mp = 0;
        }
        else if (LE == 1) { //hit de escritura
            esc_mp = 1;
            lec_mp = 0;
            mida_esc_mp = 1;
        }
    }
    else {
        miss = 1;
        countmiss++;
        if (LE == 0) { //miss de lectura
         replacement = 1;
         lec_mp = 1;
         esc_mp = 0;
         mida_lec_mp = 32;
         tag_out = cache[linea_mc];
         cache[linea_mc] = tag;
         
        }
        else if (LE == 1) { //miss de escritura
            replacement = 0;
            esc_mp = 1;
            lec_mp = 0;
            mida_esc_mp = 1;
        }
        
    }


	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  printf("Hits: %d, Miss: %d\n", counthit, countmiss);
  
}
