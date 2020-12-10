# include <stdio.h>


int bitcount(int x);

int main ()
{

int x;
x=-4;

printf("%d \n",bitcount(x));


return 0;    
}

int bitcount(int x)
{
    int b;

    for(b=0;x!=0;++b)
        x&= (x-1);
    
    return b;


}
