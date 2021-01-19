# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define MAXLINE 1000

int gwtline(char *s,int lim);
int file_lookup(FILE *, char *);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    FILE *fp;
    char *pattern;
    long lineno=0;
    int c;
    int found=0;
    char *prog=argv[0];

    if(argc==1)
        printf("Usage: find pattern (optional:from file)\n");
    else if(argc==2){
        pattern=argv[1];
        while(gwtline(line,MAXLINE)>0){
            lineno++;
            if((strstr(line,pattern)!=NULL )){
                printf("%ld:",lineno);
                printf("%s",line);
                found++;
            }
        }
    }
    else
        {
            pattern=*++argv;
            while(--argc>1)
                if((fp=fopen(*++argv,"r"))==NULL)
                    fprintf(stderr, "%s: can not open %s\n",prog, *argv);
                else
                {
                    found=file_lookup(fp,pattern);
                    if(found)
                        fprintf(stdout, "%s: has found pattern (%s) at file %s\n",prog,pattern, *argv);
                    else
                        fprintf(stdout, "%s: has not found pattern (%s) at file %s\n",prog,pattern, *argv);

                }
                
        }
    
    return found;
    
}

int file_lookup(FILE *fp, char *pattern)
{
    char line[MAXLINE];
    

    while(fgets(line,MAXLINE,fp)!=NULL)
        if(strstr(line,pattern))
            return 1;
    if(strstr(line,pattern))
            return 1;
    else
        return 0;
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