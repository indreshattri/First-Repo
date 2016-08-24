#include <stdio.h>
#include <stdlib.h>

struct node{
    int dat;
    struct node * next;
};

void grtr_r(struct node * list,struct node *temp)
{
	int flag = 0;
	if( temp->dat >  list->dat ) {
		temp->next = list->next;
		free(list);
		temp = temp->next;
		list = temp->next;
		flag = 1;
		
	}
	if(list == NULL){
		return;
	}
	if(list->next == NULL) {
		return;
	}
	if( flag == 0) {
		temp = temp->next->next;
		list = list->next->next;
	}
	grtr_r(list,temp);
}

void printk(struct node * list,int k) 
{
	int i;
	i = 1;
	while( list != NULL) {
		if( i == k ) {
			printf("%d\n",list->dat);
			i = 0;
		}
		i++;
		list = list->next;
	}
	return;
}

struct node * last(struct node * list)
{
	if(list->next == NULL) {
		return list;
	}
	last(list->next);
}

void del (struct node * list)
{
	struct node * temp;
	printf("%d   d\n",list->dat);
	if(list->next->next == NULL) {
		temp = list->next;
		list->next = NULL;
		free(temp);
		return;
	}
	temp = list->next;
	list->next = list->next->next;
	free(temp);
	return;
}

void dup(struct node * list)
{
	int k;
	k = list->dat;
	while( list != NULL ) {
		if(list->next != NULL) {
	
			if(list->next->dat == k ) {
				del(list);
			}
			else
			list = list->next;
		}
		if(list->next == NULL) {
			break;
		}
	}
	return;
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
	struct node * head;
    struct node * list;
    struct node * temp;
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
    			temp = head;
    			while(temp->next != NULL ) {
    				dup(temp);
    				print(head);
    				printf("g   \n");
    				temp = temp->next;
    				if(temp == NULL) {
    					break;
					}
				}
				break;
			case 3:
				printf("\n");
				print(head);
				printf("\n");
				break;
			case 4:
				int k;
				scanf("%d",&k);
				printf("%d\n",head->dat);
				printk(head->next,k);
				break;
			case 5:
				grtr_r(head->next,head);
				break;
		}
	}
				
}
