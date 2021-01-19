# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc,char *argv[])
{
    FILE *fp1,*fp2;
    void filecompare(FILE *, FILE *);
    char *prog=argv[0];
    
   if(argc!=3){
        fprintf(stderr, "Please enter correct number of files to compare\n");
        exit(1);
    }
    else 
        {
            if((fp1=fopen(*++argv,"r"))==NULL){
                fprintf(stderr, "%s: can not open %s\n",prog, *argv);
                exit(2);
            }
            if((fp2=fopen(*++argv,"r"))==NULL){
                fprintf(stderr, "%s: can not open %s\n",prog, *argv);
                exit(3);
            }
            else{
                filecompare(fp1,fp2);
                fclose(fp1);
                fclose(fp2);
            }
        }   
    
    exit(0);
}
# define MAXCHAR 100

void filecompare(FILE *fp1, FILE *fp2)
{
    char line1[MAXCHAR];
    char line2[MAXCHAR];
    int i;
    
    i=1;
    while((fgets(line1,MAXCHAR,fp1)) !=NULL){
        if((fgets(line2,MAXCHAR,fp2)) ==NULL )
            break;
        if(strcmp(line1,line2)!=0){
                printf(" Lines they differ\n");
                printf("Line in first file: %s",line1);
                printf("Line in second file: %s",line2);
                printf("Line %d\n",i);
                break;
            }
        else
             ++i;
        }
}