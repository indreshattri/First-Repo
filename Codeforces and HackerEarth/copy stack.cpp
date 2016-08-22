#include<stdio.h>
#include<stdlib.h>

struct stack 
{
	int size;
	int a[100];
};

struct stack copy(struct stack s1)
{
	struct stack s2;
	int i;
	for(i=0;i<8;i++){
		s2.a[i]=s1.a[i];
	}
	return s2;
}

int main(){
	struct stack s1,s2;
	int i=0;
	for(i=0;i<8;i++){
		scanf("%d",&s1.a[i]);
	}
	s2 = copy(s1);
	for(i=0;i<8;i++){
		printf("%d\n",s2.a[i]);
	}
}
