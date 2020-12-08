# include <stdio.h>

#define MAXLINE 100


int getlne(char line[], int maxline);
int any(char line1[], char line2[]);

int main ()
{

int len;

char line1[MAXLINE];
char line2[MAXLINE];


while ((len = getlne(line1, MAXLINE)) > 0 && (len = getlne(line2, MAXLINE)) > 0)
      printf("%d\n",any(line1,line2));


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

int any(char line1[], char line2[])
{
    int i,j,k;
    k=0;
    for(j=0;line2[j]!='\0' && k==0 ;++j)
            for(i=0;line1[i]!='\0' && k==0  && line2[j]!='\n';++i)
                    if(line1[i]==line2[j]){
                            k=1;
        }

    if (k==1)
        return i;
    else
        return -1;

}

