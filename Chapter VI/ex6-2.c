# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

# define MAXWORD 100
# define NKEYS (sizeof keytab / sizeof(keytab[0]))

struct tnode {
    char *word;
    int count;
    struct varnode *dict;
    struct tnode *left;
    struct tnode *right;
} ;

struct varnode {
    char *word;
    struct varnode *left;
    struct varnode *right;
};

# define NKEYS (sizeof keytab / sizeof(keytab[0]))

struct key {
    char *word;
    int count;
    struct tnode *keyword;
} keytab[]={
    "char",0, NULL,
    "double",0, NULL,
    "float",0, NULL,
    "int",0, NULL,
    "long",0,NULL
    };


int binsearch(char *, struct key *,int);


int getword( char *, int);
struct tnode *addtree(struct tnode *, char *, int comp);
void treeprint(struct tnode *);


int main(int argc, char *argv[])
{
    char word[MAXWORD];
    struct tnode *root;
    int c,n;
    float comp;

   if(argc==2)
        comp=atof(*++argv);
   else {
       printf("Please enter number of characters to be checked\n");
        return 0;
   }    

    while(getword(word,MAXWORD)!=EOF)
            if((n=binsearch(word, keytab,NKEYS))>=0)
                    while((c=getword(word,MAXWORD))!=';' && c!=EOF)
                        if(isalpha(word[0]))
                            keytab[n].keyword=addtree(keytab[n].keyword,word,comp);
            
    
    for(n=0;n<NKEYS;++n)
        if(keytab[n].keyword==NULL)
            printf("There are no matching variables for variable type %s\n",keytab[n].word);
        else{
            printf("For variable type %s\t list is as follows:\n",keytab[n].word);
            treeprint(keytab[n].keyword);
        }       
    return 0;

}

int binsearch(char *word, struct key tab[], int n )
{
    int cond;
    int low, high, mid;

    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if((cond=strcmp(word,tab[mid].word))<0)
            high=mid-1;
        else if(cond>0)
            low=mid+1;
        else
            return mid;
    }
    return -1;
}

struct tnode *talloc(void);
struct varnode *t2alloc(void);
char *strdp(char *,int n);
struct varnode *addtree_var(struct varnode *v, char *w);

struct tnode *addtree(struct tnode *p, char *w, int comp)
{
    int cond;
    char s[MAXWORD];
    strcpy(s,w);

    if(p==NULL){
        p=talloc();
        p->word=strdp(w,comp);
        p->dict=addtree_var(p->dict,w);
        p->count=1;
        p->left=p->right=NULL;
    }
    else if((cond=strncmp(w,p->word,comp))==0){
        p->count++;
        p->dict=addtree_var(p->dict,w);
    }
    else if(cond<0)
        p->left=addtree(p->left,w,comp);
    else
        p->right=addtree(p->right,w,comp);
    return p;
}

struct varnode *addtree_var(struct varnode *v, char *w)
{
    int cond;
    

    if(v==NULL){
        v=t2alloc();
        v->word=strdp(w,0);
        v->left=v->right=NULL;
    }
    else if((cond=strcmp(w,v->word))==0)
        ;
    else if(cond<0)
        v->left=addtree_var(v->left,w);
    else
        v->right=addtree_var(v->right,w);
    return v;
}


void treeprint2(struct varnode *);

void treeprint(struct tnode *p)
{
    if(p!=NULL){
        treeprint(p->left);
        printf("%4d %s\t",p->count,p->word);
        treeprint2(p->dict);
         printf("\n");
        treeprint(p->right);
       
}
}

void treeprint2(struct varnode *v)
{
    if(v!=NULL){
        treeprint2(v->left);
        printf("%s\t",v->word);
        treeprint2(v->right);
}
}



struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct varnode *t2alloc(void)
{
    return (struct varnode *) malloc(sizeof(struct varnode));
}

char *strdp(char *s, int n)
{
    char *p;
    p=(char *) malloc(strlen(s)+1);
    if(p!=NULL)
        if(n>0)
            strncpy(p,s,n);
        else
            strcpy(p,s);
    return p;
}

int getword(char *word,int lim)
{
    int c, d,getch(void);
    void ungetch(int);
    char *w=word;

    while(isspace(c=getch()))
        ;

    if(c!=EOF)
        *w++=c;
    if(isalpha(c) || c=='_' || c=='#'){
        for(;--lim>0;w++)
            if(!isalnum(*w=getch())){
                ungetch(*w);
                break;
        }
    }
    else if( c=='"'){
        *w--;
        for(;--lim>0;)
            if(c==EOF){
                break;
                return c;
            }
            else if((c=getch())!='\"')
                *w++=c;
            else
            {
                break;
            }  
    }
    else if( c=='/'){
        if((d=getch())=='*')
            while(((c=getch())!='*') || ((d=getch())!='/'))
                if(c==EOF)
                    return c;
                else if(d==EOF)
                    return d;
                else
                    ;
    }
    else
        {
        *w='\0';
        return c;
        }

    *w='\0';
    return word[0];
}



#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void)
{
    return (bufp>0) ? buf[--bufp] : getchar();

}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++]=c;
        
       
}