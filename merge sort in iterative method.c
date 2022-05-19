#include<stdio.h>
void merge(int *arr,int l,int m,int h)
{
	int i,j,n1,n2,a[100],b[100],k;
	n1=m-l+1;
	n2=h-m;
	k=l;
	for(i=0; i<n1; i++)
	{
	  a[i]=arr[k++];	
	}
	k=m+1;
	for(i=0; i<n2; i++)
	{
		b[i]=arr[k++];
	}
	i=0,j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
		{
			arr[k]=a[i];
			k++;
			i++;
		}
		else
		{
			arr[k]=b[j];
			k++;
			j++;
		}
	}
	while(i<n1)
	{
		arr[k]=a[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		arr[k]=b[j];
		k++;
		j++;
	}	
}
void merge_sort(int *arr,int n)
{
	int p,i,l,h,m;
	for(p=2; p<=n; p=p*2)
	{
		for(i=0; i<n; i=i+p)
		{
			l=i;
			h=l+p-1;
			m=(l+h)/2;
			if(h<=n)
			{
			  merge(arr,l,m,h);
		    }
		}	
	}
	merge(arr,0,(p/2)-1,n-1);	
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
	merge_sort(arr,n);
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
}