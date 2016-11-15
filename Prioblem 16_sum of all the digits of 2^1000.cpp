#include"stdio.h"
#include"stdlib.h"
void main()
{
	int *a;
	a=(int *)malloc(sizeof(int)*2);
	a[0]=6;
	a[1]=1;
	int digit=2;
	for(int i=5;i<1001;i++)
	{
		//printf("Enter...THE MAX a[digit-1]=%d\n",a[digit-1]);
		if(a[digit-1]>=5)
		{
			//printf("正在开辟，此时a[digit-1]=%d\n",a[digit-1]);
			int *b=(int *)malloc(sizeof(int)*digit);
			for(int m=0;m<digit;m++)
				b[m]=a[m];
			digit++;
			a=(int *)malloc(sizeof(int)*digit);
			for(int m=0;m<digit-1;m++)
				a[m]=b[m];
			a[digit-1]=1;
			for(int j=digit-2;j>=1;j--)
			{
				if(a[j]>=5)
				{
					a[j]=a[j-1]>=5?a[j]*2-9:a[j]*2-10;
				}
				else 
					a[j]=a[j-1]>=5?a[j]*2+1:a[j]*2;
				
			}
		}
		else if(a[digit-1]<5)
		{
			for(int j=digit-1;j>=1;j--)
			{
				if(a[j]>=5)
				{
				a[j]=a[j-1]>=5?a[j]*2-9:a[j]*2-10;
				}
				else 
					a[j]=a[j-1]>=5?a[j]*2+1:a[j]*2;
			}
		}
		a[0]=(a[0]>=5?a[0]*2-10:a[0]*2);
		//printf("次数=%d digit=%d count=",i,digit);
		if(i==1000)
		{
		int sum=0;
		for(int k=digit-1;k>=0;k--){
			sum+=a[k];
			}
		printf("%d",sum);
		}
		printf("\n");
	}
}