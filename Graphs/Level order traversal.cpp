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


struct node * findx( struct node * node, int x)
{
	if( node->right->dat == x || node->left->dat == x) {
		return node;
	}
	if( node->dat > x) {
		return findx( node->left,x);
	} else {
		return findx(node->right,x);
	}
}

void findp(struct node * node,int x)  
{
	if( node->dat == x) {
		printf("%d \n",node->dat);
		return;
	}
	printf("%d ",node->dat);
	if( node->dat > x) {
		findp(node->left,x);
	} else {
		findp(node->right,x);
	}
}

void print( struct node * root,struct node * node,int * sum)
{
	if( node == NULL) {
		return;
	}
	
	if( node->right == NULL && node->left == NULL) {
		*sum = *sum + node->dat;
		findp(root,node->dat);
	}
	print( root,node->right,sum);
	print( root,node->left,sum);
}

struct node * find( struct node * node,int x) 
{
	
	if( node->dat < x) {
		
		if( node->right == NULL) {
			
			return node;
		}
		return find( node->right,x);
	}
	if( node->dat >= x) {
		if( node->left == NULL) {
			
			return node;
		}
		return find(node->left,x);
	}
	
}

void create( struct node * root, int x)
{
	
	struct node * temp;
	temp = find(root,x);
	
	if( temp->dat < x) {
		temp->right = ( struct node *)malloc( sizeof( struct node));
		temp->right->dat = x;
		temp->right->left = NULL;
		temp->right->right = NULL;
		
	} else {
		
		temp->left = ( struct node *)malloc( sizeof( struct node));
		temp->left->dat = x;
		temp->left->left = NULL;
		temp->left->right = NULL;
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

void levelorder( struct node * root)
{
	printf("SS \n");
	struct queue * q;
	q = ( struct queue*)malloc( sizeof( struct queue));
	struct node * temp;
	q->front = 0;
	q->rear = 0;
	enq(q,root);
	while( !isempty(q) ) {
		temp = deq( q);
		printf("%d ",temp->dat);
		if( temp->left != NULL) {
			enq(q,temp->left);
		}
		if( temp->right != NULL) {
			enq( q,temp->right);
		}
	}
	
}

int main() 
{
	struct node * root;
	int n;
	int i;
	int x;
	root = ( struct node *)malloc( sizeof( struct node));
	scanf("%d",&n);
	scanf("%d",&x);
	root->dat = x;
	root->left = NULL;
	root->right = NULL;
	printf("TS \n");
	for( i = 0; i < n - 1; i++) {
		scanf("%d",&x);
		create(root,x);
	}
	printf("SS \n");
	levelorder(root);
}
