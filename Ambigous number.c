#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,*a,*c,b[100000],n,k=0;
    while(1){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        else{
            a=(int *)malloc(n * sizeof(int));
            c=(int *)malloc(n * sizeof(int));
            for(i=0;i<n;i++){
                scanf("%d ",&a[i]);
                c[a[i]-1]=i+1;
            }
            for(i=0;i<n;i++){
                if(i==n-1&&a[i]==c[i]){
                    b[k]=1;
                    k++;
                }
                if(a[i]!=c[i]){
                    b[k]=0;
                    k++;
                    break;
                }
            }
           free(a);
           free(c);

        }
    }
     for(i=0;i<k;i++){
        if(b[i]==1){
            printf("ambiguous\n");
        }
        else{
            printf("not ambiguous\n");
        }
    }
    return 0;
}
