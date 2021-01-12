# include <stdio.h>
# include <ctype.h>
# include <string.h>



int main(int argc,char *argv[])
{
    int c;

    
    if(strcmp("upper",argv[0])==0){
        while((c=getchar())!=EOF)
            putchar(toupper(c));
        return 1;
    }
    else if(strcmp("lower",argv[0])==0){
        while((c=getchar())!=EOF)
            putchar(tolower(c));
        return 1;
    }
    return 0;
}   
