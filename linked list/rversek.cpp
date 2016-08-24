#include <stdio.h>
#include <stdlib.h>

struct node{
    int dat;
    struct node * next;
};

struct node *findend(struct node * list)
{
	if( list->next == NULL) {
		return list;
	}
	return findend(list->next);
}

struct node *create(struct node * list,int x)
{
   list->dat = x;
   list->next = NULL;
   return list;
}

void print (struct node * list)
{
	if(list == NULL) {
		printf("\n");
		return;
	} 
	printf("%d ",list->dat);
	print(list->next);
}

struct node * reversek(struct node * head, int k )
{
	struct node * crnt;
	struct node * next;
	struct node * prev;
	crnt = head;
	int i = 0;
	next = prev = NULL;
	while( i < k && crnt != NULL) {
		next = crnt->next;
		crnt->next = prev;
		prev = crnt;
		crnt = next;
		i++;
	}
	if( next != NULL) {
		head->next = reversek(crnt,k);
	}
	return prev;
	
}

int main()
{
	struct node * head;
	struct node * temp;
	struct node * list;
	int k;
	int x;
	int d;
	scanf("%d%d",&d,&x);
	head = (struct node *)malloc(sizeof(struct node));
	list = create(head,x);
	while(1) {
		scanf("%d",&d);
		switch(d) {
			case 1:
				scanf("%d",&x);
				list = findend(head);
				list->next = (struct node *)malloc(sizeof(struct node ));
				list = create(list->next,x);
				break;
			case 2:
				print(head);
				break;
			case 3:
				scanf("%d",&k);
				head = reversek(head,k);
				break;
				
		}
	}
}

