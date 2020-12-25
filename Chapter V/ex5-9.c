# include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static int daytab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
            {0,31,29,31,30,31,30,31,31,30,31,30,31}};


int main()
{
    int *m;
    int *d;
    int year=1998;
    int yearday=65;
    int month;
    int day;
    m=&month;
    d=&day;

    month_day(year,yearday,m,d);

    if(day_of_year(year,*m,*d)!=-1)
            printf("Day  of year for %d-%d-%d is %d\n", year, *m,*d, day_of_year(year,*m,*d));
    else
        printf("Invalid date\n");
       
}

int day_of_year(int year, int month, int day)
{
    int i,leap;
    int *p;
    leap= year%4==0 && year%100 != 0 || year%400 ==0;
    if( year <0 || month <=0 || day <=0)
        return -1;
    else if( month>12)
        return -1;
    else if(day>daytab[leap][month])
        return -1;
    else
        p=& daytab[leap][0];
        i=0;
        while(i++<month)
                day+=*p++;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i,leap, *p;
    leap= year%4==0 && year%100 != 0 || year%400 ==0;
    
    if( year <0 || yearday <=0)
        printf("Invalid date\n");
    else if((leap==0 && yearday>365) || (leap==1 && yearday>366) )
        printf("Invalid date\n");
    else{
        i=0;
        p=& daytab[leap][0];
        while(yearday>*p){
            yearday-=*p++;
            i++;
        }
           
        
    }
    *pday=yearday;
    *pmonth=i;
}