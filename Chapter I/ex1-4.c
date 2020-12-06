#include <stdio.h>
int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower=0;
    upper=100;
    step=5;

    celsius=lower;
    printf(" Celsius Fahrenheit  Conversion \n\n");
    while(celsius <= upper) {
        fahr= (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius= celsius+step;
    } 
}