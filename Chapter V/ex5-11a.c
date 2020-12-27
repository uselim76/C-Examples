# include <stdio.h>
# include <stdlib.h>
#define MAXLINE 1000
#define MAXTAB  10

int getlne(char line[], int maxline);
void detab(char line[], char tab[]);
void copy(char to[], char from[]);

int main (int argc, char *argv[])
{

int len,tab;


char line[MAXLINE];
char longest[MAXLINE];
char a[MAXTAB];
char *p;

p=a;

while(--argc>0)
    *p++=atoi(*++argv);

*p='\0';

while ((len = getlne(line, MAXLINE)) > 0){
      detab(line,a);
      printf("%s",line);
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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) !='\0')
        ++i;
}

void detab(char line[],char *p)
{
    char temp[MAXLINE];
    int i,j,k,check,gap;
   
    i=0;
    j=0;
    while(line[i]!='\0'){
        if(line[i]!='\t')
            temp[j]=line[i];
        else{
            check=*p++;
            gap=check-j;
            if(gap <5){
                for(k=0;k<gap;k++,j++)
                    temp[j]=' ';
                j=j-1;
                }
            else 
                temp[j]=line[i];
            
        }    
        ++i;
        ++j;
        
    }
    temp[j]='\0';
    copy(line, temp);
}

