#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i,low,high,mid,se,flag=0;
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&se);
	low=0,high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
	    if(arr[mid]<se)
		{
			low=mid+1;
		}
		
		else if(arr[mid]>se)
		{
			high=mid-1;
		}
		else if(arr[mid]==se)
		{
		    flag=1;
		    break;
		}
	}
	if(flag==1)
	{
		printf("element found");
	}
	else
	{
		printf("element not found");
	}
	return 0;
}