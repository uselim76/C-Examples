# include <stdio.h>
/*Print a histogram of different characters of input*/
int main ()
{
#define max_char 100 /* maximum number of different characters*/
#define max_freq 3000 /* maximum frequency for each character*/

int i,c, hist[max_char];
int dict[max_char];
int uniq_char;
int check=0;

for(i=0;i<max_char;++i){/* Initialize arrays */
    hist[i]=0;
    dict[i]=0;
}

uniq_char=0;
while((c=getchar()) != EOF){
    i=0;
    while(c!=dict[i] && i< uniq_char)
        ++i;
    if (i==uniq_char) {
        dict[uniq_char]=c;
        ++hist[uniq_char];
        ++uniq_char;
    }
    else
    {
        ++hist[i];
    }
}

printf("Frequency of characters \n");
for(i=0;i<uniq_char;++i){
    if(dict[i] == '\n')
        printf("New line\t");
    else if(dict[i]=='\t')
        printf("Tabstop \t");
    else if(dict[i]==' ')
        printf("Blanks \t\t");
    else{
        putchar(dict[i]);
        printf("\t\t");
        }
    printf("%d\n", hist[i]); /* print horizontal = for each word*/
     
}     
 }