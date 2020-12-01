# include <stdio.h>
/* write a program that writes its input one word per line*/
int main ()
{
#define IN 1
#define OUT 0

int state,c;
state=IN;
while ((c=getchar()) != EOF){
    
    if (c=='\t' || c==' ' || c=='\n'){
        if(state==IN)
                putchar('\n'); /* print a new line if we reach end of the word*/
        state=OUT;   
        }
    else 
        state=IN;
    if (state==IN)
        putchar(c);
    }
    
 }