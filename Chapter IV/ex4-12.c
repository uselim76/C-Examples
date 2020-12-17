# include <stdio.h>

#define MAXLINE 100


void itoa(int n, char s[]);


int main ()
{

int c=-127;

char line[MAXLINE];

itoa(c, line);

printf("%s\n",line);

return 0;    
}

void itoa(int n, char s[])
{
    static int i=0;
    int j;
    int temp;
    if (n<0){
        s[i++]='-';
        n=-n;
    }
    if(n/10)
        itoa(n/10,s);
    
    s[i++]=n%10 + '0';

    s[i]='\0';

    
}

