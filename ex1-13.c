# include <stdio.h>
/* write a program that prints a histogram of the lenghts of the words*/
int main ()
{
#define IN 1
#define OUT 0
#define WORDLENGTH 10

int c,i,j,nc,state; 
int nw[WORDLENGTH];

for(i=0;i<WORDLENGTH;++i)
    nw[i]=0;
nc=0;
state=OUT;
while ((c=getchar()) != EOF){
    if (c !='\t' && c !=' ' && c !='\n'){
        state=IN;
        ++nc;
        }
    else if (state==IN){
        state=OUT;
        ++nw[nc-1];
        nc=0;
    }
}
printf("\n");
for(i=0;i<WORDLENGTH;++i){
    printf("#_of_words  with length %d\t", i+1);
    for(j=0;j<nw[i];++j)
        printf("X"); /* print horizontal = for each word*/
    printf("\n");    
} 
/* print vertical || for each word*/
printf("Word Length Histogram in Vertical Order\n\n");
for(i=0;i<WORDLENGTH;++i){
    for(j=0;j<WORDLENGTH;++j){
        if(nw[j]==0)
            printf(" ");
        else
            {
            printf("X");
            --nw[j];
            }
    }        
    printf("\n");
 } 
}