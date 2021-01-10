# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

# define MAXWORD 100
# define NKEYS (sizeof keytab / sizeof(keytab[0]))

struct word_node {
    char *word;
    struct line_node *line_nos;
    struct word_node *left;
    struct word_node *right;
} ;

struct line_node {
    int line_no;
    struct line_node *left;
    struct line_node *right;
};



struct dict {
    char *word;
    struct word_node *keyword;
} keytab[]={
    "and", NULL,
    "but",NULL,
    "if",NULL,
    "or",NULL,
    "the",NULL
    };

int n_line;



int getword( char *, int);
struct word_node *addtree(struct word_node *, char *);
void treeprint(struct word_node *);
int binsearch(char *word, struct dict tab[], int n );

int main()
{
    char word[MAXWORD];
    struct word_node *root;
    extern int n_line;
    int n;
    
    root=NULL;
    n_line=1;
    while(getword(word,MAXWORD)!=EOF)
            if((n=binsearch(word, keytab,NKEYS))<0)
                    if(isalpha(word[0]))
                            root=addtree(root,word);

    printf("Words\t \tLine Nos\n");
    printf("====\t=\t=======\n");
    treeprint(root);

    return 0;

}

int binsearch(char *word, struct dict tab[], int n )
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


struct word_node *talloc(void);
struct line_node *t2alloc(void);
char *strdp(char *,int n);
struct line_node *addtree_var(struct line_node *v);

struct word_node *addtree(struct word_node *p, char *w)
{
    int cond;


    if(p==NULL){
        p=talloc();
        p->word=strdp(w,0);
        p->line_nos=addtree_var(p->line_nos);
        p->left=p->right=NULL;
    }
    else if((cond=strcmp(w,p->word))==0)
        p->line_nos=addtree_var(p->line_nos);
    else if(cond<0)
        p->left=addtree(p->left,w);
    else
        p->right=addtree(p->right,w);
    return p;
}

struct line_node *addtree_var(struct line_node *v)
{
    
    extern int n_line;

    if(v==NULL){
        v=t2alloc();
        v->line_no=n_line;
        v->left=v->right=NULL;
    }
    else if(v->line_no==n_line)
        ;
    else if(v->line_no > n_line)
        v->left=addtree_var(v->left);
    else
        v->right=addtree_var(v->right);
    return v;
}


void treeprint2(struct line_node *);

void treeprint(struct word_node *p)
{
    if(p!=NULL){
        treeprint(p->left);
        printf("%s\t",p->word);
        treeprint2(p->line_nos);
        printf("\n");
        treeprint(p->right);
       
}
}

void treeprint2(struct line_node *v)
{
    if(v!=NULL){
        treeprint2(v->left);
        printf("%d\t",v->line_no);
        treeprint2(v->right);
}
}


struct word_node *talloc(void)
{
    return (struct word_node *) malloc(sizeof(struct word_node));
}

struct line_node *t2alloc(void)
{
    return (struct line_node *) malloc(sizeof(struct line_node));
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
    extern int n_line;

    while(isspace(c=getch()))
        if(c=='\n')
            n_line++;

    if(c!=EOF)
        *w++=c;
    if(isalpha(c)){
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