#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,i,x,k,a;
    scanf("%d",&n);
    int num=n;
     k=0;a=2*num-1;
    for(i=1;i<=2*n-1;i++)
    {
        for (x=k;x>0;x--)
        {
            printf("%d ",num--);
        }
        for(x=a;x>0;x--)
        {
            printf("%d ",num);
        }
        
        for(x=k;x>0;x--)
        {
            printf("%d ",++num);
        }
        if (i<n)
        {
            a-=2;k++;
        }
        else
        {
            a+=2;k--;
        }
        
        printf("\n");
    } 
    
    
  	// Complete the code to print the pattern.
    return 0;
}