#include<stdio.h>
int search(int *arr,int n,int se)
{
	int static i=0;
	if(i==n)
	{
		return 0;
	}
	if(arr[i]==se)
	{
		return 1;
	}
	i++;
	return search(arr,n,se);
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i,se,res;
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&se);
	if(search(arr,n,se))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}  
}