#include"stdio.h"
#include"stdlib.h"
void main()
{
	FILE *f,*f1;
	f=fopen("D:\\name.txt","r");
	f1=fopen("D:\\name_dealed.txt","w");
	//char **name;
	char c=NULL;
	int i=0;
	double sum=0;
	while(c!=EOF)
	{
		c=fgetc(f);
		//printf("out:%c\n",c);
		////*
		if(c!='"'&&c!=',')
		{
			char *name=(char *)malloc(sizeof(char)*30);
			int j=0;
			int count=0;
			while(c!='"'&&c!=EOF)
			{
				name[j]=c;
				count+=c-64;
				//printf("in:%c",name[i][j]);
				c=fgetc(f);
				j++;
			}
			name[j]='\0';
			//printf("%d ",i);
		printf("%d %s\n",count,name);
		sum+=count*(i+1);
		fprintf(f1,"%d %s %d\n",i+1,name,count);
		i++;	
		}
		//*/
	}

	printf("%lf",sum);

}
