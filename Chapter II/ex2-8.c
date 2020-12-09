# include <stdio.h>


int rightrot(int x, int n);

int main ()
{

int x,  n;
x=127;

n=2;



printf("%d \n",rightrot(x,n));


return 0;    
}

int rightrot(int x, int n)
{
    int c,i,d;

    c= x & ~(~0 << (n)); /* get n bits at right of x*/    
    
    i=0;
    d=x;
    while(d>0){
        ++i;                /* find bit length of x */
        d= d>>1;
    }
    x = x >> n;                       /* erase last n bits*/
   
    c= c <<(i-n);              /* get bits into left most position to change*/
    
       
    x=x+c;
    return x;


}
