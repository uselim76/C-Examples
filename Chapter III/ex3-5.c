# include <stdio.h>
# include <limits.h>
#define MAXLINE 100


void itob(long n, char s[], int b);


int main ()
{

long c=LONG_MIN;

char line[MAXLINE];

itob(c, line,10);

printf("%s\n",line);

return 0;    
}

void itob(long n, char s[],int b)
{
    int i=0;
    int j;
    int temp;
    int max_check=0;
    int sign=((n>0) ? 1: -1);
    if(n>LONG_MIN)
        n*=sign;
    else
        {
            max_check=1;
            n+=1;
            n*=sign;
        }
    
    if(n==0)
       s[i++]='0';
    else{
        if(b==16)
          while(n>0){
                if(n%b >9)
                    s[i++]='a'+n%b -10;
                else  
                    s[i++]= n%b +'0'; 
                n/=b;
                } 
         
        else
            while(n>0){
                s[i++]= n%b +'0';
                n/=b;
                }    
         }  
    if(sign==-1)
            s[i++]='-';

    if(max_check)
        s[0]=s[0]+1;      
    s[i]='\0';
    --i;
    for(j=0;j<=i;++j,--i){
        temp=s[j];
        s[j]=s[i];
        s[i]=temp;
    }
    
}

