#include<stdio.h>
#include<stdlib.h>

struct stack {
	int ar[100];
	int top;
};

void push( struct stack * st,int x)
{
	st->ar[st->top] = x;
	st->top = st->top + 1;
	return;
}

int isempty( struct stack * st)
{
	if( st->top == 0) {
		return 1;
	}
	return 0;
}

void pop(struct stack * st) 
{
	st->top = st->top - 1;
	return;
}

int top( struct stack * st)
{
	int temp;
	temp = st->ar[st->top-1];
	return temp;
}

void dfs( int a[100][100],int * clr,int * d,int * p,int s,int n)
{
	struct stack * st;
	int i,j,u;
	st = ( struct stack *)malloc(sizeof(struct stack));
	st->top = 0;
	push(st,s - 1);
	clr[s-1] = 1;
	printf("%d ",s);
	while( !isempty(st)) {
		u = top(st);
		if( clr[u] == 0)
			printf("%d ",u + 1);
		clr[u] = 1;
		for( i = 0; i < n; i++) {
			if( a[u][i] == 1 && clr[i] == 0) {
				push(st,i);
				break;
			}
			else if( i == n - 1 ) {
				pop(st);
				clr[u] = 2;;
			}
		}
	}
	
}

int main()
{
	int a[100][100],clr[100] = { 0 };
	int d[100] = { INT_MAX };
	int p[100] = { INT_MIN };
	int i,j,n,s,x,q;
	scanf("%d %d %d",&n,&s,&q);
	for(i = 0; i < q; i++) {
		int c,b;
		scanf("%d %d",&c,&b);
		a[ c - 1][ b - 1] = a[b - 1][c - 1] = 1;
	}
	dfs(a,clr,d,p,s,n);
}
