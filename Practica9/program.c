#include <stdio.h>


int main () {
    double x = 665857;
    double y = 470832;
    double z = x*x*x*x - 4*(y*y*y*y) - 4*(y*y);
    float x1 = 665857;
    float y1 = 470832;
    float z1 = x1*x1*x1*x1 - 4*(y1*y1*y1*y1) - 4*(y1*y1);
    long long int x2 = 665857;
    long long int y2 = 470832;
    long long int z2 = x2*x2*x2*x2 - 4*(y2*y2*y2*y2) - 4*(y2*y2);
    
    printf("Doble precisión: %lf, simple precisión: %f, enteros: %lld\n",z,z1,z2);
}
