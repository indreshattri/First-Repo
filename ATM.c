#include <stdio.h>
#include <stdlib.h>
int main()
{
   int n,m,s,ctr=0,i;
   scanf("%d %d",&n,&m);
   for(i=0;i<n;i++){
        scanf("%d",&s);
        if(s%m==0){
            ctr++;
        }
   }
   printf("%d",ctr);
}
