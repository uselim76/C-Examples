# include <stdio.h>
# define SIZE 10

int main(){
    int n, array[SIZE], getint(int *);

    for(n=0;n<SIZE && getint(&array[n])!=EOF;++n)
            ;
    --n;
    printf("\n");
    while(n>=0){
        printf("%d \n", array[n--]);
    }


}

int getch(void);
void ungetch(int);

# include <ctype.h>

int getint( int *pn)
{
    int c, sign;

    while(isspace(c=getch()))
        ;
    
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
        ungetch(c);
        return 0;
    }

    sign=(c=='-') ?-1:1;
    if(c=='+' || c=='-')
        c=getch();
    if(c==' ')
        c=getch();
    for(*pn=0;isdigit(c);c=getch())
        *pn=*pn * 10 +(c -'0');
    *pn *=sign;
    if(c!=EOF)
        ungetch(c);
    return c;

}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void)
{
    return (bufp>0) ? buf[--bufp] : getchar();

}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++]=c;
        
       
}