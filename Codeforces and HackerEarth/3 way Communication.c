#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int i,ctr=0,t;
    float x,y,x1,x2,y1,y2,s1,s2,s3,r;

    scanf("%d",&t);
    for(i=0;i<t;i++){
            ctr=0;
        scanf("%f%f%f%f%f%f%f",&r,&x,&y,&x1,&y1,&x2,&y2);
        s1=((x-x1) * (x-x1) + (y - y1) * (y - y1));
        s2=((x2-x1) * (x2-x1) + (y2 - y1) * (y2 - y1));
        s3=((x-x2) * (x-x2) + (y - y2) * (y - y2));
        if(s1 <=r*r){
           ctr++;
        }
        if(s2 <= r*r){
            ctr++;
        }
        if(s2 <= r*r){
            ctr++;
        }
        if(ctr >=2){
            printf("yes\n");
        }
        else{
           printf("no\n");
        }
    }
    
    return 0;
}
