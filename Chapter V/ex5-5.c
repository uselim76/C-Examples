# include <stdio.h>

#define MAXLINE 100


int getlne(char line[], int maxline);
int str_ncmp(char *s, char *t,int n);
void str_ncat(char *s, char *t,int n);
void str_ncpy(char *s, char *t,int n);

int main ()
{

int len=0;
int n=5;
int c;

char line1[MAXLINE];
char line2[MAXLINE];

while ((len = getlne(line1, MAXLINE)) > 0 && (len = getlne(line2, MAXLINE)) > 0){
    str_ncat(line1,line2, n);
    printf("%s",line1);
}

while ((len = getlne(line1, MAXLINE)) > 0 && (len = getlne(line2, MAXLINE)) > 0){
    str_ncpy(line1,line2, n);
    printf("%s",line1);
}

while ((len = getlne(line1, MAXLINE)) > 0 && (len = getlne(line2, MAXLINE)) > 0){
    c=str_ncmp(line1,line2, n);
    if(c==0)
        printf("First %d characters are same\n", n);
    else if(c<0)
        printf("First string's %d characters are before second string\n",n);
    else
        printf("First string's %d characters are after second string\n",n);
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


void str_ncat(char *s, char *t,int n)
{
        int i=0;

        while(*s++)
        ;
        s-=2;
        for(i=0;i<n && *t ;++i)
                *s++=*t++;
        *s++='\n';
        *s='\0';
}

void str_ncpy(char *s, char *t,int n)
{
        int i=0;

        for(i=0;i<n && *t ;++i)
                *s++=*t++;
        
}

int str_ncmp(char *s, char *t,int n)
{
        int i=0;

        for(i=0;i<n  && *s++== *t++;++i)
                ;
        if(i==n)
            return 0;
        else
            return *(--s) - *(--t);
}