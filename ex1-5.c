#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    float fahr, celsius;
    
    fahr=UPPER;
    printf(" Fahrenheit Celsius Conversion \n\n");
    while(fahr >= LOWER) {
        celsius= (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr= fahr-STEP;
    } 
}