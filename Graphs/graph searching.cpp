#include<stdio.h>
#include<stdlib.h>

struct queue {
	int a[100];
	int front;
	int rear;
};

void enq( struct queue * q, int x) 
{
	q->a[q->front] = x;
	q->front = q->front + 1;
	return;
}

int pop( struct queue *q)
{
	int temp;
	temp = q->a[q->rear];
	q->rear = q->rear + 1;
	return temp;
}

void bfs( int a[100][100], int * clr, int * d, int * p, int s,int n)
{
	int i,j,u;
	struct queue * q;
	q = ( struct queue *)malloc( sizeof( struct queue));
	q->front = 0;
	q->rear = 0;
	clr[ s- 1 ] = 1;
	d[s - 1] = 0;
	enq( q,s - 1);
	for( i = 0; i < n; i++) {
		u = pop(q);
		printf("%d ",u + 1);
		for( j =0 ; j < n; j++) {
			if( a[u][j] == 1 && clr[j] == 0) {
				enq( q,j);
				p[j] = u;
				clr[j] = 1;
			}
		}
		clr[j] = 2;
	}
	
}

int main()
{
	int i;
	int j;
	int n;
	int s;
	int a[100][100];
	int clr[100] = { 0 };
	int d[100] = { INT_MAX};
	int p[100] = { INT_MIN};
	scanf("%d %d",&n,&s);
	for( i = 0; i < n; i++) {
		for( j= 0; j < n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	bfs( a,clr,d,p,s,n);
}
