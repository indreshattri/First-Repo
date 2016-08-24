#include<stdio.h>
#include<stdlib.h>

struct node{
    int dat;
    struct node * next;
};

void print(struct node * list,struct node * head)
{
	int flag = 0;
	while( list != head || flag == 0) {
		if( list == head) {
			printf("%d\n",list->dat);
			flag = 1;
		} else {
			printf("%d\n",list->dat);
		}
		list = list->next;
	}
	return;
}

struct node * findk(struct node * list,int k,int i) 
{
	if( i == k - 1 ) {
		return list;
	} else {
		return findk(list->next,k,i+1);
	}
}

struct node * find_end(struct node * list,struct node * head)
{
	while(list->next != head) {
		list = list->next;
	}
	return list;
}

struct node * insert(struct node * head,int k,int x)
{
	struct node * p;
	struct node * temp;
	if( k == 1) {
		p = find_end(head->next,head);
		p->next = (struct node *)malloc(sizeof(struct node));
		p->next->dat = x;
		p->next->next = head;
		head = p->next;
	} else{
		p = findk(head,k,1);
		temp = p->next;
		p->next = (struct node *)malloc(sizeof(struct node));
		p->next->dat = x;
		p->next->next = temp;
		
	}
	return head;
	
}

struct node *create(struct node * list,int x,struct node * head)
{
   list->dat = x;
   list->next = head;
   return list;
}

int main()
{
	struct node * head;
	struct node * list;
	int flag = 0;
	int x;
	int d;
	int k;
	while(1) {
		scanf("%d",&d);
		switch(d) {
			case 1:
				
				scanf("%d",&x);
				if(flag == 0) {
					head = (struct node *)malloc(sizeof(struct node ));
					flag = 1;
					list = create(head,x,head);
				} else {
					list->next = (struct node *)malloc(sizeof(struct node ));
					list = create(list->next,x,head);
				}
				break;
			case 2:
				print(head,head);
				break;
			case 3:
				scanf("%d",&k);
				scanf("%d",&x);
				head = insert(head,k,x);
				break;
		}
	}
				
				
}
