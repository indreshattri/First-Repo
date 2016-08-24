#include <stdio.h>
#include <stdlib.h>

struct node{
    int dat;
    struct node * next;
};

int freq(struct node * list)
{
	int n;
	int k;
	k = list->dat;
	n = 0;
	while(list != NULL) {
		if(list->dat == k) {
			n++;
		}
		list = list->next;
	}
	printf("%d   f\n",n);
	return n;
}

int size(struct node * list)
{
	int i = 0;
	while( list != NULL) {
		i++;
		list = list->next;
	}
	return i;
}

int find( struct node * list,int k)
{
	int i;
	i = 1;
	while( i != k) {
		list = list->next;
		i++;
	}
	return list->dat;
}

int palin(struct node * head)
{
	int i;
	int j;
	struct node * list;
	int k;
	int n;
	i = 1;
	n = size(head);
	list = head;
	while(list != NULL) {
		j = find(head,i);
		k = find(head,n+1-i);
		if( j != k ) {
			return 0;
		} 
		list = list->next;
	}
	return 1;
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
    			int q;
    			q = palin(head);
    			if(q == 1) {
    				printf("YES\n");
				} else {
					printf("NO\n");
				}
				break;
			case 3:
				int a[1000][2];
				int i;
				i = -1;
				int j;
				int flag;
				flag = 1;
				struct node * list;
				list = head;
				while(list != NULL) {
					flag = 1;
					for( j = 0;j <= i; j++ ) {
						if ( a[j][0] == list->dat) {
							flag = 0;
						}
					}
					if( flag == 1) {
						i++;
						a[i][0] = list->dat;
						a[i][1] = freq(list);
					}
					list = list->next;
				}
				for( j = 0; j <=i; j++) {
					printf("%d %d\n",a[j][0],a[j][1]);
				}
				break;
    	}
    }
}
