# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

# define MAXWORD 100


struct word_node {
    char *word;
    int count;
    struct word_node *left;
    struct word_node *right;
} ;





int getword( char *, int);
struct word_node *addtree(struct word_node *, char *);
struct word_node *treeprint(struct word_node *,struct word_node *);
void treeprint2(struct word_node *p);
struct word_node *addtree_count(struct word_node *p,struct word_node *s);

int main()
{
    char word[MAXWORD];
    struct word_node *root, *roots;
   
    
    root=NULL;
    roots=NULL;
    while(getword(word,MAXWORD)!=EOF)
                if(isalpha(word[0]))
                            root=addtree(root,word);

    printf("Word Counts\n");
    roots=treeprint(root, roots);
    treeprint2(roots);
    return 0;

}


struct word_node *talloc(void);
char *strdp(char *,int n);


struct word_node *addtree(struct word_node *p, char *w)
{
    int cond;


    if(p==NULL){
        p=talloc();
        p->word=strdp(w,0);
        p->count++;
        p->left=p->right=NULL;
    }
    else if((cond=strcmp(w,p->word))==0)
        p->count++;
    else if(cond<0)
        p->left=addtree(p->left,w);
    else 
        p->right=addtree(p->right,w);
   
    return p;
}



struct word_node *addtree_count(struct word_node *p, struct word_node *s)
{
    int cond;

    if(s==NULL){
               s=talloc();
                s->word=p->word;
                s->count=p->count;
                s->left=s->right=NULL;
                }
        else if((cond=(s->count - p->count))==0){
            if(strcmp(s->word,p->word)>0)
                s->left=addtree_count(p,s->left);
            else
                s->right=addtree_count(p,s->right);
            }  
        else if(cond<0)
            s->left=addtree_count(p,s->left);
        else 
            s->right=addtree_count(p,s->right);

        return s;
}     

struct word_node *treeprint(struct word_node *p,struct word_node *s)
{
    if(p!=NULL){
        s=treeprint(p->left,s);
        s=addtree_count(p,s);
        s=treeprint(p->right,s);     
}
    return s;
}

void treeprint2(struct word_node *p)
{
    if(p!=NULL){
        treeprint2(p->left);
        printf("%d\t%s\n",p->count,p->word);
        treeprint2(p->right);
       
}
}


struct word_node *talloc(void)
{
    return (struct word_node *) malloc(sizeof(struct word_node));
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