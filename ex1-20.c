# include <stdio.h>
#define MAXLINE 1000

int getlne(char line[], int maxline);
void detab(char line[]);
void copy(char to[], char from[]);

int main ()
{

int len;

char line[MAXLINE];
char longest[MAXLINE];


while ((len = getlne(line, MAXLINE)) > 0){
      detab(line);
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

void detab(char line[])
{
    char temp[MAXLINE];
    int i,j,k,check;
    i=0;
    j=0;
    while(line[i]!='\0'){
        if(line[i]!='\t')
            temp[j]=line[i];
        else{
            check=j %10;
            if(check >5){
                for(k=0;k<10-check;k++,j++)
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

