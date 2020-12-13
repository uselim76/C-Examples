# include <stdio.h>

#define MAXLINE 100


int getlne(char line[], int maxline);
void escape(char line1[], char line2[]);

int main ()
{

int len;

char s_line[MAXLINE];
char t_line[MAXLINE];

while ((len = getlne(s_line, MAXLINE)) > 0){
      escape(s_line,t_line);
      printf("%s\n",t_line);
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

void escape(char s[], char t[])
{
    int i,j;
    j=0;
    i=0;
    while(s[i] !='\0'){
       switch (s[i]) {
            case '\n':
                t[j]='\\';
                ++j;
                t[j]='n';
                break;
            case '\t':
                t[j]='\\';
                ++j;
                t[j]='t';
                break;
            default:
                t[j]=s[i];
                break;
        }
        
        ++i;
        ++j;

        }
    t[j]='\0';

    }

