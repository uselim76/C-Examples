# include <stdio.h>
# include <ctype.h>
#define MAXLINE 100


int getlne(char line[], int maxline);
int htoi(char line[],int len);
int lower(int c);

int main ()
{

int len;

char line[MAXLINE];



while ((len = getlne(line, MAXLINE)) > 0)
      printf("%d\n",htoi(line,len));

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

int htoi(char s[],int len)
{
    int i,n,k;

    n=0;
    
    if(s[0]=='0' && lower(s[1])=='x')
        k=2;
    else
        k=0;
    
    for(i=k;i<len-1;++i){
        if(isdigit(s[i]))
            n=16*n + (s[i] -'0');
        else
            n=16*n + lower(s[i])- 87;   
    }

    return n;
}

int lower(int c){
    if(c>='A' && c<='Z')
        return c+'a' - 'A';
    else
        return c;
}
    

