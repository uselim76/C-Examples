# include <stdio.h>

#define MAXLINE 100


void itoa(int n, char s[], int len);


int main ()
{

int c=-127;
int len=10;

char line[MAXLINE];

itoa(c, line,len);

printf("%s\n",line);

return 0;    
}

void itoa(int n, char s[], int len)
{
    int i=0;
    int j;
    int temp;
    int sign=((n>0) ? 1: -1);
    n*=sign;
    if(n==0)
       s[i++]='0';
    else 
       while(n>0){
                s[i++]= n%10 +'0';
                n/=10;
        }
    if(sign==-1)
            s[i++]='-';
    for(j=0;j<len-i;++j)
            s[i+j]=' ';
    s[i+j+1]='\0';
    i+=j-1;
    for(j=0;j<=i;++j,--i){
        temp=s[j];
        s[j]=s[i];
        s[i]=temp;

    }

    
}

