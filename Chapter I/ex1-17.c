# include <stdio.h>
#define MAXLINE 1000
#define PRINTLENGTH 80

int getlne(char line[], int maxline);
void copy(char to[], char from[]);

int main ()
{

int len;
int max;
char line[MAXLINE];
char longest[MAXLINE];

max = 0;
while ((len = getlne(line, MAXLINE)) > 0)
    if (len > PRINTLENGTH) {
        printf("%s\n", line);
    }

return 0;    
}

int getlne(char s[], int lim)
{
    int c, i;
    for (i=0; (c=getchar()) !=EOF && c!='\n'; ++i)
        if(i<lim)
           s[i]=c;
    if(i<lim && c== '\n') {
        s[i]=c;
        s[++i]='\0';    
    }
    if(i>=lim)
        s[lim-1]='\0';
    return i;   
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) !='\0' )
        ++i;
}