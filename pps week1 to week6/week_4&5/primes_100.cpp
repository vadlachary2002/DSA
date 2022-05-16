#include <stdio.h>  
int main(){  
    int factors=0,n=0,upto,i=1,j=1;  
    printf("enter upto :");
    scanf("%d",&upto);
    while(n<upto){  
        j=1;  
        factors=0;  
        while(j<=i){  
            if(i%j==0){
			factors++;  
			}
			j++;
        }  
        if(factors==2)  
        {  
            printf("%d,",i);  
            n++;  
        }  
        i++;  
	}
	return 0;  
}  
