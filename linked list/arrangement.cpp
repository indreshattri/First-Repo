#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node * next;
	int dat;
};

struct node * create(struct node * list,int x)
{
	list->dat = x;
	list->next = NULL;
	return list;
}

int size (struct node * list) 
{
	int i;
	i = 0;
	while( list != NULL) {
		i++;
		list = list->next;
	}
	return i;
}

struct node * findk( struct node * list, int k) 
{
	int i;
	i = 1;
	while( i != k ) {
		list = list->next;
		i++;
	}
	return list;
}

void print(struct node * list) 
{
	if(list == NULL) {
		return;
	}
	printf("%d ",list->dat);
	print(list->next);
}

void rearrange(struct node * head) 
{
	struct node * list;
	list = head;
	struct node * temp;
	int n;
	struct node *p;
	struct node *q;
	int i;
	int j;
	i = 0;
	n = size(head);
	j = n;
	printf("%d     n\n",n);
	while( i < n ){
		p = findk(head,i + 1);
		q = findk(head,n);
		temp = p->next;
		p->next = q;
		q->next = temp;
		i = i + 2;
		j= j - 2;;
	}
	list = head;
	i = 1;
	while( i != n ) {
		list = list->next;
		i++;
	}
	list->next = NULL;
	
}

int main()
{
	int x,k,d;
	struct node * head;
	struct node * list;
	head = (struct node *)malloc(sizeof(struct node));
	scanf("%d %d",&d,&x);
	list = create(head,x);
	while(1) {
		scanf("%d",&d);
		switch(d) {
			case 1:
				scanf("%d",&x);
				list->next = (struct node *)malloc(sizeof(struct node));
				list = create(list->next,x);
				break;
			case 2:
				print(head);
				printf("\n");
				break;
			case 3:
				rearrange(head);
				break;
		}
	}
}
