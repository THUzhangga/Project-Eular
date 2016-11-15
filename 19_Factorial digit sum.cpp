#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
int* cal(int *a,int *c)
{
	int digit=_msize(a)/4;
	//printf("%d\n",digit);
	///*
	int *re=(int *)malloc(_msize(a)+8);
	int *re0=(int *)malloc(_msize(a));
	int *re1=(int *)malloc(_msize(a));
	int *b0=(int *)calloc(digit+2,4);
	int *b1=(int *)calloc(digit+2,4);
	int *d=(int *)calloc(digit+2,4);
	for(int i=0;i<digit;i++)
	{
		 b0[i+1]=(a[i]*c[0]+b0[i])/10;
		 //printf("i+=%d %d\n",i+1,b0[i+1]);
         re0[i]=(a[i]*c[0]+b0[i])%10;
	}
	re0[digit]=b0[digit];
	//for(int i=0;i<digit+1;i++)
		//printf("%d",re0[i]);
	//printf("\n");
	//*/
	///*
	for(int i=0;i<digit;i++)
	{
		 b1[i+1]=(a[i]*c[1]+b1[i])/10;
         re1[i]=(a[i]*c[1]+b1[i])%10;
	}
	re1[digit]=b1[digit];
	//for(int i=0;i<digit+1;i++)
		//printf("%d",re1[i]);
	//printf("\n");
	for(int i=digit+1;i>=1;i--)
		re1[i]=re1[i-1];
	re1[0]=0;
	//for(int i=0;i<digit+2;i++)
		//printf("%d",re1[i]);
	//printf("\n");
	for(int i=0;i<digit+1;i++)
	{
		d[i+1]=(re0[i]+re1[i]+d[i])/10;
		re[i]=(re0[i]+re1[i]+d[i])%10;
	}
	re[digit+1]=b1[digit+1]+d[digit+1]+re1[digit+1];
	if(re[digit+1]>=1)
		return re;
	if(re[digit+1]==0)
	{
		realloc(re,(digit+1)*4);
		if(re[digit]==0)
			realloc(re,(digit)*4);
		return re;
	}
}
void main()
{
	/*
	int *a=(int *)malloc(sizeof(int)*4);
	//printf("%d\n",_msize(a));
	a[0]=1;
	a[1]=2;
	a[2]=3;
	a[3]=4;
	int c[2]={1,0};
	int *ca=cal(a,c);
	for(int i=0;i<4;i++)
		printf("%d",ca[i]);
	*/
	int *a=(int *)malloc(sizeof(int));
	int *c=(int *)malloc(sizeof(int)*2);
	a[0]=1;
	for(int k=1;k<11;k++)
	{
	//int k=12;
		c[0]=k%10;
		c[1]=k/10;
		a=cal(a,c);
	for(int i=0;i<_msize(a)/4;i++)
		printf("%d",a[i]);
	printf("\n");
	}
	int sum=0;
	for(int i=0;i<_msize(a)/4;i++)
		sum+=a[i];
printf("%d",sum);
}
