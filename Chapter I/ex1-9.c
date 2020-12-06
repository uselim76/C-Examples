# include <stdio.h>

/* program that replaces ne or more blanks with one blank*/
int main ()
{

int c,buffer;
buffer=0;

while ((c=getchar()) != EOF)
    if (((c==' ')+ (buffer==' '))<2)
        putchar(c), buffer=c;
 }