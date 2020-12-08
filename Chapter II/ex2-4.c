# include <stdio.h>

#define MAXLINE 100


int getlne(char line[], int maxline);
int has_contain(char line[], int c);
void squeeze(char s1[], char s2[]);

int main ()
{

int len;

char line1[MAXLINE];
char line2[MAXLINE];


while ((len = getlne(line1, MAXLINE)) > 0 && (len = getlne(line2, MAXLINE)) > 0){
      squeeze(line1,line2);
      printf("%s\n",line1);
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

void squeeze(char s1[], char s2[])
{
    int i,j;
    
    for(i=j=0; s1[i]!='\0';i++)
            if(!has_contain(s2, s1[i])){
                    s1[j]=s1[i];
                    j++;
                }
    s1[j]='\0';  
    
}

int has_contain(char line[], int c)
{
    int i,k;
    k=0;
    for(i=0;line[i]!='\0' && k==0 ;++i)
        if(line[i]==c){
            k=1;
        }

    return k;

}

