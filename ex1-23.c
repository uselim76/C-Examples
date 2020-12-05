# include <stdio.h>
#define MAXLINE 100


int getlne(char line[], int maxline);
void comment(char line[]);
void copy(char to[], char from[]);

int main ()
{

int len;

char line[MAXLINE];



while ((len = getlne(line, MAXLINE)) > 0){
      comment(line);
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


void comment(char line[])
{
    char temp[MAXLINE];
    int i,j,end,check;
    i=0;
    j=0;
    check=0;
    end=0;
    while(end==0){
        while(check==0 && end==0){
            temp[j]=line[i];
            ++j;
            ++i;
            if(line[i]=='\0')
                end=1;
            else if(line[i-1]=='/' && line[i]=='*'){
                check=1;
                j=j-1;
            }
        }
        while(check==1 && end==0){
            ++i;
            if(line[i]=='\0')
                end=1;
            else if(line[i-1]=='*' && line[i]=='/'){
                check=0;
                ++i;
            }    
        }    
    }
    temp[j]='\0';
    copy(line, temp);
}
    
    

