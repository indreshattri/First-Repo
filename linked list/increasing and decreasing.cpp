 #include<stdio.h>
 #include<stdlib.h>
 
 struct node {
 	int dat;
 	struct node * next;
 };
 
 struct node * create (struct node * list,int x) 
 {
 	list->dat = x;
 	list->next = NULL;
 	return list;
 }
 
 struct node * findk( struct node * head, int i,int k)
{
	if( k == 1) {
		return head;
	} else {
		head = head->next;
		i++;
		while( i != k) {
		head = head->next;
		i++; 
		}
	}
	return head;
 } 
 
struct node * sort( struct node * head,struct node * list) {
 	struct node * temp;
 	struct node * temp1;
 	temp = head;
 	if( head->dat > list->next->dat) {
 		temp1 = list->next;
 		list->next = list->next->next;
 		temp1->next = head;
 		head = temp1;
 		return head;
	 }
 	while ( temp != list )  {
 		if( temp->next->dat > list->next->dat) {
 			temp1 = list->next;
 			list->next = list->next->next;
 			temp1->next = temp->next;
 			temp->next = temp1;
 			break;
		 }
		 temp = temp->next;
	 }
	 return head;
 }
 
 void print ( struct node * list) 
 {
 	if( list == NULL) {
 		printf("\n");
 		return ;
	 }
	printf( "%d ",list->dat);
	print(list->next);
 }
 
 struct node * arrange( struct node * head,struct node * head1)
 {
 	struct node * list;
 	struct node * temp;
 	list = head;
 	while( list != NULL) {
 		if( list->dat > list->next->dat) {
 			break;
		 }
		 list = list->next;
	 }
	temp = list->next;
	list->next = NULL;
	head1 = temp;
	return head1;
 }
 
 int main() 
 {
 	int n,a[100],i;
 	struct node * head;
 	struct node * head1;
 	struct node * list;
 	scanf("%d",&n);
 	for( i = 0; i< n; i++) {
 		scanf("%d",&a[i]);
 		if( i == 0) {
 			head = ( struct node *)malloc(sizeof( struct node ));
 			list = create( head,a[i]);
		 } else {
		 	list->next = ( struct node *)malloc(sizeof( struct node ));
		 	list = create( list->next,a[i]);
		 }
	 }
 	list = head;
 	for( i = 1; i < n ; i++) {
 		list = findk(head,1,i);
 		head = sort(head,list);
	 }
	 print(head);
 }
