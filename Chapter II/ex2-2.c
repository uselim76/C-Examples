# include <stdio.h>
# define MAXLINE 100

int c,i;
char s[MAXLINE];


int main ()
{ 
for (i=0; ((i<MAXLINE-1) *((c=getchar()) !='\n')*(c!=EOF)); ++i)
          s[i]=c;
s[i]='\0';

printf("%s\n", s);

return 0;    
}
