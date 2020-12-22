# include <stdio.h>

#define MAXLINE 100


int getlne(char line[], int maxline);
void str_cat(char *s, char *t);


int main ()
{

int len=0;

char line1[MAXLINE];
char line2[MAXLINE];


while ((len = getlne(line1, MAXLINE)) > 0 && (len = getlne(line2, MAXLINE)) > 0){
      str_cat(line1,line2);
      printf("%s",line1);
}

return 0;    
}

int getlne(char s[], int lim)
{
    int c, i;
    for (i=0; i< lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i]=c;
    if(c== '\n') {
        s[i]=c;
        ++i;    
    }
    s[i]='\0';
    return i;   
}


void str_cat(char *s, char *t)
{
        while(*s++)
        ;
        s-=2;
        while(*t)
                *s++=*t++;
        *s='\0';
}


