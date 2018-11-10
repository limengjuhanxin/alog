void adjust_heap(int *arr,int pos,int n)
{
	int index;
	int i=pos;
	int top=arr[pos];
	while(2*i+1<n)
	{
		index = 2*i+1;
		if(2*i+2<n && (arr[2*i+1]<arr[2*i+2]))
		{
			index++;
		}
		if(arr[index]>top)
		{
			arr[i]=arr[index];
			i=index;
		}
		else
		{
			break;
		}
	}
	arr[i]=top;
}
void heap_sort(int *arr,int n)
{
	int i=n/2-1;
	int tmp;
	for(;i>0;i--)
		adjust_heap(arr,i,n);
	for(i=0;i<n-1;i++)
	{
		adjust_heap(arr,0,n-i);

		tmp=arr[0];
		arr[0]=arr[n-i-1];
		arr[n-i-1]=tmp;

	}
	
}
