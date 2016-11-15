#include"stdio.h"
#include"malloc.h"
#include"string"
int Chain(long long n)
{
	int count=0;
	while(n!=1)
	{
		//printf("%ld\n",n);
		n=(n%2==0?n/2:3*n+1);
		count++;
	}
	return count;
}
void main()
{
	//printf("%d\n",Chain(113383));
	int longest=0;
	///*
	long long int i=2;
	int m;
	for(;i<1000000;i++)
	{
		//printf("%d\n",i);
		if(Chain(i)>longest)
		{
			longest=Chain(i);
			m=i;
		}
		}
	printf("%d",m);
	//*/
	}