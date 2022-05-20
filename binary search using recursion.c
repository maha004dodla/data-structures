#include<stdio.h>
int l=0;
int search_element(int *arr,int search,int size)
{
	int m,h;
	h=size-1;
	m=(l+h)/2;
	if(l>h)
	{
		return 0;
	}
	if(arr[m]==search)
	{
		return 1;
	}
	if(search>arr[m])
	{
		l=m+1;
	}
	else if(search<arr[m])
	{
		size=m;
	}
	return search_element(arr,search,size);
}
int main()
{
	int size,arr[100],i,search;
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&search);
	if(search_element(arr,search,size))
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
}