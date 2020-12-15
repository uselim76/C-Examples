# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXLINE 1000

char line[MAXLINE];
int read_index;

int getlne(char line[], int max);
int getop(char s[]);
void push(double);
double pop(void);



int main()
{
    int type;
    double op2,op3;
    int op1;
    char s[MAXOP];
    extern char line[MAXLINE];
    int len;
    extern int read_index;

    
    

while((len=getlne(line, MAXLINE))>0){
    read_index=0;
    while(read_index<len) {
        type=getop(s);
        switch(type) {
            case NUMBER:
                push(atof(s));
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
            case '\n':
                printf("\t %.8g \n",pop());
                break;
            default:
                printf("error:unknown command %s\n", s);
                break;
        }
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

# include <ctype.h>


int getop(char s[])
{

    int i,c,check;
    extern int read_index;
    extern char line[MAXLINE];

        while((s[0]=c=line[read_index++]) ==' '|| c=='\t')
                ;
        s[1]='\0';
        if(!isdigit(c) && c!='.' && c!='-')
            return c;
        i=0;
        if (c == '-')
            {
            check = line[read_index];
            if (!isdigit(check)){
                return c;
            }
            else{
                 s[++i]=line[read_index++];  
                while (isdigit(s[++i] = c = line[read_index++]))
                       ;   
            }   
            }
        else
            while (isdigit(s[++i] = c = line[read_index++]))
                    ;   

        if(c=='.')
            while(isdigit(s[++i] =c=line[read_index++]))
                 ;
        s[i] ='\0';
        read_index--;
          
        return NUMBER;
        
       
}


int getlne(char s[], int lim)
{
    int c,i;
    i=0;
    while(--lim>0 && (c=getchar())!=EOF && c!= '\n')
        s[i++]=c;
    if(c=='\n')
        s[i++]=c;

    s[i]='\0';
    return i;    
}

