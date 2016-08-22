#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,b,t,p[1000][2];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d",&a,&b);
        p[i][1] = a+b;
        if(a>b){
            p[i][0]=a;
        }
        else{
            p[i][0]=b;
        }
    }
    for(i=0;i<t;i++){
        printf("%d %d",p[i][0],p[i][1]);
    }
    return 0;
}
