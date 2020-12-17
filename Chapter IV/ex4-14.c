# include <stdio.h>

# define swap(t,x, y) { t temp; temp=y; y=x;   x=temp;}

int modular_reverse(int x,int y);


int main ()
{

int x=5;
int y=2;
    printf("%d\n",x%y);
    printf("%d\n", modular_reverse(x,y));



return 0;    
}

int modular_reverse(int x,int y)
{
    swap(int,x,y);
    return  x%y;
}