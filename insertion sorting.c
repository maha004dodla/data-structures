#include<stdio.h>
void insertion_sort(int *arr,int n)
{
	int i,j,temp;
	for(i=1; i<n; i++)
	{
		j=i-1;
		while(arr[i]<arr[j])
		{
			temp=arr[i];         
			while(temp<arr[j])      
			{
				arr[j+1]=arr[j];
				arr[j]=temp;
				j--;
			}
		}
	}
	if(j=-1)
	{
		arr[i]=temp;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i,j;
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion_sort(arr,n);
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	
}