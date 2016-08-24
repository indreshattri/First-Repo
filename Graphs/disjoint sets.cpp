#include<stdio.h>
#include<stdlib.h>

struct node {
	int dat;
	struct node * next;
	struct node * rep;
};

struct node * findset( int x,struct node * *a) 
{
	struct node * temp;
	temp = a[x];
	return temp->rep;
}

void Union( int x,int y,struct node * *a)
{
	printf("p\n");
	struct node * temp;
	struct node * list1;
	struct node * list2;
	list1 = findset(x,a);
	list2 = findset(y,a);
	temp = list1;
	printf("list1->dat %d list2->dat %d\n",list1->dat,list2->dat);
	if( list1 == list2) {
		return;
	}
	while( temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = list2;
	temp = list2;
	while( temp != NULL) {
		temp->rep = list1;
		temp= temp->next;
	}
	printf("s\n");
}

void makeset( struct node* * a,int x )
{
	int n;
	int i;
	struct node * head;
	struct node * temp;
	head = (struct node * )malloc(sizeof(struct node));
	head->dat = x;
	head->rep = head;
	head->next = NULL;
	a[x] = head;
	return;

}

int main()
{
	int g[100][100];
	struct node *a[100];
	struct node * temp;
	int i;
	int x;
	int j;
	int n;
	int k;
	int q;
	int p[100];
	j = 0;
	scanf("%d",&n);
	for( i = 0; i < n; i++) {
		for( j = 0; j < n; j++) {
			scanf("%d",&g[i][j]);
		}
	}
	for( i = 0; i < n; i++) {
		makeset(a,i);
	}
	printf("j\n");
	for( i = 0; i < n; i++) {
		for( j = i + 1; j < n; j++) {
			if( g[i][j] == 1 ) {
				Union(i,j,a);
			}
		}
	}
	for( i = 0; i < n; i++) {
		temp = findset(i,a);
		p[i] = temp->dat;
		if( p[i] == i) {
			printf("%d ",i + 1);
		}
	}
	
}
