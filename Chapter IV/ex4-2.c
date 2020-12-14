# include <stdio.h>
# include <ctype.h>

# define MAXLINE 1000

int getlne(char line[], int max);

int main()
{
    
 
    char line[MAXLINE];
    double sum=0;; 
   
    double atof(char s[]);
    
    sum=0;

    while(getlne(line, MAXLINE)>0)
        printf("\t %.2f \n", sum+=atof(line));

    return 0;    
    
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

double atof(char s[])
{
    double val, power, expo;
    int i, sign,j, sign_expo,k;
    expo=1;
    sign_expo=1;

    for(i=0; isspace(s[i]);i++)
        ;
    sign = (s[i]=='-') ? -1 : 1;

    if(s[i]=='+' || s[i]=='-')    
            i++;

    for(val=0.0;isdigit(s[i]);i++) 
        val=10.0*val +(s[i]-'0');

    if(s[i]=='.')
        i++;

    for(power=1.0;isdigit(s[i]);i++)    {
        val=10.0 * val+(s[i]-'0');
        power*=10;
    }
    if(s[i]=='e' || s[i]=='E')
            i++;
    if(s[i]=='-'){
        sign_expo=-1;
        i++;
    }
    
    for(j=0;isdigit(s[i]);i++) 
            j=10*j +(s[i]-'0');   
        
    if(sign_expo==-1)
        for(k=0;k<j;++k)
            expo/=10;
    else
        for(k=0;k<j;++k)
            expo*=10;
        
    return sign*val*expo/power;
    }





