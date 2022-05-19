#include<stdio.h>
void insertion_sort(int *arr,int n)
{
	static int i,temp,j;
	if(i<n)
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
		i++;
		insertion_sort(arr,n);
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
	insertion_sort(arr,n);
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}	
}




