#include <stdio.h>
#include <stdlib.h>

struct node{
    int dat;
    struct node * next;
};

void swap_alt(struct node * list,struct node * temp)
{
	int tr;
	tr = temp->dat;
	temp->dat = list->dat;
	list->dat = tr;
	if(temp->next == NULL  ) {
		return;
	}
	if(list->next == NULL  ) {
		return;
	}
	swap_alt(list->next->next,temp->next->next);
	return;
}

struct node * last(struct node * list)
{
	if(list->next == NULL) {
		return list;
	}
	last(list->next);
}

struct node *reverse (struct node *list, struct node * temp,struct node * head,int i)
{
	if(list == NULL ) {
		return head;
	}
	head = reverse(list->next,temp->next,head,i+1);
	if(i == 1) {
		temp->next = NULL;
		list->next = temp;
	} else {
		if(list->next == NULL) {
			head = list;
			list->next = temp;
		} else {
			list->next = temp;
		}
	}
	return head;
}

void sort (struct node * list,struct node * temp )
{
	int tr;
	if(temp == list) {
		return;
	}
	if(list->dat < temp->dat) {
		tr = list->dat;
		list->dat = temp->dat;
		temp->dat = tr;
		return;
	}
	return sort(list,temp->next);
}

void insertion(struct node * list ,struct node * head ) 
{
	while(list != NULL ) {
		sort(list,head);
		list = list->next;
	}
	return;
}

struct node * findk(struct node * list,int k,int i) 
{
	if( i == k-1) {
		return list;
	}
	return findk(list->next,k,i+1);
}

struct node * insert (struct node * head,int k,int x) 
{
	struct node *temp;
	struct node * p;;
	if( k == 1) {
		temp = (struct node *)malloc(sizeof(struct node));
		temp->next = head;
		temp->dat = x;
		head = temp;
	} else {
		p = findk(head,k,1);
		if(p->next == NULL) {
			temp = (struct node *)malloc(sizeof(struct node));
			temp->dat = x;
			p->next = temp;
			temp->next = NULL;
		} else {
			temp = (struct node *)malloc(sizeof(struct node));
			temp->dat = x;
			temp->next = p->next;
			p->next = temp;
		}
	}
	return head;
}

struct node *find(struct node * list,int x) 
{
	if( list->next->dat == x) {
		return list;
	}
	return find(list->next,x);
}

struct node *del(struct node * head,int x) 
{
	struct node *p;
	struct node *temp;
	if( head->dat == x ) {
		temp = head->next;
		free(head);
		head = temp;
	} else {
		p = find(head,x);
		if( p->next->next == NULL ) {
			free(p->next);
			p->next = NULL;
		} else {
			temp = p->next->next;
			free(p->next);
			p->next = temp;
		}
	}
	return head;
}

struct node *create(struct node * list,int x)
{
   list->dat = x;
   list->next = NULL;
   return list;
}

print(struct node * list)
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
    struct node * crt;
   	struct node * next1;
    struct node * prev;
    int d;
    int k;
    int x;
    head = NULL;
    head = (struct node *) (malloc(sizeof(struct node)));
    scanf("%d%d",&d,&x);
    list = create(head,x);
    while(1) {
    	scanf("%d",&d);
    	switch(d) {
    		case 1:
    			scanf("%d",&x);
    			list = last(head);
    			list->next = (struct node *)malloc(sizeof(struct node));
    			list = create(list->next,x);
    			break;
    		case 2:
    			scanf("%d",&x);
    			head = del(head,x);
    			break;
    		case 3:
    			print(head);
    			break;
    		case 4:
    			scanf("%d%d",&k,&x);
    			head = insert(head,k,x);
    			break;
    		case 5:
    			insertion(head->next,head);
    			break;
    		case 6:
    			
    			crt = head;
    			prev = NULL;  z
    			while( crt->next != NULL) {
    				next1 = crt->next;
    				crt->next = prev;
    				prev = crt;
    				crt = next1;
    				
				}
				crt->next = prev;
				head = crt;
    			break;
    		case 7:
    			swap_alt(head->next,head);
    			break;
		}
	}
    return 0;
}
