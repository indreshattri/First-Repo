#include<stdio.h>
#include<stdlib.h>

struct node {
	int dat;
	struct node * left;
	struct node * right;
};

struct node * create( struct node * node, int x)
{
	if( node == NULL) {
		node = ( struct node *)malloc( sizeof( struct node));
		node->dat = x;
		node->right = NULL;
		node->left = NULL;
		return node;
	}
	if( node->dat < x) {
		node->right = create( node->right,x);
	}
	if( node->dat > x) {
		node->left = create( node->left,x);
	}
	return node;
}

struct node * newroot( struct node * node,int a,int b)
{
	struct node * temp;
	if( node->dat >= a && node->dat <= b) {
		printf("node->dat %d\n",node->dat);
		return node;
	}
	if( node->dat > a) {
		return newroot( node->left,a,b);
	}
	if( temp->dat < a) {
		return newroot( node->right,a,b);
	}
}

int search( struct node * node,int x,int i)
{
	if( node->dat == x) {
		return i;
	}
	if( node->dat < x) {
		return search( node->right,x,i + 1);
	}
	if( node->dat > x) {
		return search( node->left,x,i + 1);
	}
}

int mindis( struct node * root,int a,int b)
{
	int i;
	i = 0;
	struct node * temp;
	printf("MINdis\n");
	temp = newroot( root,a,b);
	printf("temp->dat %d\n",temp->dat);
	i = search( temp,a,0);
	i = search( temp,b,i);
	return i;
}

int main()
{
	int i,n,x,q,a,b;
	struct node * root;
	root = NULL;
	scanf("%d",&n);
	for( i = 0; i < n; i++) {
		scanf("%d",&x);
		root = create(root,x);
	}
	scanf("%d",&q);
	for( i = 0; i < q; i++) {
		scanf("%d %d",&a,&b);
		if( a > b) {
			n = a;
			a = b;
			b = n;
		}
		x = mindis(root,a,b);
		printf("%d\n",x);
	}
}
