int find_mid_num(int *arr,int start,int end)
{
	int mid = (end-start)/2+start;
	int pos1=arr[start]>arr[mid]?start:mid;
	int pos2=arr[start]>arr[end]?start:end;
	int pos = arr[pos1]<arr[pos2]?pos1:pos2;
	return pos;
}
int find_datum(int *arr,int start,int end,int pos)
{
	
	int vtmp = arr[pos];
	arr[pos] = arr[start];
	
	int i = start;
	int j = end;
	int index = start;
	while(start<end)
	{
		while(arr[j--] > vtmp);
		if(++j>i)
		{
			arr[i] = arr[j];
			i++;
		}
		else
		{
			index = i;
			break;
		}

		while(arr[i++] < vtmp);
		if(--i<j)
		{
			arr[j]=arr[i];
			j--;
		}
		else
		{
			index = j;
			break;
		}
	
	}

	arr[index]=vtmp;

	return index;
}
void f_sort(int *arr,int start,int end)
{
	if(start>=end)
		return;
	int pos = find_mid_num(arr,start,end);
	int mid = find_datum(arr,start,end,pos);
	f_sort(arr,start,mid-1);
	f_sort(arr,mid+1,end);
}
void fast_sort(int *arr,int n)
{
	f_sort(arr,0,n-1);
}
