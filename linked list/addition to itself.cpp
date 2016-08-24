#include <stdio.h>
#include <stdlib.h>

struct node{
    int dat;
    struct node * next;
};

struct node *create(struct node * list,int x)
{
   list->dat = x;
   list->next = NULL;
   return list;
}

struct node * findk(struct node * list,int k,int i) 
{
	if( i == k  ) {
		return list;
	} else {
		return findk(list->next,k,i+1);
	}
}

int size(struct node * head)
{
	int i = 0;
	while( head != NULL ) {
		i++;
		head = head->next;
	}
	return i;
}

void swap(struct node * head,int k)
{
	struct node *p1;
	struct node * p2;
	int n;
	int temp;
	p1 = findk(head,k,1);
	n = size(head);
	p2 = findk(head,n + 1 - k,1);
	temp = p1->dat;
	p1->dat = p2->dat;
	p2->dat = temp;
}

struct node * last(struct node * list)
{
	if(list->next == NULL) {
		return list;
	}
	last(list->next);
}

void print(struct node * list)
{
    if(list == NULL){
        return;
    }
    printf("%d\n",list->dat);
    return print(list->next);
}

int main()
{
	struct node * head;
	struct node * list;
	struct node * p;
	struct node * temp;
	int d;
	int x;
	int k;
	scanf("%d",&d);
	scanf("%d",&x);
	head = (struct node *)malloc(sizeof(struct node ));
	list = create(head,x);
	while(1) {
		scanf("%d",&d);
		switch(d) {
			case 1:
				scanf("%d",&x);
				list->next = (struct node *)malloc(sizeof(struct node ));
				list = create(list->next,x); 
				break;
			case 2:
				print(head);
				break;
			case 3:
				p = head;
				temp = list;
				while( p != temp->next) {
					list->next = (struct node *)malloc(sizeof(struct node ));
					list = create(list->next,p->dat); 
					p = p->next;
				}
				break;
			case 4:
				scanf("%d",&k);
				swap(head,k);
				break;
		}
	}
}
