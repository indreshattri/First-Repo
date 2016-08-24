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

int isempty( struct queue * q) 
{
	if( q->front == q->rear) {
		return 1;
	}
	return 0;
} 

void bfs( int a[100][100], int * clr, int s,int n)
{
	int i,j,u;
	struct queue * q;
	q = ( struct queue *)malloc( sizeof( struct queue));
	q->front = 0;
	q->rear = 0;
	clr[ s- 1 ] = 1;
	enq( q,s - 1);
	while(!isempty(q)) {
		u = pop(q);
		for( i = 0; i < n; i++) {
			if( a[u][i] == 1 && clr[i] == 0) {
				enq(q,i);
				clr[i] = 1;
			}
		}
		clr[u] = 2;
	}
}

void articulation( int a[100][100],int c, int n)
{
	int i,j,k,ctr ,A[100][100];
	for( i = 0; i< n; i++) {
		ctr = 0;
		int clr[100] = {0};
		for( j = 0; j < n; j++) {
			for( k = 0; k < n; k++) {
				if( j == i || k == i) {
					A[j][k] = 0;
				} else {
					A[j][k] = a[j][k];
				}
			}
		}
		for( j = 0; j <n; j++) {
			if( clr[j] == 0) {
				bfs(A,clr,j,n);
				ctr++;
			}
		}
		if( ctr - 1 > c) {
			printf("%d ",i + 1);
		}
	}
}

int main()
{
	int i,j,a[100][100],clr[100] = {0},c = 0,n;
	scanf("%d",&n);
	for( i = 0; i < n; i++) {
		for( j = 0; j < n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for( i = 0; i < n; i++) {
		if( clr[i] == 0) {
			bfs(a,clr,i,n);
			c++;
		}
	}
	printf("ppp");
	articulation(a,c,n);
}
