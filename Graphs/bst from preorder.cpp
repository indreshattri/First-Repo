#include<stdio.h>
#include<stdlib.h>

struct node {
	int dat;
	struct node * left;
	struct node * right;
};

void construct( struct node * node,int * a,int l,int r)
{
	if( l > r) {
		return;
	}
	printf("node->dat %d l %d r %d\n",node->dat,l,r);
	if(l == r) {
		if( node->dat < a[l]) {
			node->right = ( struct node *)malloc(sizeof( struct node));
			node->right->dat = a[l];
			node->right->left = NULL;
			node->right->right = NULL;
		} else {
			node->left = ( struct node *)malloc( sizeof( struct node));
			node->left->dat = a[l];
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}
	int i;
	for( i = l; i <= r; i++) {
		if( a[i] > node->dat) {
			break;
		}
	}
	
	if(a[l - 1] > a[l] ) {
		node->left = ( struct node *)malloc(sizeof( struct node));
		node->left->dat = a[l];
		node->left->left = NULL;
		node->left->right = NULL;
		construct(node->left,a,l + 1,i - 1);
	}
	if( i <= r) {
		node->right =  ( struct node *)malloc(sizeof( struct node));
		node->right->dat = a[i];
		node->right->left = NULL;
		node->right->right = NULL;
		construct(node->right,a,i + 1,r);
	}
	printf("Completed\n");
}

void preorder( struct node * node)
{
	if( node == NULL) {
		return ;
	}
	printf("%d ",node->dat );
	preorder(node->left);
	preorder(node->right);
}

int main()
{
    struct node * root;
	int i;
	int n;
	int a[100];
	scanf("%d",&n);
	for ( i = 0 ; i < n; i++) {
		scanf("%d",&a[i]);
		printf("%d\n",a[i]);
	}
	printf("P\n");
	root = ( struct node *)malloc(sizeof( struct node));
	printf("P\n");
	root->dat = a[0];
	printf("P\n");
	root->left = NULL;
	printf("P\n");
	root->right = NULL;
	printf("P\n");
	construct(root,a,1,n-1);
	preorder(root);
}
