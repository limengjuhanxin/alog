void m_merge(int *arr,int start,int mid,int end)
{
	int nums=end-start+1;
	int *new=(int *)malloc(sizeof(int)*nums);
	int i,j,k=0;
	for(i=start,j=mid+1;(i<=mid && j<=end);)
	{
		if(arr[i]<=arr[j])
		{
			new[k++]=arr[i++];
		}
		else
		{
			new[k++]=arr[j++];
		}
	}
	if(i!=(mid+1))
	{
		for(;i<=mid;i++)
			new[k++]=arr[i];
	}
	if(j!=(end+1))
	{
		for(;j<=end;j++)
			new[k++]=arr[j];
	}

	for(i=0,j=start;j<=end;i++,j++)
		arr[j]=new[i];

	free(new);	
}
void m_sort(int *arr,int start,int end)
{
	int mid=(end-start)/2+start;
	if(start==end)
		return;
	else
	{
		m_sort(arr,start,mid);
		m_sort(arr,mid+1,end);
		m_merge(arr,start,mid,end);
	}
}
void merge_sort(int *arr,int n)
{
	m_sort(arr,0,n-1);
}
