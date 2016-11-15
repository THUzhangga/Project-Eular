#include"stdio.h"
#include "malloc.h"
#include"math.h"
#include"string"
int pow(int a,int n)
{
	int i=0;
	while(i<n)
	{
		a*=n;
		i++;
	}
	return a;
}
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
int sumFactor(int n)
{
	int **a;
	int b=1;
	a=(int **)malloc(sizeof(int *)*n);
	for(int i=0;i<n;i++)
		a[i]=(int *)malloc(sizeof(int)*2);
	int order=0;
	for(int i=2;i<n/2;i++)
	{
		if(n%i==0&&isPrime(i)==true)
		{
			//printf("i=%d ",i);
			int m=n;
			a[order][0]=i;
			int count=0;
			while(m%i==0)
			{
				m/=i;
				count++;
			}
			b*=(count+1);
			//printf("count=%d\n",count);
			a[order][1]=count;
			order++;
		}
	}
	int *factor=(int *)malloc(sizeof(int)*b);
	for(int i=0;i<b;i++)
	{
		
	}

	return 0;
	//printf("the number of the factors of %d is %d\n",n,count);
}
int naive(int n)
{
	int *a=(int *)calloc(n,sizeof(int));
	int order=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			a[order]=i;
			order++;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	return sum;
}
void main()
{
	int sum=0;
	for(int i=0;i<10000;i++)
	{
		int m=naive(i);
		if(naive(m)==i)
		{
			sum+=i;
			printf("i=%d naiv(i)=%d\n",i,m);
		}
	}
	printf("%d",sum);
}

