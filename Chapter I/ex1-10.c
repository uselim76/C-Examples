# include <stdio.h>
/* Program that copies input to output replacing tab with \t, blnaks with \b and backslash with \\ */
int main ()
{
int c;
while ((c=getchar()) != EOF){
    if (c=='\t'){
        putchar('\\');
        putchar('t');
        }
    else if (c==' '){
        putchar('\\');
        putchar('b');
        }
    else if (c=='\\'){
        putchar('\\');
        putchar('\\');
        }
    else
        putchar(c);
}
 }