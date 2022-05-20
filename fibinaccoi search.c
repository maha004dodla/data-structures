#include<stdio.h>
int min(int a,int b)
{
	if(a>b)
	{
		return b;
	}                                         
	return a;                                
}                                             
int fibi_search(int *arr,int n,int se)
{                                             
	int i,fib[n],L,M,H;
	L=-1,H=n-1;
	fib[0]=0,fib[1]=1;
	for(i=2; i<n; i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	while(fib[H]!=0)
	{
		M=min(L+fib[H-2],n-1); 
		if(se==arr[M] || arr[H]==se)
		{
			return 1;
		}
		else if(se>arr[M])
		{
			L=M;
			H=H-1;
		}
		else if(se<arr[M])
		{
		   H=H-2;	
		}
	}
	if(arr[H]==se)
	{
		return 1;
	}
	return 0;
}
void main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i,se,res;
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&se);
	if(fibi_search(arr,n,se))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}   
}