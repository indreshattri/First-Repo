#include<stdio.h>
#include<stdlib.h>

struct node {
	int dat;
	struct node * right;
	struct node * left;
};

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

struct node * findm( int x,struct node * node, struct node * node1,int * i)
{
	if( node->right->dat == x) {
		*i = 1;
		return node1;
	}
	if( node->left->dat == x) {
		*i = 0;
		return node1;
	}
	if( node->dat < x) {
		node1= node1->left;
		return findm(x,node->right,node1,i);
	}
	if( node->dat > x) {
		node1= node1->right;
		return findm( x,node->left,node1,i);
	}
}

void createmirror( int x, struct node * root, struct node * root1) 
{
	struct node * temp;
	int i;
	i = 0;
	temp = findm( x,root,root1,&i);
	if( i == 0) {
		temp->right = ( struct node * )malloc( sizeof( struct node));
		temp->right->dat = x;
		temp->right->right = NULL;
		temp->right->left = NULL;
	}
	if( i == 1) {
		temp->left = ( struct node * )malloc( sizeof( struct node));
		temp->left->dat = x;
		temp->left->right = NULL;
		temp->left->left = NULL;
	}
}

void traverse( struct node * node, struct node *root,struct node * root1)
{
	if( node == NULL) {
		return;
	}
	if( node->right != NULL) {
		createmirror(node->right->dat,root,root1 );
		traverse( node->right,root,root1);
	}
	if( node->left != NULL) {
		createmirror( node->left->dat,root,root1);
		traverse( node->left,root,root1);
	}
	return;
} 

void print( struct node * node)
{
	if( node == NULL) {
		return;
	}
	printf("%d ",node->dat);
	print(node->right);
	print(node->left);
}

int main()
{
	struct node* root1;
	struct node * root;
	int n;
	int x;
	int i;
	scanf("%d",&n);
	scanf("%d",&x);
	root = ( struct node *)malloc( sizeof( struct node));
	root1 = ( struct node *)malloc( sizeof( struct node));
	root->dat = x;
	root->left = NULL;
	root->right = NULL;
	root1->dat = x;
	root1->left = NULL;
	root1->right = NULL;
	for( i = 0; i < n - 1; i++) {
		scanf("%d",&x);
		create(root,x);
	}
	print(root);
	traverse( root,root,root1);
	printf("\n");
	print( root1);
}
