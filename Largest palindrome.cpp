#include"stdio.h"
#include"malloc.h"
#include"math.h"
int pow(int m,int n){
	int s=1;
	while(n!=0){
	s*=m;
	n--;
	}
	return (s);
}
int isPalindrome(int n)
{
	int i=0;
	while(n/pow(10,i)!=0)
	{
		i++;
	}
	//printf("weishu=%d\n",i);
	int j=i-1;
	int *a=(int *)malloc(sizeof(int)*i);
	while(n!=0)
	{
		a[j]=n-10*(n/10);
		//printf("a[%d]=%d\n",j,a[j]);
		n/=10;
		j--;
	}
	for(int k=0;k<i/2;k++)
	{
		if(a[k]!=a[i-k-1]){
		return 0;
		break;
		}
	}
	return 1;
}
void main()
{
	int answer=0;
	for(int m=100;m<1000;m++)
	{
		for(int t=m;t<1000;t++)
		{
			if(isPalindrome(m*t)==1&&m*t>=answer)
				answer=m*t;
		}
	}
	printf("%d",answer);
}