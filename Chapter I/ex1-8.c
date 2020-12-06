#include <stdio.h>
/* Program that counts the blanks, tabs and newlines*/
int main()
{
    int c, b, t, nl;
    b=0;
    t=0;
    nl=0;
    while((c=getchar()) != EOF){
        if(c==' ')
        ++b;
        if(c=='\t')
        ++t;
        if(c=='\n')
        ++nl;
    }
    printf("\n#_of_blanks \t%d\n#_of_tabs \t%d\n#_of_newlines \t%d\n", b, t, nl);
    
}