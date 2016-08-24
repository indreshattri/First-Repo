#include<stdio.h>
#include<stdlib.h>

struct node  {
	int dat;
	struct node * left;
	struct node * right;
};

struct queue {
	struct node * a[100];
	int front;
	int rear;
};

struct node * create( struct node * node, int x) {
	if( node == NULL) {
		node = ( struct node * )malloc( sizeof( struct node));
		node->left = NULL;
		node->dat = x;
		node->right = NULL;
		return node;
	}
	if( node->dat > x) {
		node->left = create( node->left,x);
	} else {
		node->right = create( node->right,x);
	}
}

void enq( struct queue * q,struct node * node) 
{
	q->a[q->rear] = node;
	q->rear = q->rear + 1;
	return; 
}

struct node * deq( struct queue * q)
{
	struct node * temp;
	temp = q->a[q->front];
	q->front = q->front + 1;
	return temp;
}

int isempty( struct queue * q)
{
	if( q->front == q->rear) {
		return 1;
	}
	return 0;
}

int checkcomplete( struct node * root,int n )
{
	printf("SS \n");
	int flag = 0;
	struct queue * q;
	q = ( struct queue*)malloc( sizeof( struct queue));
	struct node * temp;
	q->front = 0;
	q->rear = 0;
	int i;
	i = 1;
	enq(q,root);
	while( !isempty(q) ) {
		temp = deq( q);
		if( temp->left != NULL) {
			enq(q,temp->left);
		}
		if( temp->right != NULL) {
			enq( q,temp->right);
		}
		if( (temp->right == NULL || temp->left == NULL) && flag == 0) {
			flag = 1;
		}
		if( (temp->right != NULL || temp->left != NULL) && flag == 1) {
			flag = 2;
		}
		if( i == n) {
			if( flag == 1) {
				return 1;
			} else {
				return 0;
			}
		}
		i++;
	}
	
}

int main()
{
	int i;
	int n; 
	int x;
	struct node * root;
	root = ( struct node *)malloc( sizeof( struct node));
	scanf("%d",&n);
	scanf("%d",&x);
	root->dat = x;
	root->left = NULL;
	root->right = NULL;
	for( i = 0; i < n - 1; i++) {
		scanf("%d",&x);
		create(root,x);
	}
	if(checkcomplete( root,n)) {
		printf("Y\n");
	} else {
		printf("N\n");
	}
}

