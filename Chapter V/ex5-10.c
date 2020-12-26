# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

#define MAXOP 100
#define NUMBER '0'


int getop(char s[]);
void push(double);
double pop(void);


int main(int argc, char *argv[])
{ 
    
    int type;
    double op2,op3;
    int op1;
    char *p;
    int len;
    
    
    if(argc<=1)
        printf("Wrong pattern: needed extra input\n");
    else
    while(--argc>0) {
        p=*++argv;
        type=getop(p);
        switch(type) {
            case NUMBER:
                push(atof(p));
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
            default:
                printf("error:unknown command %s\n", p);
                break;
        }
    
    
    
    
       }
    printf("\t %.8g \n",pop());
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


# include <ctype.h>



int getop(char ps[])
{
    int c,check;
    

    while((c=*ps++) ==' '|| c=='\t')
        ;
    
    if(!isdigit(c) && c!='.' && c!='-')
        return c;
    
    if (c == '-')
    {
        if (!isdigit(*ps)){
                *ps--;
                return c;
        }
        else{
            while (isdigit(*ps++))
                    ;   
            c=*ps++;  
        }

    }
    else{
        *ps--;
        while (isdigit(*ps))
                    ps++;   
         c=*ps;  
        }

    if(c=='.')
        while(isdigit(*++ps))
            ;
    
    
        
    return NUMBER;
    
}

