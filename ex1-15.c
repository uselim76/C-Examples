# include <stdio.h>

int heat(int fahr);

int main ()
{

int i;

for(i=0; i <=300; i=i+20)
    printf("%3d\t %4d \n", i, heat(i));
    return 0;
}

int heat(int fahr)
{
    int p; 
    p=(fahr - 32) * (5.0 / 9.0);
    return p;    
}