#include<stdio.h>
#include<stdlib.h>

struct stack {
	int arr[100];
	int top;
};

void push(struct stack * node,int x)
{
	node->top = node->top + 1;
	node->arr[node->top] = x;

	return ;

}

int pop(struct stack * node)
{

	return node->arr[node->top];
}

int isdigit(char c)
{
	if(c > 47 && c < 58 ) {
		return 1;
	}
	else {
		return 0;
	}
}

int oprn (char oprtr,int m,int n)
{

	switch (oprtr) {
		case '+':{
			return n + m;

		}
		case '-':{
			return n - m;

		}
		case '*':{
			return n * m;

		}
		case '/':{
			return (n) / (m);
		}
	}
}
int main()
{
	int i = 0,m,n,t,j;
	int reslt;
	int flag;
	char a[100],c;
	struct stack *s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->top = -1;
	while( ( c = getchar()) != '\n' ) {
		a[i] = c;
		i++;
	}
	a[i] = '\0';
	i = 0;
	t = 0;
	flag = 0;
	while( a[i] != '\0' ) {
		if( isdigit(a[i]) ) {
			j = a[i] - '0';
			t = 10 * t + j;
            flag = 1;
		}
		else if(a[i] == ' ' && flag == 1){
			push(s,t);
			t = 0;
			flag = 0;
		}
		else if( a[i] != ' ')  {
			m = pop(s);
			s->top = s->top - 1;
			n = pop(s);
			s->top = s->top - 1;
			reslt = oprn(a[i],m,n);
			push(s,reslt);
		}
		i++;
	}
	reslt = pop(s);
	printf("%d",reslt);
}
