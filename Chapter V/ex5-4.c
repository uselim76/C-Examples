# include <stdio.h>

#define MAXLINE 100


int getlne(char line[], int maxline);
int str_end(char *s, char *t);


int main ()
{

int len=0;

char line1[MAXLINE];
char line2[MAXLINE];


while ((len = getlne(line1, MAXLINE)) > 0 && (len = getlne(line2, MAXLINE)) > 0)
      if(str_end(line1,line2)==1)
            printf("Second string appears at the end of first string\n");
        else
            printf("Second string does not appear at the end of first string\n");


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


int str_end(char *s, char *t)
{
        int check=0;

        while(*t++)
            check++;
        t-=++check;
        while(*s++)
            ;
        s-=check;
               
        while(*t++==*s++)
                ;
        if(*t=='\0')
            return 1;
        else
            return 0;
}


