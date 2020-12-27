# include <stdio.h>
# include <stdlib.h>
# include <string.h>


#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int tail);


int main(int argc, char *argv[])
{
    int nlines;
    int tail;
    char *p;

    if(argc!=2)
        printf("Wrong input pattern\n");
    else{
        if((*++argv)[0]!='-'){
            printf("Wrong input pattern\n");
            return 0;
        }
        else
            p=++(*argv);
    }   

    
    if(atoi(p)){
        tail=atoi(p);

    if(( nlines = readlines(lineptr,MAXLINES) ) >=0){
        if(tail<0)
            tail*=-1;
        if(tail>nlines)
            tail=nlines;
        writelines(lineptr,nlines,tail);
        return 0;
    }
    else
    {
        printf("error:input too big to sort\n");
        return 1;
    }
    }
      else{
        printf("Not a valid tail input\n");  
        return 0;
      }
}

#define MAXLEN 1000
int gwtline(char *s, int);
char *alloc(int);

int readlines(char *lineptr[],int numlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines=0;
    while((len=gwtline(line,MAXLEN))>0)
        if(nlines >= MAXLINES || (p=alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1]='\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
        }
        
    
    return nlines;        
}

void writelines(char *lineptr[], int nlines, int tail)
{
    int i;

    for (i=nlines-tail; i<nlines; i++)
        printf("%s\n", lineptr[i]);
}

int gwtline(char s[],int lim)
{
    int c,i;

    for(i=0;i<lim -1 && (c=getchar()) != EOF && c!='\n';++i)
        s[i]=c;
    if(c=='\n') {
        s[i]=c;
        ++i;
    }   
    s[i]='\0';
    return i;
}


#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;

char *alloc(int n)
{
    if(allocbuf+ALLOCSIZE- allocp >=n){
        allocp+=n;
        return allocp -n;
    }
    else
        return 0;
}