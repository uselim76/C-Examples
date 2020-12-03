# include <stdio.h>
#define MAXLINE 1000

int getlne(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char r[], int len);

int main ()
{

int len;

char line[MAXLINE];
char longest[MAXLINE];


while ((len = getlne(line, MAXLINE)) > 0){
    reverse(line,len);
    printf("%s\n", line);
}
return 0;    
}

int getlne(char s[], int lim)
{
    int c, i;
    for (i=0; i< lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i]=c;
    s[i]='\0';
    return i;   
}

void reverse(char r_line[], int len)
{
    int i;

    char temp[len+1];
    for(i=0;i<len;++i)
        temp[i]=r_line[len-i-1];
    temp[i] = '\0';
    copy(r_line, temp);
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) !='\0')
        ++i;
}