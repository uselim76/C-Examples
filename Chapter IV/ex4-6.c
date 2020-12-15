# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void clear(void);

int main()
{
    int type;
    double op2,op3;
    int op1;
    char s[MAXOP];
    int A=100;
    double recent;

    while((type=getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case 'A':
                push(A);
                break;
            case 'p':
                op2=pop();
                push(op2);
                break;
            case 'd':
                op2=2*pop();
                push(op2);
                break;
            case 'e':
                op2=exp(pop());
                push(op2);
                break;
            case 's':
                op2=sin(pop());
                push(op2);
                break;
            case 'x':
                op2=pop();
                op3=pop();
                op2=pow(op3,op2);
                push(op2);
                break;
            case 'w':
                op2=pop();
                op3=pop();
                push(op2);
                push(op3);
                break;
            case 'c':
                clear();
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2= pop();
                push(pop() -op2);
                break;
            case '%':
                op1=(int) pop();
                push((int) pop() % op1);
                break;            
            case '/':
                op2=pop();
                if(op2==0.0)
                    printf("error : zero divisor\n");
                else
                    push(pop() / op2);
                break;
            case 'R':
                printf("%g\n", recent);
                push(recent);
                break;            
            case '\n':
                recent=pop();
                printf("\t %.8g \n",recent);
                break;
            default:
                printf("error:unknown command %s\n", s);
                break;
        }
    }
    return 0;
    
}


#define MAXVAL 100
int sp=0;

double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, can't push %g\n",f);
       
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else{
        printf("error:stack empty\n");
        return 0.0;
    }
}

void clear(void)
{
    int i;
    for(i=sp;i>=0;--i)
        val[i]=0;
}

# include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c,check;
    

    while((s[0]=c=getch()) ==' '|| c=='\t')
        ;
    s[1]='\0';
    if(!isdigit(c) && c!='.' && c!='-')
        return c;
    i=0;
    if (c == '-')
    {
        check = getch();
        if (!isdigit(check)){
                ungetch(check);
                return c;
        }
        else{
            s[++i]=check;  
            while (isdigit(s[++i] = c = getch()))
                    ;   
        }   
    }
    else
        while (isdigit(s[++i] = c = getch()))
                    ;   


    if(c=='.')
        while(isdigit(s[++i] =c=getch()))
            ;
    s[i] ='\0';
    
    if (c!=EOF)
        ungetch(c);
    
        
    return NUMBER;
    
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