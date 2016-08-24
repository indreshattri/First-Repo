#include<stdio.h>
#include<stdlib.h>

struct node {
	int dat;
	struct node * right;
	struct node * left;
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
	printf("%d ",node->dat);
	print( root,node->left,sum);
	print( root,node->right,sum);
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



void delnode( struct node * temp,int x)
{
	int m;
	struct node * p;
		if( temp->right->dat == x ) {
			if( temp->right->right == NULL && temp->right->left == NULL) {
				free(temp->right);
				temp->right = NULL;
				return;
			}
			if( temp->right->right == NULL && temp->right->left != NULL) {
				p = temp->right;
				temp->right = temp->right->left;
				free(p);
				return;
			}
			if( temp->right->right != NULL && temp->right->left == NULL) {
				p = temp->right;
				temp->right = temp->right->right;
				free(p);
				return;
			}
			if( temp->right->right != NULL && temp->right->left != NULL) {
				p = temp->right->left;
				struct node * w;
				w = temp->right;
				printf("%d jjjjjjjjjjj \n",temp->dat);
				if( p->right != NULL ) {
					w = w->left;
					p = p->right;
				}
				while(p->right != NULL) {
					p = p->right;
					w = w->right;
				}
				m = p->dat;
				p->dat = temp->right->dat;
				temp->right->dat = m;
				printf("%d jjjjjjjjjjj \n",w->dat);
				return delnode(w,p->dat);
			}
		}
		if( temp->left->dat == x ) {
			if(temp->left->right == NULL && temp->left->left == NULL) {
				free(temp->left);
				temp->left = NULL;
				return;
			}
			if( temp->left->right == NULL && temp->right->left != NULL) {
				p = temp->left;
				temp->left= temp->left->left;
				free(p);
				return;
			}
			if( temp->left->right != NULL && temp->left->left == NULL) {
				p = temp->left;
				temp->left = temp->left->right;
				free(p);
				return;
			}
			if( temp->left->right != NULL && temp->left->left != NULL) {
				p = temp->left->left;
				struct node * w;
				w = temp->left;
				if( p->right != NULL) {
					w = w->left;
					p = p->right;
				}
				while( p->right != NULL) {
					p = p->right;
					w = w->right;
				}
				m = p->dat;
				p->dat = temp->left->dat;
				temp->left->dat = m;
				return delnode(w,p->dat);
			}
		}
}

void del( struct node * root, int x) {
	struct node * temp;
	temp= findx(root,x);
	delnode( temp,x);
}

int main()
{
	int  i,x;
	int sum;
	sum = 0;
	struct node * root;
	root = (struct node * )malloc(sizeof(struct node));
	int n;
	scanf("%d",&n);
	for( i = 0; i < n; i++) {
		scanf("%d",&x);
		if( i == 0) {
			root->dat = x;
			root->right = NULL;
			root->left = NULL;
		} else {
			create( root,x);
		}
	}
	sum = 0;
	print(root,root,&sum);
	printf("\n");
}
