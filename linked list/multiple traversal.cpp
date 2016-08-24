#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node * next;
	struct node * prev;
	int dat;
};

struct node *create ( struct node * list, int x)
{
	list->dat = x;
	list->next = NULL;
	return list;
} 

struct node * findk( struct node * list, int i, int k)
{
	if( i == k) {
		return list;
	}
	return findk(list->next,i + 1,k + 1);
}

int main()
{
	int i;
	int n;
	int x;
	int k;
	struct node * head;
	struct node * list;
	struct node * temp;
	scanf("%d",&n);
	head = (struct node * )malloc(sizeof( struct node ) );
	scanf("%d",&x);
	list = create (head,x);
	list->prev = NULL;
	for( i = 1;i < n; i++) {
		list->next =  (struct node * )malloc(sizeof( struct node ) );
		scanf("%d",&x);
		list->next->prev = list;
		list = create(list->next,x);
	}
	scanf("%d",&k);
	list = head;
	while( 1 ){
			while( list->next != NULL && k > 0) {
				printf("%d ",list->dat);
				k--;
				list = list->next;
			}
			if( k > 0) {
				printf("%d ",list->dat);
				k--;
			} else {
				break;
			}
			list = list->prev;
			while( list->prev != NULL && k > 0 ) {
				printf("%d ",list->dat);
				list = list->prev;
				k--;
			}
	}
}
