# include <stdio.h>
# define MAXLINE 1000

int getlne(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[]="selim";

int main()
{
    char line[MAXLINE];
    

    int found =0;
    int index = -1;
    
    while(getlne(line, MAXLINE)>0)
        if( (index=(strindex(line, pattern))) >=0 ) {
            printf("%s", line);
            printf("Rightmost Index is %d \n",index);
            found++;
        }
    return found;
}

int getlne(char s[], int lim)
{
    int c,i;
    i=0;
    while(--lim>0 && (c=getchar())!=EOF && c!= '\n')
        s[i++]=c;
    if(c=='\n')
        s[i++]=c;

    s[i]='\0';
    return i;    
}

int strindex(char s[], char t[])
{
    int i, j,index;

    index=-1;
    j=0;
    i=0;
    while(s[i]!='\0'){
        if(s[i]==t[j]){
                for(j=0; t[j]!='\0'&& s[i]==t[j]; ++j, ++i)
                            ;
                if(t[j]=='\0')
                        index=i-j+1;
                --i;
                }
        j=0;
        ++i;
    }

    return index;
    
}            





