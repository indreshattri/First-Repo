#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,a[1000],key;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        key=a[i];
        for(j=i-1;j>=0&&key<a[j];j--){
            {
                a[j+1]=a[j];
            }
        }
        a[j+1]=key;
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
