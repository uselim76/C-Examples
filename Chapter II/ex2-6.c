# include <stdio.h>

int setbits(int x, int p, int n, int y);

int main ()
{

int x, p, n,y;
x=223;
p=5;
n=2;
y=128;


printf("%d \n",setbits(x,p,n,y));


return 0;    
}

int setbits(int x, int p, int n, int y)
{
    int c;

    c= (x >>(p+1-n)) & ~(~0 << n); /* get n bit at position p of x*/
    y= y>> n;                       /* erase last n bits of y*/
    y= y<<n;                        /* move y to original bit length and fill last n bits with 0*/
    y= y | c;                       /* change last n bits of y*/

    return y;


}
