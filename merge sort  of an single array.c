#include<stdio.h>
int * merge_sort(int *arr,int n)
{
	int i,j,k;
	int a[100],b[100];
	int l,h,m;
	l=0;
	h=n-1;
	m=(l+h)/2;
	for(i=l; i<=m; i++)
	{
		a[k++]=arr[i];
	}
	k=0;
	for(i=m+1; i<=h; i++)
	{
		b[k++]=arr[i];
	}
	i=0,j=0,k=0;
	while(i<n/2 && j<n/2)
	{
		if(a[i]<b[j])
		{
			arr[k]=a[i];
			i++;
		}
		else
		{
			arr[k]=b[j];
			j++;
		}
		k++;
	}
	while(i<n/2)
	{
		arr[k++]=a[i++];
	}
	while(j<n/2)
	{
		arr[k++]=b[j++];
	}
	return arr;	
}
void main()
{
	int n,n1;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,n);
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	
}