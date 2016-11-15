#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
#include"string.h"

void Add(char a[],char b[],char d[])
{
    char c[1200];
    int lena=strlen(a),lenb=strlen(b);
    int i,len;
    len=lena>lenb?lena:lenb;
    len++;
    c[0]='\0';
    for(i=1;i<=len;i++)c[i]='0';
    for(i=1;i<=lena;i++)c[i]+=a[lena-i]-48;
    for(i=1;i<=lenb;i++)c[i]+=b[lenb-i]-48;
    for(i=0;i<=len;i++)
        if(c[i]>57)
    {
            c[i]-=10;
            c[i+1]++;
        }

    for(i=len;i>1;i--)
        if(c[i]==48)len--;
        else break;
     for(i=0;i<=len;i++)
        d[i]=c[len-i];
}

void main()
{
	FILE *f;
	f=fopen("D:\\Feb.txt","w");
    char a[1200];
    char b[1200];
    char c[1200];
    a[0] = '1';
    a[1] = '\0';
    b[0] = '1';
    b[1] = '\0';
    int i = 3;
    while (true)
    {
        Add(a, b, c);
		fprintf(f,"%s\n\n",c);
        if (strlen(c) == 1000) break;
        i++;
        strcpy(a, b);
        strcpy(b, c);
    }
    printf("%d\n", i);
	int sum=0;
	for(int i=0;i<strlen(c);i++)
    sum+=c[i]-48;
	printf("%d",sum);
}