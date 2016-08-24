#include <stdio.h>
#include <stdlib.h>

struct node{
    int dat;
    struct node * next;
    struct node * prev;
};

struct node * find(struct node * list,int key) 
{
	if( list->dat == key ) {
		return list;
	} else {
		return find(list->next,key);
	}
}

struct node * findk(struct node * list,int k,int i) 
{
	if( i == k - 1 ) {
		return list;
	} else {
		return findk(list->next,k,i+1);
	}
}



struct node * insertb( struct node * head, int k,int g) 
{
	struct node * p;
	struct node * temp2;
	struct node * temp1;
	temp2 = (struct node *)malloc(sizeof(struct node));
	temp2->dat = g;
	if ( k == 1) {
		head->prev = temp2;
		temp2->next = head;
		head = temp2;
		head->prev = NULL; 
	} else {
		p = findk(head,k,1);
		if ( p->next == NULL) {
			p->next = temp2;
			temp2->prev = p;
			temp2->next = NULL;
		} else {
			temp1 = p->next;
			temp1->prev = temp2;
			temp2->next = temp1;
			p->next = temp2;
			temp2->prev = p;
		}
	}
	return head;
}

struct node * del(int key,struct node * head) 
{
	struct node *p;
	struct node *temp1;
	struct node *temp2;
	if( head->dat == key ) {
		temp1 = head->next;
		free(head);
		head = temp1;
		head->prev = NULL;
	} else {
		p = find(head,key);
		if( p->next == NULL) {
			p->prev->next = NULL;
			free(p);
		} else {
			temp1 = p->prev;
			temp2 = p->next;
			p->prev->next = temp2;
			p->next->prev = temp1;
			free(p);
				
		}
	}
	return head;
}

struct node * create(struct node * list )
{
	struct node * temp;
    scanf("%d",&list->dat);
    list->next = NULL;
    temp = list;
    return temp;
}

void printp(struct node * list ) {
	if(list == NULL) {
        return;
    }
    	printf("%d\n",list->dat);
        printp(list->prev);

}

void print(struct node * list)
{
    if(list->next == NULL){
    	printf("%d\n",list->dat);
    	printp(list->prev);
        return;
    }
        print(list->next);

}
int main()
{
	int d,key;
    struct node * head;
    struct node * temp;
    temp =  NULL;
    head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
   	printf("1 for insertion   2 for deletion   3 for printing   4 to insert at kth position   5 to exit  \n");
    scanf("%d",&d);
    temp = create(head);
    while(1) {
    	printf("1 for insertion   2 for deletion   3 for printing   4 to insert at kth position   5 to exit  \n");
    	int d;
    	scanf("%d",&d);
    	switch(d) {
    		case 1:
    			temp->next = (struct node *)malloc(sizeof(struct node));
    			temp->next->prev = temp;
    			temp = create(temp->next);
    			break;
    		case 2:
    			scanf("%d",&key);
    			head = del(key,head);
    			break;
    			
    		case 3:
    			print(head);
    			break;
    		case 4:
    			int k,g;
    			scanf("%d%d",&k,&g);
    			head = insertb(head,k,g);
    			break;
    		case 5:
    			exit(1);
		}
	}
    return 0;
}
