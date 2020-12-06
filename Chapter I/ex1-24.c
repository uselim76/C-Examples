# include <stdio.h>
#define MAXLINE 100


int getlne(char line[], int maxline);
int check(char line[]);
int comment(char line[]);

int main ()
{

int len;

char line[MAXLINE];



while ((len = getlne(line, MAXLINE)) > 0){
      if (check(line)==0 && comment(line)==0)
                printf("%s",line);
      else
            printf("Syntax error\n");
}
return 0;    
}

int getlne(char s[], int lim)
{
    int c, i;
    for (i=0; i< lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i]=c;
    if(c== '\n') {
        s[i]=c;
        ++i;    
    }
    s[i]='\0';
    return i;   
}

int check(char line[])
{
    
    char syntax[10];
    int i,j,k,end,check;
    j=0; 
    syntax[0]=40;
    syntax[1]=91;
    syntax[2]=123;
    syntax[3]=39;
    syntax[4]=34;
    syntax[5]=41;
    syntax[6]=93;
    syntax[7]=125;
    syntax[8]=39;
    syntax[9]=34;
    for(k=0;k<5;++k){
        i=0;
        check=0;
        end=0;
    while(end==0){
        while(check==0 && end==0){
            if(line[i]=='\0')
                end=1;
            else 
                if(line[i]==syntax[k]){
                        check=1;
                        j++;
            }
            ++i;
        }
        while(check==1 && end==0){
            if(line[i]=='\0')
                end=1;
            else if(line[i]==syntax[k+5]){
                check=0;
                j--;
            }  
            ++i;  
        }    
    }
}
    return j;
}
    
int comment(char line[])
{
    
    int i,j,end,check;
    i=0;
    
    check=0;
    end=0;
    while(end==0){
        while(check==0 && end==0){          
            ++i;
            if(line[i]=='\0')
                end=1;
            else if(line[i-1]=='/' && line[i]=='*'){
                check=1;    
            }
        }
        while(check==1 && end==0){
            ++i;
            if(line[i]=='\0')
                end=1;
            else if(line[i-1]=='*' && line[i]=='/'){
                check=0;
                ++i;
            }    
        }    
    }
    return check;
}