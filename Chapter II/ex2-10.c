# include <stdio.h>

int lower(int c);

int main ()
{

int c='A';
c=lower(c);
putchar(c);
printf("\n");

return 0;    
}


int lower(int c){
    return (c>='A' && c<='Z') ? c+'a' - 'A'  : c;   
}
    

