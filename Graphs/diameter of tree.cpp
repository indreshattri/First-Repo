#include<stdio.h>
#include<stdlib.h>

struct node {
	int dat;
	struct node * left;
	struct node * right;
};

int  diameter( struct node * node, int * max)
{
	int lht;
	int rht;
	int p;
	if( node == NULL ) {
		return 0;
	}
	lht = diameter(node->left,max);
	rht = diameter(node->right,max);
	if( lht > rht) {
		p = 1 + lht;
	} else {
		p = rht + 1;
	}
	printf("node->dat %d lht %d rht  %d   *max\n",node->dat,lht,rht,*max);
	if( lht + rht > *max) {
		*max = lht + rht;
	}
	return p;
}

struct node * create( struct node * node, int x)
{
	if( node == NULL) {
		node = ( struct node *)malloc( sizeof( struct node));
		node->dat = x;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	if( node->dat > x) {
		node->left = create( node->left,x);
	} else {
		node->right = create( node->right,x);
	}
	return node;
}

int main()
{
	struct node * root;
	root = NULL;
	int n;
	int i;
	int x;
	int max;
	scanf("%d",&n);
	for( i = 0; i < n; i++) {
		scanf("%d",&x);
		root = create( root,x);
	}
	max = 0;
	x = diameter(root,&max);
	printf("%d diameter",max + 1);
}
