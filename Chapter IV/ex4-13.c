# include <stdio.h>
# include <string.h>

#define MAXLINE 100

int getlne(char s[], int lim);
void reverse(char s[]);


int main ()
{

char line[MAXLINE];

while(getlne(line,MAXLINE)>0){
    reverse(line);
    printf("%s",line);
}

return 0;    
}

void reverse(char s[])
{
    # define LEN strlen(s)
    
    static int i=0;
    
    int temp;
    
    if(i<(LEN-2)/2){
        temp=s[i];
        s[i]=s[LEN-2-i];
        s[LEN-2-i]=temp;
        i++;
        reverse(s);
    }

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
