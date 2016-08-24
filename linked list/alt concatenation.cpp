#include <stdio.h>
#include <stdlib.h>

struct node{
    int dat;
    struct node * next;
};

void link(struct node *p1, struct node * p2,struct node * head2) 
{
	struct node * temp;
	temp = p2->next;
	p2->next = p1->next->next;
	p1->next->next = temp;
	while( temp->next != NULL ) {
		temp = temp->next;
	}
	temp->next = head2;
	return;
}

struct node * max(struct node * head)
{
	struct node *p;
	int max;
	max = head->dat;
	p = head;
	while( head->next != NULL ) {
		if( head->next->dat > max ) {
			max = head->next->dat;
			p = head;
		}
		head = head->next;
	}
	return p;
}

struct node *concat (struct node * list1,struct node * list2)
{
	struct node * temp1;
	struct node * temp2;
	struct node * head1;
	head1 = list1;
	while(list2 != NULL ) {
		temp1 = list1->next;
		temp2 = list2->next;
		list1->next = list2;
		list2->next = temp1;
		list1 = list1->next->next;
		list2 = temp2;
	}
	return head1;
}

struct node * last(struct node * list)
{
	if(list->next == NULL) {
		return list;
	}
	last(list->next);
}

struct node *create(struct node * list,int x)
{
   list->dat = x;
   list->next = NULL;
   return list;
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
	struct node * head1;
	struct node * head2;
	int flag1 = 0;
	int x;
	int flag2 = 0;
	struct node * list1;
	struct node * p1;
	struct node * p2;
	struct node * list2;
	int d;
	while(1) {
		scanf("%d",&d);
		switch(d) {
			case 1:
				
				scanf("%d",&x);
				if(flag1 == 0) {
					head1 = (struct node *)malloc(sizeof(struct node ));
					flag1 = 1;
					list1 = create(head1,x);
				} else {
					list1->next = (struct node *)malloc(sizeof(struct node ));
					list1 = create(list1->next,x);
				}
				
				break;
			case 2:
				scanf("%d",&x);
				if(flag2 == 0) {
					head2 = (struct node *)malloc(sizeof(struct node ));
					flag2 = 1;
					list2 = create(head2,x);
				} else {
					list2->next = (struct node *)malloc(sizeof(struct node ));
					list2 = create(list2->next,x);
				}
				break;
			case 3:
				print(head1);
				break;
			case 4:
				print(head2);
				break;
			case 5:
				head1 = concat(head1,head2);
				break;
			case 6:
				print(head1);
				break;
			case 7:
				p1 = max(head1);
				printf("%d    m1\n",p1->next->dat);
				p2 = max(head2);
				printf("%d    m1\n",p2->next->dat);
				link(p1,p2,head2);
			case 8:
				printf("\n");
				print(head1);
				printf("\n");
			case 9:
				exit(1);
		}
			
	}
}
