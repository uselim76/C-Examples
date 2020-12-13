# include <stdio.h>

#define MAXLINE 100


int getlne(char line[], int maxline);
void expand(char line1[], char line2[]);

int main ()
{

int len;

char s_line[MAXLINE];
char t_line[MAXLINE];

while ((len = getlne(s_line, MAXLINE)) > 0){
      expand(s_line,t_line);
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

void expand(char s[], char t[])
{
    int i,j,k;
    j=0;
    i=0;
    while(s[i] !='\0'){
       switch (s[i]) {
            case '-':
                ++i;
                if( t[j-1] < s[i]){
                        k=s[i-2]+1;
                        while(k <= s[i]){
                                t[j]=k;
                                ++k;
                                ++j;
                                }
                }
                else if (t[j-1] > s[i]){
                        k=s[i-2]-1;
                        while(k >= s[i]){
                                t[j]=k;
                                --k;
                                ++j;
                                }
                }
                else
                    ;
                --j;
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

