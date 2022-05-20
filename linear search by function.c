//searching//
#include<stdio.h>
int search(int *arr,int n,int se)
{
	int i,flag=0;
	for(i=0; i<n; i++)
	{
		if(arr[i]==se)
		{
			flag = 1;
			break;
		}
    }
    return flag==1;
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