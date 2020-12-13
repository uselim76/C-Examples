# include <stdio.h>
# include <time.h>


int n,i,j;
clock_t cpu_time;
int v[20000];

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main ()
{
n=-1;
i=0;
for(i=0;i<20000;++i)
    v[i]=i;

for ( i = 0, cpu_time = clock(); i < 1000000; ++i ) 
        j = binsearch1(n, v, 20000);
cpu_time = clock() - cpu_time;
printf("binsearch1() time is  %lu \t \n", cpu_time);

for ( i = 0, cpu_time = clock(); i < 1000000; ++i ) 
        j = binsearch2(n, v, 20000);
cpu_time = clock() - cpu_time;
printf("binsearch2() time is %lu \t \n", cpu_time);


return 0;    

}

int binsearch2(int x, int v[], int n)
{
    int low, mid, high;
    
    low=0;
    high=n-1;
    mid=(low+high)/2;

    while(low <= high && x != v[mid] ){
        if(x<((v[mid])))
            high=mid-1;
        else
            low=mid+1; 
        mid=(low+high)/2;  
    }      
        
    if(x==((v[mid])))
        return mid;
    else    
        return -1;
}
                
int binsearch1(int x, int v[], int n)
{
    int low, mid, high;
    
    low=0;
    high=n-1;

    while(low <= high){
        mid=(low+high)/2;
        if(x < v[mid])
            high=mid-1; 
        else if (x > v[mid])
            low=mid+1; 
        else
            return mid;
    }
    return -1;
}
