#include<stdio.h>
int * merge_sort(int *a,int n,int *b,int n1)
{
	int i=0,j=0,k=0;
	static int res[100];
	while(i<n && j<n1)
	{
		if(a[i]<b[j])
		{
			res[k]=a[i];
			i++;
		}
		else
		{
			res[k]=b[j];
			j++;
		}
		k++;
	}
	while(i<n)
	{
		res[k++]=a[i++];
	}
	while(j<n1)
	{
		res[k++]=b[j++];
	}
	return res;	
}
void main()
{
	int n,n1;
	scanf("%d%d",&n,&n1);
	int a[n],b[n1],i,*res;
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0; i<n1; i++)
	{
		scanf("%d",&b[i]);
	}
	res=merge_sort(a,n,b,n1);
	for(i=0; i<(n+n1); i++)
	{
		printf("%d ",res[i]);
	}
	
}