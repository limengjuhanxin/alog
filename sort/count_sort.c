int count_sort(int *arr,int n,int range)
{
	int *r=(int *)malloc(sizeof(int)*range);
	int *new=(int*)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<range;i++)
	{
		r[i]=0;
	}
	for(i=0;i<n;i++)
	{
		r[arr[i]]++;
	}
	for(i=1;i<range;i++)
	{
		r[i]+=r[i-1];
	}

	for(i=n-1;i>=0;i--)
	{
		new[--r[arr[i]]]=arr[i];
	}
	for(i=0;i<n;i++)
	{
		arr[i]=new[i];
	}
	free(r);
	free(new);
}
