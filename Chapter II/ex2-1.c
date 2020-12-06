# include <stdio.h>
# include <limits.h>
# include <float.h>

long d;
float e;

int main ()
{
 d=CHAR_MAX;   
 printf("CHAR_MAX is %d\n",d);
 d=CHAR_MIN;
 printf("CHAR_MIN is %d\n",d);
 d=UCHAR_MAX;
 printf("UCHAR_MAX is %d\n",d);
 d=SHRT_MAX;   
 printf("SHRT_MAX is %d\n",d);
 d=SHRT_MIN;
 printf("SHRT_MIN is %d\n",d);
 d=USHRT_MAX;
 printf("USHRT_MAX is %d\n",d);
 d=INT_MAX;   
 printf("INT_MAX is %d\n",d);
 d=INT_MIN;
 printf("INT_MIN is %d\n",d);
 d=UINT_MAX;
 printf("UINT_MAX is %ld\n",d);
 d=LONG_MAX;   
 printf("LONG_MAX is %ld\n",d);
 d=LONG_MIN;
 printf("LONG_MIN is %ld\n",d);
 e=ULONG_MAX;
 printf("ULONG_MAX is %.0f\n",e);

return 0;    
}
