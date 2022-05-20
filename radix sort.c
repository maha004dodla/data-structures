#include<stdio.h>
int maxi(int *arr, int n)
{
    int max=arr[0];
    int i;
    for (i=1; i<n; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}
 
void countSort(int *arr,int n,int exp) 
{
    int output[n];
    int i, count[10] = { 0 };
	for (i=0; i<n; i++)
	{
        count[(arr[i]/exp)%10]++;
    }
 
    for (i=1; i<10; i++)
    {
        count[i]+=count[i - 1];
    }
	for (i=n-1; i>=0; i--) 
	{
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i=0; i<n; i++)
    {
        arr[i] = output[i];
    }
}
void radix_sort(int *arr, int n)
{
    int m = maxi(arr, n);
    int exp;
    for (exp=1; m/exp > 0; exp*=10)
    {
        countSort(arr, n, exp);
    }
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	radix_sort(arr,n);
    for(i=0; i<n; i++)
    {
    	printf("%d ",arr[i]);
	}
    return 0;
}