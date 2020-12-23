# include <stdio.h>

#define MAXLINE 100


int getlne(char *s, int maxline);
void reverse(char *s);
int strindex(char *s, char *t);

int main ()
{
char line[MAXLINE];
char *s, *t;

s=line;   
char searchfor[]="selim";
t=searchfor;

    int found =0;
    int index = -1;
    
    while(getlne(s, MAXLINE)>0)
        if( (index=(strindex(s, t))) >=0 ) {
            printf("%s", line);
            printf("Rightmost Index is %d \n",index);
            found++;
        }
    return found;
}

int getlne(char *s, int lim)
{
    int c, i;
    for (i=0; i< lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        *s++=c;
    if(c== '\n') {
        *s++=c;
          ++i;
    }
    *s='\0';
    return i;   
}

void reverse(char *s)
{
    int i=0;
    int len=0;
    int temp;

    while(*s++)
        ++len;
    s=(s-len-1);
    for(i=0; i<(len-1)/2;++i){
        temp=*(s+i);
        *(s+i)=*(s+len-2-i);
        *(s+len-2-i)=temp;
    }



}
int strindex(char *s, char *t)
{
    int i, j,index;

    index=-1;
    j=0;
    i=0;
    while(*s){
        if(*s==*t){
                for(j=0; *(t+j) !='\0'&& *(s+j)==*(t+j); ++j, ++i)
                            ;
                if(*(t+j)=='\0')
                        index=i-j+1;
                
                s=s+j;
                j=0;
                }
        else{
         *s++;
         ++i;
        }
    }

    return index;
    
}            