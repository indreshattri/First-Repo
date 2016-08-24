#include<stdio.h>
int partition(int *a,int l,int r)
{
    int i,pindex,pivot,temp;
    pivot=a[r];
    pindex=l;
    for(i=l;i<r;i++){
    	if(a[i]<pivot){
    		temp=a[i];
    		a[i]=a[pindex];
    		a[pindex]=temp;
    		pindex++;
		}
	}
		temp=pivot;
		pivot=a[pindex];
		a[pindex]=temp;
        return pindex;
}
void quicksort(int *a,int l,int r)
{
	int index;
    if(l >= r){
        return;
    }
    index=partition(a,l,r);
    quicksort(a,l,index-1);
    quicksort(a,index+1,r);
}
int main()
{
    int i,n,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
