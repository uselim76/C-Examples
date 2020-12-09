# include <stdio.h>

int invert(int x, int p, int n);

int main ()
{

int x, p, n;
x=128;
p=5;
n=2;



printf("%d \n",invert(x,p,n));


return 0;    
}

int invert(int x, int p, int n)
{
    int c,d;

    c= (x >>(p+1-n)) & ~(~0 << n); /* get n bit at position p of x*/    
    d= ~(~0 << n);
    c = d -c ;                       /* invert the bits*/
   
    c = c << (p+1 -n);              /* get bits into position to change*/
    
    d = x & ~(~0 << (p+1 -n));       /* get rightmost bits of x*/
    
    c=c+d;                          /* prepare comparion bit for position p and before of x*/
    
    x = x >> (p+1);                 /* erase position p and before of x*/
    
    x = x << (p+1);
    
    x=x+c;
    return x;


}
