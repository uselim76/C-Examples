# include <stdio.h>
# include <stdlib.h>
#define MAXLINE 1000


int getlne(char line[], int maxline);
void detab(char line[],int tab[]);
void copy(char to[], char from[]);

int main (int argc, char *argv[])
{

int len,c;


char line[MAXLINE];
char longest[MAXLINE];
int a[2];




if(argc!=3)
    printf("Wrong usage: please use -m +n format\n");

else
    while(--argc>0 && ((*++argv)[0]=='-' || *argv[0]=='+')){
        c=*argv[0];
        switch(c) {
            case '-':
                a[0]=atoi(*argv) * -1;
                break;
            case '+':
                a[1]=atoi(*argv);
                break;
            default:
                printf("Illegal option\n");
                argc=0;
                break;

        }
    }

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

void detab(char line[],int tab[])
{
    char temp[MAXLINE];
    int i,j,k,m,n,check;
    m=tab[0];
    n=tab[1];
   
    i=0;
    j=0;
    
    while(line[i]!='\0') { 
        if(line[i]!='\t')
            temp[j]=line[i];
        else{
            if(j>m){
            check=(j-m) %n;
            if(check >5){
                for(k=0;k<10-check;k++,j++)
                    temp[j]=' ';
                j=j-1;
                }
            else 
                temp[j]=line[i];
            }
            else{
            check=j %m;
            if(check >5){
                for(k=0;k<10-check;k++,j++)
                    temp[j]=' ';
                j=j-1;
                }
            else 
                temp[j]=line[i];
            
            }    

        }    
        ++i;
        ++j;
        
    }
    temp[j]='\0';
    copy(line, temp);
}

