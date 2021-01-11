# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

# define MAXWORD 100
# define HASHSIZE 101

struct nlist {
    char *name;
    char *defn;
    struct nlist *next;
    
} ;

static struct nlist *hashtab[HASHSIZE];

int getword( char *, int);
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name,char *defn);
struct nlist *undef(char *name);
void hash_print(struct nlist *);

int main()
{
    char word[MAXWORD];
    char word1[MAXWORD];
    struct nlist *table;
    int i;
   
    
    table=NULL;
    while((i=getword(word,MAXWORD))!=EOF)
            if(i=='#') {
                i=getword(word,MAXWORD);
                if(i!=EOF && (strcmp(word,"define")==0)){
                    i=getword(word,MAXWORD);
                    i=getword(word1,MAXWORD);
                    table=install(word,word1);
                }
            }
    printf("Definitions before deletion\n");
    for(i=0;i<HASHSIZE;++i)
        if(hashtab[i]!=NULL)
            hash_print(hashtab[i]);
    
    char name[]="IN";
    table=undef(name);
    printf("Definitions after deletion\n");
    for(i=0;i<HASHSIZE;++i)
        if(hashtab[i]!=NULL)
            hash_print(hashtab[i]);

    return 0;

}

char *strdp(char *s, int n);


unsigned hash(char *s)
{
    unsigned hashval;

    for(hashval=0;*s;s++)
        hashval=*s+31*hashval;

    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for(np=hashtab[hash(s)]; np!=NULL;np=np->next)
        if(strcmp(s,np->name)==0)
            return np;
    return NULL;
}



struct nlist *install(char *name,char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if((np=lookup(name))==NULL ){
        np=(struct nlist *) malloc(sizeof(*np));
        if (np==NULL || (np->name=strdp(name,0))==NULL)
            return NULL;
        hashval=hash(name);
        np->next=hashtab[hashval];
        hashtab[hashval]=np;
    }
    else
        free((void *) np->defn);

    if((np->defn=strdp(defn,0))==NULL)
        return NULL;
    
    return np;
}

struct nlist *undef(char *name)
{
    struct nlist *np;
    unsigned hashval;

    if((np=lookup(name))!=NULL ){
        while(np!=NULL){
            free((void *) np->defn);
            free((void *) np->name); 
            np=np->next;
        }
        hashval=hash(name);
        hashtab[hashval]=NULL;        
    }
    
    return np;
}

void hash_print(struct nlist *p)
{
    if(p!=NULL){
        printf("%s\t%s\n",p->name,p->defn);
        hash_print(p->next);
    }
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
    if(isalnum(c)){
        for(;--lim>0;w++)
            if(!isalnum(*w=getch())){
                ungetch(*w);
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