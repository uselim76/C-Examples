# include <stdio.h>
# include <string.h>


#define MAXLINES 5000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char []);
void writelines(char *lineptr[], int nlines);

void q_sort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    
    char array_of_lines[ALLOCSIZE];

    if(( nlines = readlines(lineptr,MAXLINES,array_of_lines) ) >=0){
       q_sort(lineptr, 0 , nlines-1);
       writelines(lineptr,nlines);
        return 0;
    }
    else
    {
        printf("error:input too big to sort\n");
        return 1;
    }
       
}

#define MAXLEN 1000
int gwtline(char *s, int);
char *alloc(int);
void str_cat(char *s, char *t);

int readlines(char *lineptr[],int numlines,char line_array[])
{
    int len, nlines;
    
    char *p, line[MAXLEN];
    p=line_array;
    nlines=0;
    while((len=gwtline(line,MAXLEN))>0)
        if(nlines >= MAXLINES || line_array+ ALLOCSIZE -p < len )
            return -1;
        else
        {
            line[len-1]='\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
            p+=len;
        }
        
    
    return nlines;        
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i=0; i<nlines; i++)
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


void q_sort(char *v[], int left, int right)
{
    int i,last;
    void swap(char *v[],int i, int j);

    if(left>=right)
        return;

    swap(v, left, (left+right)/2);
    last=left;
    for(i=left+1;i<=right;i++)
        if(strcmp(v[i],v[left])<0)
            swap(v,++last,i);
            
    swap(v,left,last);
    q_sort(v,left,last-1);        
    q_sort(v,last+1,right);

}

void swap( char *v[],int i, int j)
{
    char *temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}


