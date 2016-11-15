#include"stdio.h"
int smallcount(int n)
{
	switch(n)
	{
	case(0):return 0;
	case(1):return 3;//one
	case(2):return 3;//two
	case(3):return 5;
	case(4):return 4;
	case(5):return 4;
	case(6):return 3;
	case(7):return 5;
	case(8):return 5;
	case(9):return 4;
	case(10):return 3;
	case(11):return 6;
	case(12):return 6;
	case(13):return 8;
	case(14):return 8;
	case(15):return 7;
	case(16):return 7;
	case(17):return 9;
	case(18):return 8;
	case(19):return 8;
	case(20):return 6;
	}
}
int bigcount(int n)
{
	if(n<=20)
	{
		return smallcount(n);
	}
	else if(20<n&&n<100)
	{
		int a=n/10;
		int b=n%10;
		printf("20 to 100:a=%d b=%d\n",a,b);
		int count_a=a==2?6:smallcount(a+10)-2;
		return count_a+smallcount(b);
	}
	else if(n>=100&&n<1000)
	{
		printf("Enter 100 to 1000\n");
		if(n%100==0)
		{
			int a=n/100;
			printf("a=%d\n",a);
			printf("Enter Õû°Ù\n");
			return smallcount(a)+7;
		}
		else if(n%100!=0)
		{
			int a=n/100;
			int b=(n-a*100);
			printf("a=%d b=%d\n",a,b);
			return smallcount(a)+10+bigcount(b);
		}
	}
	else if(n==1000)
	{
		printf("Enter 1000\n");
		return 11;
	}

}
void main()
{
	int sum=0;
	for(int i=1;i<=1000;i++)
	sum+=bigcount(i);
	printf("%d",sum);

}
