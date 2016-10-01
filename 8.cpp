#include"stdio.h"
void main()
{
	FILE *f,*f1;
	f=fopen("D:\\8.txt","r");
	int a[1000];
    for(int i=0;i<1000;i++){
	fscanf(f,"%d",&a[i]);
		}
	double answer=0;
	for(int i=0;i<1000-13;i++)
	{
		double x=1;
		for(int j=i;j<i+13;j++)
		{
			x*=a[j];
		}
		if(x>answer)
			answer=x;
	}
	fclose(f);
	printf("%lf",answer);

}