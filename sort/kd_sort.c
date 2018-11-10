struct node
{
	int val;
	struct node *next;
};
struct link
{
	struct node *head;
	struct node *tail;
};
struct link arr_l[10];
struct node *head;
int create_list(int *arr,int n)
{
	head=NULL;
	if(n==0)
		return -1;
	head = (struct node *)malloc(sizeof(struct node));
	struct node* p = head;
	p->val=arr[0];
	p->next=NULL;
	int i;
	struct node *cur;
	for(i=1;i<n;i++)
	{
		cur =(struct node *)malloc(sizeof(struct node));
		cur->val=arr[i];
		cur->next=NULL;
		p->next=cur;
		p=cur;
	}
}
int get_bit(struct node *p,int i)
{
	int val=p->val;
	int pos=((val/((int)pow(10,i)))%10);
//	printf("val:%d pos:%i mod:%d\n",val,i,pos);
	return pos;
}
void insert_list(struct node *p,int index)
{
//	printf("insert　num:%d pos:%d\n",p->val,index);
	if(NULL==arr_l[index].head)
	{
		arr_l[index].head=p;
		arr_l[index].tail=p;
		arr_l[index].head->next=NULL;
		arr_l[index].tail->next=NULL;
		
	}
	else
	{
		arr_l[index].tail->next=p;
		arr_l[index].tail=p;
		arr_l[index].tail->next=NULL;
	}
}
void merge_list()
{
	int i;
	struct node *p;
	struct node *p_h;
	p_h=head;
	for(i=0;i<10;i++)
	{
		if(arr_l[i].head!=NULL)
		{
			head=arr_l[i].head;
			break;
		}
	}
	for(i++;i<10;i++)
	{
		if(arr_l[i].head!=NULL)
		{	
			arr_l[i-1].tail->next=arr_l[i].head;
		}
	}
//	printf("clear\n");
	for(i=0;i<10;i++)
	{
		arr_l[i].head=NULL;
		arr_l[i].tail=NULL;
	}
	
}
void print_list(struct node	*head)
{
	struct node*p=head;
	while(p!=NULL)
	{
		printf("%2d ",p->val);
		p=p->next;
	}
	printf("\n");
}
void free_list(struct node*head)
{
	struct node *p=head;
	struct node *q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}
/***************kd sort******************/
int kd_sort(int *arr,int n,int size)
{
	if(create_list(arr,n)==-1)
		return -1;
	struct node *p;
	struct node *q;
	int i;
	for(i=0;i<size;i++)
	{
		p=head;
		while(p!=NULL)
		{
			int pos=get_bit(p,i);
			q=p;
			p=p->next;
			insert_list(q,pos);
		}
		merge_list();
	}
	print_list(head);
	free_list(head);
}
