#include<stdio.h>
#include<stdlib.h>

struct node {
	int dat;
	struct node * right;
	struct node * left;
};

void inorder( struct node * node)
{
	if( node == NULL) {
		return ;
	}
	inorder(node->left);
	printf("%d ",node->dat);
	inorder(node->right);
}


struct node * minval( struct node * node)
{
	while( node->left  != NULL) {
		node = node->left;
	}
	return node;
}


struct node * delnode( struct node * node,int x) {
	struct node * temp;
	if( node == NULL) {
		return node;
	}
	if( node->dat > x) {
		node->left=  delnode(node->left,x);
	} else if( node->dat < x) {
		node->right = delnode(node->right,x);
	}
	else {
		if(node->left == NULL) {
			temp = node->right;
			free(node);
			return temp;
		} else if(node->right == NULL){
			temp = node->left;
			free( node);
			return temp;
		} 
		temp = minval(node->right);
		node->dat = temp->dat;
		node->right = delnode(node->right,temp->dat);
	}
	return node;
}

struct node * delbst( struct node * root)
{
	while( root->left != NULL || root->right != NULL) {
		root = delnode(root,root->dat);
		printf("\n %d deleted\n",root->dat);
		inorder(root);
	}
	return root;
}


struct node * create( struct node * node,int x)
{
	if( node == NULL) {
		node = ( struct node*)malloc( sizeof( struct  node));
		node->dat = x;
		node->right = NULL;
		node->left = NULL;
		return node;
	}
	if( node->dat > x) {
		node->left = create( node->left,x);
	} else {
		node->right = create( node->right , x);
	}
	return node;
}

int main()
{
	struct node * root;
	int n;
	int i;
	int x;
	root = NULL;
	scanf("%d",&n);
	for( i = 0; i < n; i++ ) {
		scanf("%d",&x);
		root = create( root,x);
	}
	inorder(root);
	root = delbst(root);
	inorder(root);
}
