#include"stdio.h"
#include"string.h"
#include"string"
#include"math.h"
//#include"math.h"
char *intTochar(int n)
{
	char re[1000];
	int i=0;
	int m=n;
	while(m!=0)
	{
		i++;
		m/=10;
	}
	//printf("%d",i);
	for(int j=0;j<i;j++)
	{
		re[j]=n%10+'0';
		n/=10;
	}
	re[i]='\0';
	return re;
}
//整数转变为字符串

char *subtract(char *a,char *b)
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>=b[i])
			a[i]=a[i]-b[i]+'0';
		else
		{
			int j=1;
			while(a[i+j]=='0')
			{
				a[i+j]=9+'0';
				j++;
			}
			a[i+j]--;
			a[i]=a[i]+10-b[i]+'0';
		}
	}
	for(int i=strlen(a)-1;i>=0;i--)
	{
		if(a[i]!='0')
		{
			a[i+1]='\0';
			break;
		}
	}
	return a;
}
//大整数减法
int isExactDivision(char *a,int n)//大整数除法
{
	char *b;
	b=intTochar(n);
	int lena=strlen(a);
	int lenb=strlen(b);
	//printf("lena=%d lenb=%d\n",lena,lenb);
	if(lena<lenb)
		//printf("%d",0);
		return 0;
	else if(lena==lenb)
	{
		for(int i=lena-1;i>=0;i--)
		{
			if(a[i]>b[i])
				break;
			else if(a[i]<b[i])
			{
				//return 0;
				break;
			}
		}
	}
	//a代表的数不能比b小
	
	while(strlen(a)>lenb)
	{
		//printf("%d,%d\n",strlen(a),lenb);
		int deal=0;
		int count=1;
		for(int i=strlen(a)-1;i>=0;i--)
		{
			deal+=a[i]-'0';
			if(deal>=n) break;
			count++;
			deal*=10;
		}
		//printf("%d",deal);
		int t=deal%n;
		char *c=intTochar(t);
		for(int i=strlen(a)-count;i<strlen(a)-count+strlen(c);i++)
			a[i]=c[i-strlen(a)+count];
		a[strlen(a)-count+strlen(c)]='\0';
		//printf(" %s\n",a);
		
	}
	int last=0;
	for(int i=strlen(a)-1;i>=0;i--)
	{
		last+=a[i]-'0';
		if(i==0) break;
		last*=10;
	}
	if(last%n==0)
	return 1;
	else return 0;
}
int isRe(int  n)
{
	int m=n;
	while(m%2==0)
		m/=2;
	while(m%5==0)
		m/=5;
	return m>1?1:0;
} 
int main()  
{
	/*
	char a[1200];
	for(int i=0;i<4;i++)
		a[i]=i+1+'0';
	a[4]='\0';
	char b[1200];
	for(int i=0;i<4;i++)
		b[i]=4-i+'0';
	b[4]='\0';
	printf("%s",subtract(a,b));
	*/
	FILE *f;
	f=fopen("D:\\大数除法.txt","w");
	int n=7654321;
	char a[100]="999999999";
	int num=0;
	//printf("%d",isExactDivision(a,23));
	    num=2016;
		if(isRe(num)==1)
		{
			printf("数：%d;",num);
			while(num%2==0)
			num/=2;
			while(num%5==0)
			num/=5;
			printf("等同于%d ",num);
			int recycle=1;
			char rec[1200];
			rec[0]=9;
			rec[1]='\0';
			while(isExactDivision(rec,num)!=1)
			{
				recycle++;
				for(int j=0;j<recycle;j++)
					rec[j]='9';
				rec[recycle]='\0';
				printf("%s;",rec);
			}
			printf("循环节：%d\n",recycle);

		}	
	
	

}
