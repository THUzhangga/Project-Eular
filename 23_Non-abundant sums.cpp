#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
int pow(int m,int n)
{
	int s=1;
	while(n!=0)
	{
		s*=m;
		n--;
	}
	return (s);
}
int repeat(char *a)
{
	int count=0;
	int m=_msize(a)/sizeof(int);
    for(int i=m-1;i>=0;i--)
	{
	    for(int j=0;j<i;j++)
		{
			if(a[i]==a[j])
			break;
			else
			count++;
		}
	}
	return (count==m*(m-1)/2)?1:0;
}

void main(){
	FILE *fp;
	fp=fopen("D://ÃÜÂë.txt", "w");  
	int main_count=0;
	char *p;
	int i=10;
	for(long int j=123456789;j<pow(10,i);j++)
	{
		p=(char *)calloc(i,sizeof(int));
		int k=0;
		int m=j;
		while(m!=0)
		{
			p[i-k-1]=m%10;
			m/=10;
			k++;
		}
		if(repeat(p)==1)
		{
			main_count++;
			printf("%d\n",main_count);
			//for(int n=0;n<i;n++)
			//{
				//fprintf(fp,"%d",p[n]);
				//printf("%d",p[n]);
			//}
		//fprintf(fp,"\n");
		//printf("\n");
		}
	if(main_count==1000000)
	{
		for(int n=0;n<i;n++)
			{
				//fprintf(fp,"%d",p[n]);
				printf("%d",p[n]);
			}
		break;
	}
	free(p);
	}
	fclose(fp);
}