#include"stdio.h"
#include "malloc.h"
#include"math.h"
#include"string"
bool isPrime(int num)  
    {  
        if (num==2||num==3)  
        {  
            return true;  
        }  
        if (num % 6 != 1 && num % 6 != 5)  
        {  
            return false;  
        }  
        for (int i = 5; i*i <= num; i += 6)  
        {  
            if (num % i == 0 || num % (i+2) == 0)  
            {  
                return false;  
            }  
        }  
        return true;  
    }  
int *factor(int n)
{
	int *a;
	a=(int *)malloc(sizeof(int)*2);
	a[0]=1;
	a[1]=0;
	if(n%2==0)
	{
		int t=n;
		while(t%2==0)
			{
				t/=2;
				a[1]++;
			}
	}
	a[1]+=1;
	for(int i=2;i<n/2;i++)
	{
		if(n%i==0&&isPrime(i)==true)
		{
			//printf("i=%d ",i);
			int m=n;
			int count=0;
			while(m%i==0)
			{
				m/=i;
				count++;
			}
			//printf("count=%d\n",count);
			a[0]*=(count+1);
		}
	}
	return a;
	//printf("the number of the factors of %d is %d\n",n,count);
}
void main()
{
	FILE *f;
	f=fopen("D:factor.csv","w");
	int j=1;
	for(;j++;)
	{
		int even=j%2==0?j:j+1;
		int odd=j%2==0?j+1:j;
		int na=factor(even)[1];
		int result=factor(even)[0]*factor(odd)[0]*(na-1)/na;
		fprintf(f,"%d,%d\n",j,result);
		if(result>=500)
		{
			printf("%d\n",j);
			break;
		}
	}
}