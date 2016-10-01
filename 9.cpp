#include"stdio.h"
void main()
{
	for(int a=1;a<33;a++)
	{
		for(int b=a+1;b<50;b++)
		{
			int c=100-a-b;
			
			if(c*c==a*a+b*b)
			printf("a=%d b=%d c=%d\n",a,b,c);
		}
	}
}