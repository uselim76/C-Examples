# include <stdio.h>
#define MAXLINE 1000

int getlne(char line[], int maxline);
void copy(char to[], char from[]);

int main ()
{

int len;
char line[MAXLINE];
char longest[MAXLINE];


while ((len = getlne(line, MAXLINE)) > -1)
        printf("%s", line);

return 0;    
}

int getlne(char s[], int lim)
{
    #define IN 1
    #define OUT 2
    
    int c, i,j,state;
    j=0;
    for (i=0; i< lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i){
        s[i]=c;
        if (c=='\t' ||  c==' '){
            state =IN;
            ++j;
        }
        else{
            j=0;
            state=OUT;
        }
    }
    if(c== '\n' && state==IN) {
        i=i-j;
        s[i]=c;
        ++i;    
    }
    else if(c=='\n' && state==OUT)
        {
        s[i]=c;
        ++i;
        }
    s[i]='\0';
    if(c == EOF)
        i=-1;
    return i;   
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) !='\0')
        ++i;
}