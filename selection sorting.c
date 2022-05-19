#include<stdio.h>
int max(int *arr,int n)
{
	int i,max=0,p;
	for(i=0; i<n; i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
			p=i;
		}
	}
	return p;
}
void selection_sort(int *arr,int n)
{
	int i,p,temp,last=n-1;
	while(last!=0)
	{
		p=max(arr,last+1);
		if(arr[p]>arr[last])
		{
		    temp=arr[p];
			arr[p]=arr[last];
			arr[last]=temp;	
		}
		last--;
	}
}
void main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,n);
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
}
















