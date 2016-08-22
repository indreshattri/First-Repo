#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,j,k,t,ctr,temp;
	char *a, *ba,c;
	float *bb,l;
	int s = 0;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		ctr=0;
		j=0;
		a = (char *)malloc(100 * sizeof(char));
		ba = (char *)malloc(100 * sizeof(char));
		bb = (float *)calloc(100 , sizeof(int));
		scanf("%s",a);	
		l=strlen(a);
		
		for(j=0;j<l;j++){
			if(j == 0){
				ba[ctr] = a[j];
				
				bb[ctr]= 1;
			
				ctr++;
			}
			else{
				temp = ctr;
				for(k=0;k<temp;k++){
					if(a[j] == ba[k]){
						bb[k] = bb[k] + 1;
						
						break;
					}
					if(k == ctr-1 && a[j]!=ba[k]){
						ba[ctr] = a[j];
						bb[ctr] = 1;		
						ctr++;
					}
				}
			}
		}
		
		for(j=0;j<ctr;j++) {   
			if(bb[j] == l - bb[j] ) {
				printf("YES\n");
				
				break;
			}
			
			if(j == ctr-1 && bb[j]!= l / 2) {
				printf("NO\n");
			}
		}
		free(a);
		free(ba);
		free(bb);
	}
	
	return 1;
}
